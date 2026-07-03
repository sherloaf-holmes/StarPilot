#include <sys/resource.h>
#include <unistd.h>

#include <csignal>
#include <cstring>
#include <ctime>

#include <execinfo.h>
#include <fcntl.h>
#include <ucontext.h>

#include <QApplication>
#include <QTranslator>

#include "common/swaglog.h"
#include "common/util.h"
#include "system/hardware/hw.h"
#include "selfdrive/ui/qt/qt_window.h"
#include "selfdrive/ui/qt/util.h"
#include "selfdrive/ui/qt/window.h"

// Signal-safe crash evidence. Every helper here must stay async-signal-safe:
// no malloc, no stdio, no Qt — raw open/read/write only.
namespace {

int open_crash_log() {
  int fd = open("/data/log/ui_crash.log", O_WRONLY | O_APPEND | O_CREAT | O_CLOEXEC, 0644);
  if (fd < 0) {
    fd = open("/tmp/ui_crash.log", O_WRONLY | O_APPEND | O_CREAT | O_CLOEXEC, 0644);
  }
  return fd;
}

void write_str(int fd, const char *s) {
  ssize_t ret = HANDLE_EINTR(write(fd, s, strlen(s)));
  (void)ret;
}

void write_buf(int fd, const char *buf, size_t len) {
  ssize_t ret = HANDLE_EINTR(write(fd, buf, len));
  (void)ret;
}

void write_num(int fd, unsigned long long value, unsigned base) {
  char buf[24];
  size_t i = sizeof(buf);
  do {
    buf[--i] = "0123456789abcdef"[value % base];
    value /= base;
  } while (value > 0 && i > 0);
  write_buf(fd, buf + i, sizeof(buf) - i);
}

void write_dec(int fd, long long value) {
  if (value < 0) {
    write_str(fd, "-");
    value = -value;
  }
  write_num(fd, static_cast<unsigned long long>(value), 10);
}

void write_hex(int fd, unsigned long long value) {
  write_str(fd, "0x");
  write_num(fd, value, 16);
}

long signal_safe_rss_mb() {
  int fd = open("/proc/self/status", O_RDONLY | O_CLOEXEC);
  if (fd < 0) return -1;
  char buf[4096];
  ssize_t n = HANDLE_EINTR(read(fd, buf, sizeof(buf) - 1));
  close(fd);
  if (n <= 0) return -1;
  buf[n] = '\0';
  const char *p = strstr(buf, "VmRSS:");
  if (p == nullptr) return -1;
  p += 6;
  while (*p == ' ' || *p == '\t') p++;
  long kb = 0;
  while (*p >= '0' && *p <= '9') {
    kb = kb * 10 + (*p - '0');
    p++;
  }
  return kb / 1024;
}

void write_file_contents(int fd, const char *path) {
  int src = open(path, O_RDONLY | O_CLOEXEC);
  if (src < 0) {
    write_str(fd, "<unavailable>\n");
    return;
  }
  char buf[4096];
  ssize_t n;
  while ((n = HANDLE_EINTR(read(src, buf, sizeof(buf)))) > 0) {
    write_buf(fd, buf, static_cast<size_t>(n));
  }
  close(src);
}

const char *signal_name(int sig) {
  switch (sig) {
    case SIGSEGV: return "SIGSEGV";
    case SIGABRT: return "SIGABRT";
    case SIGBUS: return "SIGBUS";
    case SIGFPE: return "SIGFPE";
    case SIGILL: return "SIGILL";
  }
  return "UNKNOWN";
}

void crash_handler(int sig, siginfo_t *info, void *uctx_raw) {
  int fd = open_crash_log();
  if (fd >= 0) {
    write_str(fd, "\n=== UI CRASH sig=");
    write_str(fd, signal_name(sig));
    write_str(fd, " epoch=");
    write_dec(fd, static_cast<long long>(time(nullptr)));
    write_str(fd, " pid=");
    write_dec(fd, getpid());
    write_str(fd, " addr=");
    write_hex(fd, info != nullptr ? reinterpret_cast<unsigned long long>(info->si_addr) : 0);
    write_str(fd, " rss_mb=");
    write_dec(fd, signal_safe_rss_mb());
    write_str(fd, " ===\n");

#if defined(__aarch64__)
    if (uctx_raw != nullptr) {
      const mcontext_t &mc = static_cast<const ucontext_t *>(uctx_raw)->uc_mcontext;
      write_str(fd, "pc=");
      write_hex(fd, mc.pc);
      write_str(fd, " lr=");
      write_hex(fd, mc.regs[30]);
      write_str(fd, " sp=");
      write_hex(fd, mc.sp);
      write_str(fd, " fp=");
      write_hex(fd, mc.regs[29]);
      write_str(fd, " fault=");
      write_hex(fd, mc.fault_address);
      write_str(fd, "\n");
    }
#else
    (void)uctx_raw;
#endif

    write_str(fd, "--- user backtrace ---\n");
    void *frames[64];
    int depth = backtrace(frames, 64);
    backtrace_symbols_fd(frames, depth, fd);

    write_str(fd, "--- kernel stack ---\n");
    write_file_contents(fd, "/proc/self/stack");
    close(fd);
  }
  // SA_RESETHAND already restored the default action; re-raise so the process
  // dies with the real signal status the manager expects.
  raise(sig);
}

void install_crash_handlers() {
  // backtrace() mallocs on first use (dlopens libgcc); prime it here so the
  // in-handler call stays signal-safe.
  void *frames[2];
  backtrace(frames, 2);

  struct sigaction sa = {};
  sa.sa_sigaction = crash_handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO | SA_RESETHAND;
  for (int sig : {SIGSEGV, SIGABRT, SIGBUS, SIGFPE, SIGILL}) {
    sigaction(sig, &sa, nullptr);
  }
}

// Durable record of Wayland exits. The LOGE right before _exit(0) goes over
// zmq and can be dropped before logmessaged reads it, so also append to the
// crash log directly.
void log_wayland_exit(const QByteArray &msg) {
  int fd = open_crash_log();
  if (fd < 0) return;
  write_str(fd, "\n=== UI WAYLAND EXIT epoch=");
  write_dec(fd, static_cast<long long>(time(nullptr)));
  write_str(fd, " rss_mb=");
  write_dec(fd, signal_safe_rss_mb());
  write_str(fd, " msg=");
  write_buf(fd, msg.constData(), static_cast<size_t>(msg.size()));
  write_str(fd, " ===\n");
  close(fd);
}

}  // namespace

