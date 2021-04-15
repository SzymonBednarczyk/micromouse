#ifndef LASER_SCANNER_H
#define LASER_SCANNER_H

#include "sensor.h"
#include <iostream>


class LaserScanner : public Sensor{
public:
    LaserScanner(){}
    ~LaserScanner(){}
    SensorReadings getReadings(Labyrinth* labyrinth,
                               std::pair<size_t, size_t> robot_pose,
                               Direction robot_direction);
private:
};


#endif // LASER_SCANNER_H
