#include "sensor_readings.h"

SensorReadings::SensorReadings(bool left_reading,
                               bool front_reading,
                               bool right_reading)
    : left(left_reading),
      front(front_reading),
      right(right_reading){}
