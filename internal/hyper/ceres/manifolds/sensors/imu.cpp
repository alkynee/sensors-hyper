
/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#ifdef HYPER_COMPILE_WITH_CERES

#include "hyper/ceres/manifolds/sensors/imu.hpp"
#include "hyper/ceres/manifolds/variables/euclidean.hpp"
#include "hyper/ceres/manifolds/variables/stamped.hpp"
#include "hyper/state/continuous.hpp"

namespace hyper::ceres::manifolds {

using namespace sensors;