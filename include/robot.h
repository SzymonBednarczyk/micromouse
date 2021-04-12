#ifndef ROBOT_H
#define ROBOT_H

#include "ir_sensor.h"
#include "sensor.h"
#include "data_structures.h"
#include "sensor_readings.h"
#include <iostream>


class Robot {
public:
    Robot();
    virtual ~Robot(){}
    void getWallsReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates);
private:
    RobotDirection robot_direction_;
    Sensor* sensor_;
    IrSensor ir_sensor_;
};

#endif // ROBOT_H
