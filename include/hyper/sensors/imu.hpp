/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#pragma once

#include "hyper/sensors/sensor.hpp"
#include "hyper/state/continuous.hpp"
#include "hyper/variables/orthonormality_alignment.hpp"
#include "hyper/variables/sensitivity.hpp"

namespace hyper::sensors {

class IMU final : public Sensor {
 public:
  // Constants.
  static constexpr auto kGyroscopeBiasPartitionIndex = Sensor::kNumPartitions;
  static constexpr auto kAccelerometerBiasPartitionIndex = kGyroscopeBiasPartitionIndex + 1;
  static constexpr auto kNumPartitions = kAccelerometerBiasPartitionIndex + 1;

  static conste