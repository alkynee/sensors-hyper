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
  static constexpr auto kTransformationIndex = kOffsetIndex + 1;
  static constexpr auto kNumVariables = kTransformationIndex + 1;

  static constexpr auto kDefaultJacobianType = JacobianType::TANGENT_TO_MANIFOLD;

  // Definitions.
  using Node = YAML::Node;
  using Emitter = YAML::Emitter;

  using Time = double;
  using Scalar = double;
  using ParameterBlocks = std::vector<Scalar*>;
  using ParameterBlockSizes = std::vector<int>;

  using Rate = Scalar;
  using Offset = variables::R1<Scalar>;
  using Transformation = variables::SE3<Scalar>;

  /// Constructor from Jacobian type.
  /// \param jacobian_type Jacobian type.
  explicit Sensor(JacobianType jacobian_type = kDefaultJacobianType);

  /// Constructor from YAML node.
  /// \param node YAML node.
  explicit Sensor(const Node& node);

  /// Default destructor.
  virtual ~Sensor() = default;

  /// Downcast this instance.
  /// \tparam TDerived_ Target type.
  /// \return Reference to cast instance.
  template <typename