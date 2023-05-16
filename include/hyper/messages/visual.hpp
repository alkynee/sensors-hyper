/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#pragma once

#include <cv_bridge/cv_bridge.h>
#include <glog/logging.h>

#include "hyper/messages/message.hpp"
#include "hyper/sensors/camera.hpp"
#include "hyper/variables/rn.hpp"

namespace hyper::messages {

template <typename TScalar>
class VisualTracks : public Message<TScalar> {
 public:
  // Definitions.
  usi