// Qt 5.12.8's qErrnoWarning() emits QtCriticalMsg then calls abort() directly,
// bypassing the fatal-message path. Intercept critical+fatal Wayland messages
// before the unconditional abort() fires and clean-exit so the manager restarts
// us quickly instead of going through the slow abort/crash-handler path.
void waylandAwareMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
  if (type == QtCriticalMsg || type == QtFatalMsg) {
    QByteArray bytes = msg.toUtf8();
    if (bytes.contains("ayland") || bytes.contains("wl_display")) {
      swagLogMessageHandler(type, context, msg);
      LOGE("UI WAYLAND EXIT: %s", bytes.constData());
      log_wayland_exit(bytes);
      _exit(0);  // clean exit; manager restarts us
    }
  }
  swagLogMessageHandler(type, context, msg);
  // Non-Wayland fatal: let Qt abort normally; crash_handler will capture it.
}

int main(int argc, char *argv[]) {
  setpriority(PRIO_PROCESS, 0, -20);

  install_crash_handlers();
  qInstallMessageHandler(waylandAwareMessageHandler);
  initApp(argc, argv);

  QTranslator translator;
  QString translation_file = QString::fromStdString(Params().get("LanguageSetting"));
  if (!translator.load(QString(":/%1").arg(translation_file)) && translation_file.length()) {
    qCritical() << "Failed to load translation file:" << translation_file;
  }

  QApplication a(argc, argv);
  a.installTranslator(&translator);

  MainWindow w;
  setMainWindow(&w);
  a.installEventFilter(&w);

  // Pin the UI to the little cores (0-3) AFTER startup. The realtime control
  // loop (card/controlsd) runs SCHED_FIFO on core 4; this keeps the steady-state
  // UI off it so a UI stall can't preempt the control loop. Deliberately done
  // after MainWindow init so startup — and crucially restart recovery — can use
  // all cores; pinning before init starved the restarting UI on the contended
  // little cores and stretched recovery from ~30s to minutes. The per-second
  // reaffine in UIState::update keeps it pinned thereafter.
  if (!Hardware::PC()) {
    util::set_core_affinity({0, 1, 2, 3});
  }

  return a.exec();
}
