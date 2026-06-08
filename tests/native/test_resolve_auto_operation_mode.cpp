// Host-side unit tests for XYEAdapter::resolve_auto_operation_mode().

#include <cstdio>

#include "xye_adapter.h"

namespace esphome {
namespace midea {
namespace xye {
float Temperature::to_celsius() const { return 0.0f; }
}  // namespace xye
}  // namespace midea
}  // namespace esphome

namespace {

using esphome::midea::xye::OperationMode;
using esphome::midea::xye::XYEAdapter;

int g_failures = 0;
int g_checks = 0;

void expect_op(const char *desc, float current, float target, OperationMode last, OperationMode expected) {
  g_checks++;
  const OperationMode got = XYEAdapter::resolve_auto_operation_mode(current, target, last);
  if (got != expected) {
    g_failures++;
    std::printf("FAIL: %s -- expected %d, got %d\n", desc, static_cast<int>(expected), static_cast<int>(got));
  } else {
    std::printf("ok:   %s\n", desc);
  }
}

}  // namespace

int main() {
  const auto HEAT = OperationMode::HEAT;
  const auto COOL = OperationMode::COOL;
  const auto OFF = OperationMode::OFF;

  std::printf("-- resolve_auto_operation_mode --\n");
  expect_op("above setpoint -> COOL", 26.0f, 24.0f, HEAT, COOL);
  expect_op("below setpoint -> HEAT", 22.0f, 24.0f, COOL, HEAT);
  expect_op("in deadband keeps HEAT", 24.2f, 24.0f, HEAT, HEAT);
  expect_op("in deadband keeps COOL", 23.8f, 24.0f, COOL, COOL);
  expect_op("at setpoint no history, equal -> COOL", 24.0f, 24.0f, OFF, COOL);
  expect_op("just above setpoint no history -> COOL", 24.1f, 24.0f, OFF, COOL);
  expect_op("just below setpoint no history -> HEAT", 23.9f, 24.0f, OFF, HEAT);

  std::printf("\n%d checks, %d failure(s)\n", g_checks, g_failures);
  return g_failures == 0 ? 0 : 1;
}
