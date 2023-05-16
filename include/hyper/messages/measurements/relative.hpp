
/// This file is subject to the terms and conditions defined in
/// the 'LICENSE' file, which is part of this repository.

#pragma once

#include "hyper/messages/measurements/measurement.hpp"

namespace hyper::messages {

template <typename TSensor, typename TValue>
class RelativeMeasurement final : public MeasurementBase<TValue> {
 public:
  // Definitions.
  using Base = MeasurementBase<TValue>;
  using Type = typename Base::Type;
  using Time = typename Base::Time;

  /// Constructor from time, sensor and value.
  /// \param time Time.
  /// \param sensor Sensor.
  /// \param other_time Other time.
  /// \param other_sensor Other sensor.
  /// \param value Value.
  RelativeMeasurement(const Time& time, const TSensor& sensor, const Time& other_time, const TSensor& other_sensor, const TValue& value)
      : Base{Type::RELATIVE_MEASUREMENT, time, value}, other_time_{other_time}, sensor_{&sensor}, other_sensor_{&other_sensor} {}

  /// Other time accessor.
  /// \return Other time.
  [[nodiscard]] auto otherTime() const -> const Time& { return other_time_; }

  /// Other time modifier.
  /// \return Other time.
  auto otherTime() -> Time& { return static_cast<Time&>(std::as_const(*this).otherTime()); }