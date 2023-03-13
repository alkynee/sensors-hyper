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

  /// Default constructor.
  /// \param imu IMU to parametrize.
  /// \param constant Constancy flag.
  explicit Manifold(IMU* imu, bool constant = true);

  /// Sensor accessor.
  /// \return Sensor.
  [[nodiscard]] auto sensor() const -> const IMU* final;

  /// Gyroscope intrinsics submanifold accessor.
  [[nodiscard]] auto gyroscopeIntrinsicsSubmanifold() const -> Submanifold*;

  /// Sets the gyroscope intrinsics submanifold.
  /// \param submanifold Input submanifold.
  auto setGyroscopeIntrinsicsSubmanifold(std::unique_ptr<Submanifold>&& submanifold) -> void;

  /// Sets the sensor's gyroscope intrinsics constant or variable.
  /// \param constant Constancy flag.
  auto setGyroscopeIntrinsicsConstant(bool constant) -> void;

  /// Gyroscope sensitivity submanifold accessor.
  [[nodiscard]] auto gyroscopeSensitivitySubmanifold() const -> Submanifold*;

  /// Sets the gyroscope sensitivity submanifold.
  /// \param su