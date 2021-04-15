#ifndef SENSOR_READINGS_H
#define SENSOR_READINGS_H

#include <vector>

class SensorReadings {
public:
    SensorReadings(std::vector<bool> left_reading = {false},
                   std::vector<bool> front_reading = {false},
                   std::vector<bool> right_reading = {false})
    : left(left_reading),
      front(front_reading),
      right(right_reading){}

    virtual ~SensorReadings(){}

    std::vector<bool> left;
    std::vector<bool> front;
    std::vector<bool> right;
};

#endif // SENSOR_READINGS_H
