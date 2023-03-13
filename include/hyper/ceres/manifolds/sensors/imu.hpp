/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#pragma once

#ifdef HYPER_COMPILE_WITH_CERES

#include "hyper/ceres/manifolds/sensors/sensor.hpp"
#include "hyper/sensors/imu.hpp"

namespace hyper::ceres::manifolds {

template <>
class Manifold<sensors::IMU> final : public Manifold<sensors::Sensor> {
 public:
  // Definitions.
  using IMU = sensors::IMU;

  // Constants.
  static constexpr auto kGyroscopeBiasSubmanifoldIndex = IMU::kNumVariables;
  static constexpr auto kAccelerometerBiasSubmanifoldIndex = kGyroscopeBiasSubmanifoldIndex + 1;
  static constexpr auto kNumSubmanifolds = kAccelerometerBiasSubmanifoldIndex + 1;
