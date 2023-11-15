/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#include <string>

#include <gtest/gtest.h>

#include "hyper/sensors/imu.hpp"
#include "hyper/utils.hpp"

namespace hyper::sensors::tests {

class IMUTests : public testing::Test {
 protected:
  // Constants.
  static constexpr auto kFilePath = __FILE__;
  static constexpr auto kInputFileName = "imu.