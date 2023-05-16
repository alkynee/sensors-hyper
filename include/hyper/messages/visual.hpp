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
  inline auto setSensor(const Camera* camera) -> void { camera_ = camera; }

  /// Adds a new track.
  /// \param camera Associated camera.
  inline auto addTrack(const Camera* camera) -> Track& {
    const auto [itr, inserted] = tracks_.try_emplace(camera);
    DCHECK(inserted) << "Track already exists.";
    return itr->second;
  }

  /// Track accessor.
  /// \param camera Associated camera.
  /// \return Track containing the associated image and tracked points.
  [[nodiscard]] inline auto track(const Camera* camera) const -> const Track& {
    const auto itr = tracks_.find(camera);
    DCHECK(itr != tracks_.cend()) << "Track does not exist.";
    return itr->second;
  }

  /// Track modifier.
  /// \param camera Associated camera.
  /// \return Track containing the associated image and tracked points.
  inline auto track(const Camera* camera) -> Track& {
    return const_cast<Track&>(std::as_const(*this).track(camera));
  }

  /// Tracks accessor.
  /// \return Tracks.
  inline auto tracks() const -> const Tracks& { return tracks_; }

  IDs ids;              ///< Track IDs.
  Lengths lengths;      ///< Track lengths.
  Positions positions;  ///< Track positions (optional).

 protected:
  /// Constructor from message type, time and sensor.
  /// \param type Message type.
  /// \param time Time.
  /// \param camera Camera.
  VisualTracks(const Type& type, const Time& time, const Camera* camera)
      : Base{type, time},
        ids{},
        lengths{},
        positions{},
        camera_{camera},
        tracks_{} {}

 private:
  Tracks tracks_;         ///< Tracks.
  const Camera* camera_;  ///< Camera.
};

template <typename TScalar>
class StereoVisualTracks : public VisualTracks<TScalar> {
 public:
  // Definitions.
  using Base = VisualTracks<TScalar>;
  using Type = typename Base::Type;
  using Time = typename Base::Time;
  using Camera = typename Base::Camera;

  /// Constructor from time and sensor.
  /// \param time Time.
  /// \param left_camera C