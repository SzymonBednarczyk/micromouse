#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>

#include "ir_sensor.h"
#include "sensor.h"
#include "data_structures.h"
#include "sensor_readings.h"
#include "labyrinth.h"
#include "path_algorythm.h"
#include "wall_follower.h"

class Robot {
public:
    Robot();
    virtual ~Robot(){}
    bool getWallsReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates);
    void choosePathToRide();
    bool newTile() const;
    float xVel() const;
    float yVel() const;
private:
    TileWalls convertReadingsToMap(SensorReadings readings);
    Direction robot_direction_;
    Sensor* sensor_;
    IrSensor ir_sensor_;
    PathAlgorithm* path_algorithm_;
    WallFollower wall_follower_;
    std::vector<std::vector<TileWalls>> labyrinth_map_;
    std::pair<size_t, size_t> robot_maze_coordinates_;
    bool new_tile_;
    float velocity_;
    float x_vel_;
    float y_vel_;
    std::string dir_str;
};

#endif // ROBOT_H
