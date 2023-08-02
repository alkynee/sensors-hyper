/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#include <glog/logging.h>

#include "hyper/sensors/sensor.hpp"
#include "hyper/variables/se3.hpp"

namespace hyper::sensors {

using namespace variables;

namespace {

// Variable names.
constexpr auto kRateName = "