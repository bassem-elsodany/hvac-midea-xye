// Host-side unit tests for XYEAdapter::get_climate_fan_mode() and
// get_fan_speed_level() — the C0 fan_mode byte decode paths.
//
// These run on the CI host, not the ESP target. xye_adapter.cpp is compiled
// against the minimal stub headers under tests/native/stubs/ that provide just
// the esphome climate enums and logging macros it needs.
//
// Build & run (from the repository root, output kept out of the tree):
//   g++ -std=c++17 -DUSE_ARDUINO
//       -Itests/native/stubs -Iesphome/components/midea_xye
//       tests/native/test_get_climate_fan_mode.cpp
//       esphome/components/midea_xye/xye_adapter.cpp -o /tmp/xye_fan_tests
//   /tmp/xye_fan_tests

#include <cstdint>
#include <cstdio>

#include "xye_adapter.h"

// xye_adapter.cpp references Temperature::to_celsius via get_temperature(), a
// function these tests do not exercise. A stub definition satisfies the linker.
namespace esphome {
namespace midea {
namespace xye {
float Temperature::to_celsius() const { return 0.0f; }
}  // namespace xye
}  // namespace midea
}  // namespace esphome

namespace {

using esphome::climate::ClimateFanMode;
using esphome::midea::xye::FanMode;
using esphome::midea::xye::FanSpeedLevel;
using esphome::midea::xye::XYEAdapter;

int g_failures = 0;
int g_checks = 0;

const char *fan_name(ClimateFanMode f) {
  switch (f) {
    case esphome::climate::CLIMATE_FAN_AUTO: return "AUTO";
    case esphome::climate::CLIMATE_FAN_LOW: return "LOW";
    case esphome::climate::CLIMATE_FAN_MEDIUM: return "MEDIUM";
    case esphome::climate::CLIMATE_FAN_HIGH: return "HIGH";
    case esphome::climate::CLIMATE_FAN_OFF: return "OFF";
    default: return "?";
  }
}

void expect_fan(const char *desc, uint8_t raw, ClimateFanMode expected) {
  g_checks++;
  const ClimateFanMode got = XYEAdapter::get_climate_fan_mode(static_cast<FanMode>(raw));
  if (got != expected) {
    g_failures++;
    std::printf("FAIL: %s -- expected %s, got %s\n", desc, fan_name(expected), fan_name(got));
  } else {
    std::printf("ok:   %s\n", desc);
  }
}

void expect_level(const char *desc, uint8_t raw, FanSpeedLevel expected) {
  g_checks++;
  const FanSpeedLevel got = XYEAdapter::get_fan_speed_level(static_cast<FanMode>(raw));
  if (got != expected) {
    g_failures++;
    std::printf("FAIL: %s -- expected level %d, got %d\n", desc, static_cast<int>(expected),
                static_cast<int>(got));
  } else {
    std::printf("ok:   %s\n", desc);
  }
}

}  // namespace

int main() {
  std::printf("-- get_climate_fan_mode (AUTO flag, bit 7) --\n");
  // FAN_AUTO_FLAG (0x80) takes precedence over the speed nibble.
  expect_fan("0x80 -> AUTO (auto, idle nibble)", 0x80, esphome::climate::CLIMATE_FAN_AUTO);
  expect_fan("0x84 -> AUTO (auto + low nibble, live)", 0x84, esphome::climate::CLIMATE_FAN_AUTO);
  expect_fan("0x82 -> AUTO (auto + medium nibble)", 0x82, esphome::climate::CLIMATE_FAN_AUTO);

  std::printf("\n-- get_climate_fan_mode (explicit speed nibble) --\n");
  expect_fan("0x01 -> HIGH", 0x01, esphome::climate::CLIMATE_FAN_HIGH);
  expect_fan("0x02 -> MEDIUM", 0x02, esphome::climate::CLIMATE_FAN_MEDIUM);
  expect_fan("0x04 -> LOW (this unit)", 0x04, esphome::climate::CLIMATE_FAN_LOW);
  // Regression: 0x03 (FAN_LOW_ALT) must decode as LOW, not fall through to AUTO.
  expect_fan("0x03 -> LOW (alternate encoding)", 0x03, esphome::climate::CLIMATE_FAN_LOW);
  expect_fan("0x00 -> OFF (fan stopped)", 0x00, esphome::climate::CLIMATE_FAN_OFF);

  std::printf("\n-- get_fan_speed_level (ordinal scale) --\n");
  expect_level("0x01 -> SPEED_HIGH", 0x01, FanSpeedLevel::SPEED_HIGH);
  expect_level("0x02 -> SPEED_MEDIUM", 0x02, FanSpeedLevel::SPEED_MEDIUM);
  expect_level("0x03 -> SPEED_LOW (alternate)", 0x03, FanSpeedLevel::SPEED_LOW);
  expect_level("0x04 -> SPEED_LOW", 0x04, FanSpeedLevel::SPEED_LOW);
  expect_level("0x00 -> SPEED_OFF", 0x00, FanSpeedLevel::SPEED_OFF);

  std::printf("\n%d checks, %d failure(s)\n", g_checks, g_failures);
  return g_failures == 0 ? 0 : 1;
}
