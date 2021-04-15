#ifndef SENSOR_H
#define SENSOR_H

#include "sensor_readings.h"
#include "labyrinth.h"
#include "data_structures.h"

class Sensor {
public:
    Sensor(){}
    virtual ~Sensor(){}
    virtual std::string getTexture() { return texture_name_; }
    virtual SensorReadings getReadings(Labyrinth* labyrinth,
                                       std::pair<size_t, size_t> robot_pose,
                                       Direction robot_direction) = 0;
private:
    const std::string texture_name_ = "sensors";
};

#endif // SENSOR_H
