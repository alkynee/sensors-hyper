/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#include <glog/logging.h>

#include "hyper/sensors/sensor.hpp"
#include "hyper/variables/se3.hpp"

namespace hyper::sensors {

using namespace variables;

namespace {

// Variable names.
constexpr auto kRateName = "rate";
constexpr auto kOffsetName = "offset";
constexpr auto kTransformationName = "transformation";

// Default parameters.
constexpr auto kDefaultRate = -1;

}  // namespace

Sensor::Sensor(JacobianType jacobian_type) : Sensor{Type::ABSOLUTE, jacobian_type, kNumVariables} {}

Sensor::Sensor(const Node& node) : Sensor{} {
  node >> *this;
}

auto Sensor::type() const -> Type {
  return type_;
}

auto Sensor::jacobianType() const -> JacobianType {
  return jacobian_type_;
}

auto Sensor::setJacobianType(JacobianType jacobian_type) -> void {
  jacobian_type_ = jacobian_type;
  updateParameterBlockSizes();
}

auto Sensor::rate() const -> const Rate& {
  return rate_;
}

auto Sensor::rateIsVariable() const -> bool {
  return rate() < Scalar{0};
}

auto Sensor::parameterBlocks() const -> const ParameterBlocks& {
  return parameter_blocks_;
}

auto Sensor::parameterBlockSizes() const -> const ParameterBlockSizes& {
  return parameter_block_sizes_;
}

auto Sensor::offset() const -> const Offset& {
  return static_cast<const Offset&>(*variables_[kOffsetIndex]);  // NOLINT
}

auto Sensor::offset() -> Offset& {
  return const_cast<Offset&>(std::as_const(*this).offset());
}

auto Sensor::transformation() const -> const Transformation& {
  return static_cast<const Transformation&>(*variables_[kTransformationIndex]);  // NOLINT
}

auto Sensor::transformation() -> Transformation& {
  return const_cast<Transformation&>(std::as_const(*this).transformation());
}

auto Sensor::partitions(const Time& /* time */) const -> Partitions<Scalar*> {
  Partitions<Scalar*> partitions{kNumPartitions};
  partitions[kSensorPartitionIndex] = assembleVariablesPartition();
  return partitions;
}

auto operator>>(const YAML::Node& node, Sensor& sensor) -> const YAML::Node& {
  CHECK(node);
  sensor.read(node);
  return node;
}

auto operator<<(YAML::Emitter& emitter, const Sensor& sensor) -> YAML::Emitter& {
  emitter << YAML::BeginMap;
  sensor.write(emit