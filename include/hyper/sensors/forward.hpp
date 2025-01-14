
/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#pragma once

namespace hyper::sensors {

enum class Type { ABSOLUTE, CAMERA, IMU };

enum class JacobianType { TANGENT_TO_TANGENT, TANGENT_TO_MANIFOLD };

class Sensor;

class Camera;

class IMU;

using Absolute = Sensor;

using GPS = Sensor;

}  // namespace hyper::sensors