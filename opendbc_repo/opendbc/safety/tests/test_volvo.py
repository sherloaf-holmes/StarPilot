#!/usr/bin/env python3
"""
Tests for the Volvo CMA/SPA (Polestar 2) safety mode.

The Volvo mode intentionally only enforces bus routing on TX (see
opendbc/safety/modes/volvo.h): openpilot re-emits all LCA-family messages
(passthrough copies when disengaged) and panda blocks the stock originals via
check_relay. These tests pin down that contract; the engagement-gated TX
checks from CarSafetyTest don't apply to this mode yet.
"""
import unittest

import opendbc.safety.tests.common as common
from opendbc.safety.tests.libsafety import libsafety_py
from opendbc.safety.tests.common import make_msg

SAFETY_VOLVO = 36
VOLVO_FLAG_SPA = 1

MAIN_BUS = 0
PT_BUS = 1
PARTY_BUS = 2

LCA_STEER = 0x58
PSCM = 0x16
PSCM_RELATED = 0x17
LCA_2 = 0x69
LCA_3 = 0x57
LCA_4 = 0x90
LCA_5 = 0x67
LCA_6 = 0x97
LCA_7 = 0x92

CMA_CRUISE_ADDR = 0x340
SPA_CRUISE_ADDR = 0x349
CMA_ECM_1_ADDR = 0x250
SPA_ECM_1_ADDR = 0x25
CMA_SPEED_ADDR = 0x70
SPA_SPEED_ADDR = 0x75


class TestVolvoSafetyBase(common.SafetyTest):
  TX_MSGS = [[LCA_STEER, PARTY_BUS], [PSCM, MAIN_BUS], [LCA_3, PARTY_BUS], [LCA_2, PARTY_BUS],
             [LCA_4, PARTY_BUS], [LCA_5, PARTY_BUS], [LCA_6, PARTY_BUS], [LCA_7, PARTY_BUS],
             [PSCM_RELATED, MAIN_BUS]]
  FWD_BUS_LOOKUP = {0: 2, 2: 0}
  # check_relay=true TX msgs are blocked from static forwarding toward their TX bus
  FWD_BLACKLISTED_ADDRS = {
    MAIN_BUS: [LCA_STEER, LCA_3, LCA_2, LCA_4, LCA_5, LCA_6, LCA_7],  # stock LCA family, main -> party blocked
    PARTY_BUS: [PSCM, PSCM_RELATED],                                  # PSCM messages, party -> main blocked
  }
  # RX of a check_relay TX msg on its TX (destination) bus latches relay malfunction
  RELAY_MALFUNCTION_ADDRS = {
    PARTY_BUS: (LCA_STEER, LCA_3, LCA_2, LCA_4, LCA_5, LCA_6, LCA_7),
    MAIN_BUS: (PSCM, PSCM_RELATED),
  }

  SAFETY_PARAM: int

  @classmethod
  def setUpClass(cls):
    if cls == TestVolvoSafetyBase:
      cls.safety = None
      raise unittest.SkipTest("base class")

  def setUp(self):
    self.safety = libsafety_py.libsafety
    self.safety.set_safety_hooks(SAFETY_VOLVO, self.SAFETY_PARAM)
    self.safety.init_tests()

  def test_tx_allowed_regardless_of_controls_allowed(self):
    # Passthrough relay messages must flow even when openpilot is disengaged,
    # otherwise stock LCA / PSCM traffic would be lost (stock originals are
    # blocked by check_relay).
    for controls_allowed in (False, True):
      self.safety.set_controls_allowed(controls_allowed)
      for addr, bus in self.TX_MSGS:
        self.assertTrue(self._tx(make_msg(bus, addr, 8)),
                        f"addr={addr:#x} controls_allowed={controls_allowed}")

  def test_brake_rx(self):
    # LCA_2 (0x69) on main bus, BRAKE_PEDAL_PRESSED_B is data[5] bit 6
    self.assertFalse(self.safety.get_brake_pressed_prev())
    dat = bytearray(8)
    dat[5] = 0x40
    self._rx(make_msg(MAIN_BUS, LCA_2, dat=bytes(dat)))
    self.assertTrue(self.safety.get_brake_pressed_prev())
    self._rx(make_msg(MAIN_BUS, LCA_2, 8))
    self.assertFalse(self.safety.get_brake_pressed_prev())


