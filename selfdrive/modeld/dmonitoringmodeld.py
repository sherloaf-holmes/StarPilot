#!/usr/bin/env python3
import os
import pickle
import time
from pathlib import Path

import numpy as np

from openpilot.system.hardware import TICI

os.environ["DEV"] = "QCOM" if TICI else "CPU"

from tinygrad.tensor import Tensor

from cereal import messaging
from cereal.messaging import PubMaster, SubMaster
from msgq.visionipc import VisionBuf, VisionIpcClient, VisionStreamType
from openpilot.common.file_chunker import read_file_chunked
from openpilot.common.realtime import config_realtime_process
from openpilot.common.swaglog import cloudlog
from openpilot.common.transformations.camera import _ar_ox_fisheye, _os_fisheye
from openpilot.common.transformations.model import dmonitoringmodel_intrinsics
from openpilot.selfdrive.modeld.helpers import get_tg_input_devices
from openpilot.selfdrive.modeld.parse_model_outputs import safe_exp, sigmoid
from openpilot.system.camerad.cameras.nv12_info import get_nv12_info

PROCESS_NAME = "selfdrive.modeld.dmonitoringmodeld"
SEND_RAW_PRED = os.getenv("SEND_RAW_PRED")
MODELS_DIR = Path(__file__).parent / "models"
MODEL_PKL_PATH = MODELS_DIR / "dmonitoring_model_tinygrad.pkl"
METADATA_PATH = MODELS_DIR / "dmonitoring_model_metadata.pkl"


class ModelState:
  def __init__(self, cam_w: int, cam_h: int):
    self.device = get_tg_input_devices(PROCESS_NAME, usbgpu=False)["DEV"]
    with open(METADATA_PATH, "rb") as metadata_file:
      metadata = pickle.load(metadata_file)
    self.input_shapes = metadata["input_shapes"]
    self.output_slices = metadata["output_slices"]

    self.numpy_inputs = {"calib": np.zeros(self.input_shapes["calib"], dtype=np.float32)}
    self.tensor_inputs = {
      key: Tensor(value, device="NPY").realize()
      for key, value in self.numpy_inputs.items()
    }
    self.warp_numpy_inputs = {"transform": np.zeros((3, 3), dtype=np.float32)}
    self.warp_inputs = {
      key: Tensor(value, device="NPY").realize()
      for key, value in self.warp_numpy_inputs.items()
    }
    self.frame_size = get_nv12_info(cam_w, cam_h)[3]
    self._blob_cache: dict[int, Tensor] = {}
    self.model_run = pickle.loads(read_file_chunked(str(MODEL_PKL_PATH)))
    with open(MODELS_DIR / f"dm_warp_{cam_w}x{cam_h}_tinygrad.pkl", "rb") as warp_file:
      self.image_warp = pickle.load(warp_file)

  def run(self, buf: VisionBuf, calib: np.ndarray, transform: np.ndarray) -> tuple[np.ndarray, float]:
    self.numpy_inputs["calib"][0, :] = calib
    start = time.perf_counter()

    ptr = np.frombuffer(buf.data, dtype=np.uint8).ctypes.data
    if ptr not in self._blob_cache:
      self._blob_cache[ptr] = Tensor.from_blob(
        ptr, (self.frame_size,), dtype="uint8", device=self.device,
      )

    self.warp_numpy_inputs["transform"][:] = transform
    self.tensor_inputs["input_img"] = self.image_warp(
      self._blob_cache[ptr], self.warp_inputs["transform"],
    )
    output = self.model_run(**self.tensor_inputs).numpy().flatten()
    return output, time.perf_counter() - start


