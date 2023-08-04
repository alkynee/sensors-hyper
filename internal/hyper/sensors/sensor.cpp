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

auto Sensor::offset() const -> co