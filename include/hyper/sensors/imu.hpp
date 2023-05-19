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

  static constexpr auto kGyroscopeIntrinsicsIndex = Sensor::kNumVariables;
  static constexpr auto kGyroscopeSensitivityIndex = kGyroscopeIntrinsicsIndex + 1;
  static constexpr auto kAccelerometerIntrinsicsIndex = kGyroscopeSensitivityIndex + 1;
  static constexpr auto kAccelerometerOffsetIndex = kAccelerometerIntrinsicsIndex + 1;
  static constexpr auto kNumVariables = kAccelerometerOffsetIndex + 1;

  // Definitions.
  using GyroscopeNoiseDensity = Scalar;
  using GyroscopeIntrinsics = variables::OrthonormalityAlignment<Scalar, 3>;
  using GyroscopeSensitivity = variables::Sensitivity<Scalar, 3>;
  using GyroscopeBias = state::ContinuousState<variables::Rn<Scalar, 3>>;

  using AccelerometerNoiseDensity = Scalar;
  using AccelerometerIntrinsics = variables::OrthonormalityAlignment<Scalar, 3>;
  using AccelerometerOffset = variables::Rn<Scalar, 9>;
  using AccelerometerBias = state::ContinuousState<variables::Rn<Scalar, 3>>;

  using BiasInterpolator = state::TemporalInterpolator<Scalar>;
  using DefaultBiasInterpolator = state::BasisInterpolator<Scalar, 4>;

  /// Constructor from Jacobian type and bias interpolators.
  /// \param jacobian_type Jacobian type.
  /// \param gyroscope_bias_interpolator Interpolator.
  /// \param accelerometer_bias_interpolator Interpolator.
  explicit IMU(JacobianType jacobian_type = kDefaultJacobianType, std::unique_ptr<BiasInterpolator>&& gyroscope_bias_interpolator = std::make_unique<DefaultBiasInterpolator>(),
               std::unique_ptr<BiasInterpolator>&& accelerometer_bias_interpolator = std::make_unique<DefaultBiasInterpolator>());

  /// Constructor from YAML node.
  /// \param node YAML node.
  explicit IMU(const Node& node);

  /// \brief Gyroscope noise density accessor.
  /// \return Gyroscope noise density.
  [[nodiscard]] auto gyroscopeNoiseDensity() const -> const GyroscopeNoiseDensity&;

  /// \brief Gyro