# --- TEMP: native GPU-alloc leak probe (gated on DM_GPU_PROBE), remove after diagnosis ---
class _GpuProbe:
  def __init__(self, device_str: str):
    self.device_str = device_str
    self.c = {"alloc_n": 0, "alloc_b": 0, "map_n": 0, "map_b": 0, "free_n": 0, "free_b": 0}
    from tinygrad.runtime.ops_qcom import QCOMDevice
    self._orig_alloc = QCOMDevice._gpu_alloc
    self._orig_map = QCOMDevice._gpu_map
    self._orig_free = QCOMDevice._gpu_free
    probe = self

    def wrap_alloc(dev, size, *a, **k):
      buf = probe._orig_alloc(dev, size, *a, **k)
      probe.c["alloc_n"] += 1; probe.c["alloc_b"] += buf.size
      return buf
    def wrap_map(dev, ptr, size, *a, **k):
      buf = probe._orig_map(dev, ptr, size, *a, **k)
      probe.c["map_n"] += 1; probe.c["map_b"] += size
      return buf
    def wrap_free(dev, mem, *a, **k):
      probe.c["free_n"] += 1; probe.c["free_b"] += mem.size
      return probe._orig_free(dev, mem, *a, **k)
    QCOMDevice._gpu_alloc = wrap_alloc
    QCOMDevice._gpu_map = wrap_map
    QCOMDevice._gpu_free = wrap_free

  def _rss_kb(self) -> int:
    with open("/proc/self/statm") as f:
      return int(f.read().split()[1]) * (os.sysconf("SC_PAGE_SIZE") // 1024)

  def _lru_depth(self) -> int:
    try:
      from tinygrad.device import Device
      cache = Device[self.device_str].allocator.cache
      return sum(len(v) for v in cache.values())
    except Exception:
      return -1

  def log(self, frame_id: int):
    c = self.c
    net_n = c["alloc_n"] + c["map_n"] - c["free_n"]
    net_b = c["alloc_b"] + c["map_b"] - c["free_b"]
    line = (f"DMPROBE fid={frame_id} rss={self._rss_kb()}kB lru={self._lru_depth()} "
            f"alloc={c['alloc_n']}/{c['alloc_b']//1024}kB map={c['map_n']}/{c['map_b']//1024}kB "
            f"free={c['free_n']}/{c['free_b']//1024}kB net={net_n}buf/{net_b//1024}kB\n")
    with open("/data/dm_gpu_probe.log", "a") as f:
      f.write(line)
# --- end TEMP probe ---


def slice_outputs(model_outputs, output_slices):
  return {key: model_outputs[np.newaxis, value] for key, value in output_slices.items()}


def parse_model_output(model_output):
  parsed = {"wheel_on_right": sigmoid(model_output["wheel_on_right"])}
  for suffix in ("lhd", "rhd"):
    face_descs = model_output[f"face_descs_{suffix}"]
    parsed[f"face_descs_{suffix}"] = face_descs[:, :-6]
    parsed[f"face_descs_{suffix}_std"] = safe_exp(face_descs[:, -6:])
    for key in (
      "face_prob",
      "left_eye_prob",
      "right_eye_prob",
      "left_blink_prob",
      "right_blink_prob",
      "sunglasses_prob",
      "using_phone_prob",
    ):
      parsed[f"{key}_{suffix}"] = sigmoid(model_output[f"{key}_{suffix}"])
    sleep_key = f"sleep_prob_{suffix}"
    parsed[sleep_key] = (
      sigmoid(model_output[sleep_key])
      if sleep_key in model_output
      else np.zeros((1, 1), dtype=np.float32)
    )
  return parsed


def fill_driver_data(msg, model_output, suffix):
  msg.faceOrientation = model_output[f"face_descs_{suffix}"][0, :3].tolist()
  msg.faceOrientationStd = model_output[f"face_descs_{suffix}_std"][0, :3].tolist()
  msg.facePosition = model_output[f"face_descs_{suffix}"][0, 3:5].tolist()
  msg.facePositionStd = model_output[f"face_descs_{suffix}_std"][0, 3:5].tolist()
  msg.faceProb = model_output[f"face_prob_{suffix}"][0, 0].item()
  msg.leftEyeProb = model_output[f"left_eye_prob_{suffix}"][0, 0].item()
  msg.rightEyeProb = model_output[f"right_eye_prob_{suffix}"][0, 0].item()
  msg.leftBlinkProb = model_output[f"left_blink_prob_{suffix}"][0, 0].item()
  msg.rightBlinkProb = model_output[f"right_blink_prob_{suffix}"][0, 0].item()
  msg.sunglassesProb = model_output[f"sunglasses_prob_{suffix}"][0, 0].item()
  msg.phoneProb = model_output[f"using_phone_prob_{suffix}"][0, 0].item()
  try:
    msg.sleepProb = model_output[f"sleep_prob_{suffix}"][0, 0].item()
  except AttributeError:
    pass


def get_driverstate_packet(model_output, frame_id: int, exec_time: float, gpu_exec_time: float):
  msg = messaging.new_message("driverStateV2", valid=True)
  state = msg.driverStateV2
  state.frameId = frame_id
  state.modelExecutionTime = exec_time
  state.gpuExecutionTime = gpu_exec_time
  state.rawPredictions = model_output["raw_pred"]
  state.wheelOnRightProb = model_output["wheel_on_right"][0, 0].item()
  fill_driver_data(state.leftDriverData, model_output, "lhd")
  fill_driver_data(state.rightDriverData, model_output, "rhd")
  return msg


def main():
  config_realtime_process(7, 5)
  cloudlog.warning("connecting to driver stream")
  vipc_client = VisionIpcClient("camerad", VisionStreamType.VISION_STREAM_DRIVER, True)
  while not vipc_client.connect(False):
    time.sleep(0.1)
  assert vipc_client.is_connected()
  cloudlog.warning(f"connected with buffer size: {vipc_client.buffer_len}")

  model = ModelState(vipc_client.width, vipc_client.height)
  cloudlog.warning("models loaded, dmonitoringmodeld starting")

  probe = _GpuProbe(model.device) if os.getenv("DM_GPU_PROBE") else None

  sm = SubMaster(["liveCalibration"])
  pm = PubMaster(["driverStateV2"])
  calib = np.zeros(model.numpy_inputs["calib"].size, dtype=np.float32)
  model_transform = None

  while True:
    buf = vipc_client.recv()
    if buf is None:
      continue
    if model_transform is None:
      camera = _os_fisheye if buf.width == _os_fisheye.width else _ar_ox_fisheye
      model_transform = np.linalg.inv(
        np.dot(dmonitoringmodel_intrinsics, np.linalg.inv(camera.intrinsics)),
      ).astype(np.float32)

    sm.update(0)
    if sm.updated["liveCalibration"]:
      calib[:] = np.array(sm["liveCalibration"].rpyCalib)

    start = time.perf_counter()
    model_output, gpu_execution_time = model.run(buf, calib, model_transform)
    execution_time = time.perf_counter() - start
    raw_pred = model_output.tobytes() if SEND_RAW_PRED else b""
    parsed = parse_model_output(slice_outputs(model_output, model.output_slices))
    parsed["raw_pred"] = raw_pred
    pm.send(
      "driverStateV2",
      get_driverstate_packet(parsed, vipc_client.frame_id, execution_time, gpu_execution_time),
    )

    if probe is not None and vipc_client.frame_id % 300 == 0:
      probe.log(vipc_client.frame_id)


if __name__ == "__main__":
  try:
    main()
  except KeyboardInterrupt:
    cloudlog.warning("got SIGINT")
