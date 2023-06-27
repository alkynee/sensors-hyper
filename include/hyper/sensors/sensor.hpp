/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#pragma once

#include "hyper/sensors/forward.hpp"

#include "hyper/variables/se3.hpp"
#include "hyper/yaml/yaml.hpp"

namespace hyper::sensors {

class Sensor {
 public:
  // Constants.
  static constexpr auto kSensorPartitionOffset = 0;
  static constexpr auto kSensorPartitionIndex = 0;
  static constexpr auto kNumPartitions = kSensorPartitionIndex + 1;

  static constexpr auto kOffsetIndex = 0;
  static constexpr auto kTransformationIn