class TestVolvoCmaSafety(TestVolvoSafetyBase):
  SAFETY_PARAM = 0

  def test_cruise_engage_disengage(self):
    self.assertFalse(self.safety.get_controls_allowed())
    # CMA: CRUISE_CONTROL_ENABLED is data[7] bit 0
    dat = bytearray(8)
    dat[7] = 0x01
    self._rx(make_msg(PT_BUS, CMA_CRUISE_ADDR, dat=bytes(dat)))
    self.assertTrue(self.safety.get_controls_allowed())
    self._rx(make_msg(PT_BUS, CMA_CRUISE_ADDR, 8))
    self.assertFalse(self.safety.get_controls_allowed())

  def test_gas_rx(self):
    # CMA: ACCELERATOR_PEDAL_POS is data[3], 20 baseline + 1 tolerance
    self.assertFalse(self.safety.get_gas_pressed_prev())
    dat = bytearray(8)
    dat[3] = 40
    self._rx(make_msg(PT_BUS, CMA_ECM_1_ADDR, dat=bytes(dat)))
    self.assertTrue(self.safety.get_gas_pressed_prev())
    dat[3] = 20
    self._rx(make_msg(PT_BUS, CMA_ECM_1_ADDR, dat=bytes(dat)))
    self.assertFalse(self.safety.get_gas_pressed_prev())

  def test_vehicle_moving(self):
    # CMA: BUS1_SPEED is (data[2] << 8) | data[3], scale 0.01886 m/s
    self.assertFalse(self.safety.get_vehicle_moving())
    dat = bytearray(8)
    dat[2] = 0x01  # 256 * 0.01886 = 4.8 m/s
    self._rx(make_msg(PT_BUS, CMA_SPEED_ADDR, dat=bytes(dat)))
    self.assertTrue(self.safety.get_vehicle_moving())
    self._rx(make_msg(PT_BUS, CMA_SPEED_ADDR, 8))
    self.assertFalse(self.safety.get_vehicle_moving())


class TestVolvoSpaSafety(TestVolvoSafetyBase):
  SAFETY_PARAM = VOLVO_FLAG_SPA

  def test_cruise_engage_disengage(self):
    self.assertFalse(self.safety.get_controls_allowed())
    # SPA: CRUISE_CONTROL_SPA_ENABLED is data[0] bit 1, active low (0 = cruise on)
    dat = bytearray(8)
    dat[0] = 0x02  # bit set -> cruise off
    self._rx(make_msg(PT_BUS, SPA_CRUISE_ADDR, dat=bytes(dat)))
    self.assertFalse(self.safety.get_controls_allowed())
    self._rx(make_msg(PT_BUS, SPA_CRUISE_ADDR, 8))  # bit clear -> cruise on
    self.assertTrue(self.safety.get_controls_allowed())
    dat[0] = 0x02
    self._rx(make_msg(PT_BUS, SPA_CRUISE_ADDR, dat=bytes(dat)))
    self.assertFalse(self.safety.get_controls_allowed())

  def test_gas_rx(self):
    # SPA: gas is ((data[0] & 0x7f) << 8) | data[1], scale 0.00390625 %, threshold > 1%
    self.assertFalse(self.safety.get_gas_pressed_prev())
    dat = bytearray(8)
    dat[0] = 0x02  # 512 * 0.00390625 = 2%
    self._rx(make_msg(PT_BUS, SPA_ECM_1_ADDR, dat=bytes(dat)))
    self.assertTrue(self.safety.get_gas_pressed_prev())
    self._rx(make_msg(PT_BUS, SPA_ECM_1_ADDR, 8))
    self.assertFalse(self.safety.get_gas_pressed_prev())

  def test_vehicle_moving(self):
    # SPA: BUS1_SPEED is ((data[0] & 0x7f) << 8) | data[1], scale 0.0044704 m/s
    self.assertFalse(self.safety.get_vehicle_moving())
    dat = bytearray(8)
    dat[0] = 0x01  # 256 * 0.0044704 = 1.14 m/s
    self._rx(make_msg(PT_BUS, SPA_SPEED_ADDR, dat=bytes(dat)))
    self.assertTrue(self.safety.get_vehicle_moving())
    self._rx(make_msg(PT_BUS, SPA_SPEED_ADDR, 8))
    self.assertFalse(self.safety.get_vehicle_moving())


if __name__ == "__main__":
  unittest.main()
