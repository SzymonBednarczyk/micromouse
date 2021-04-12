#ifndef SENSOR_H
#define SENSOR_H

#include "sensor_readings.h"
#include "labyrinth.h"
#include "data_structures.h"

class Sensor {
public:
    Sensor(){}
    virtual ~Sensor(){}
    virtual SensorReadings getReadings(Labyrinth* labyrinth,
                                       std::pair<size_t, size_t> robot_pose,
                                       RobotDirection robot_direction) = 0;
private:

};

#endif // SENSOR_H
