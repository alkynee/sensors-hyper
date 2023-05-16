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
  using Base = Message<TScalar>;
  using Type = typename Base::Type;
  using Time = typename Base::Time;

  using Camera = sensors::Camera;

  using Image = cv_bridge::CvImageConstPtr;
  using Track = std::tuple<Image, std::vector<cv::Point2f>>;
  using Tracks = std::map<const Camera*, Track>;

  using IDs = std::vector<typename Base::ID>;
  using Lengths = std::vector<typename Base::Size>;
  using Positions = std::vector<variables::Position<TScalar>>;

  /// Constructor from time and sensor.
  /// \param time Time.
  /// \param camera Camera.
  VisualTracks(const Time& time, const Camera* camera)
      : VisualTracks{Base::Type::VISUAL_TRACKS, time, camera} {}

  /// Sensor accessor.
  /// \return Sensor.
  [[nodiscard]] inline auto sensor() const -> const Camera* final {
    return camera_;
  }

  /// Sets the associated sensor.
  /// \param camera Sensor to set.
  inline auto setSensor(const Camera* camera) -> v