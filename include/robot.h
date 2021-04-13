#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <list>

#include "ir_sensor.h"
#include "sensor.h"
#include "data_structures.h"
#include "sensor_readings.h"
#include "labyrinth.h"
#include "path_algorythm.h"
#include "wall_follower.h"
#include "labyrinth_tile.h"

class Robot {
public:
    Robot();
    virtual ~Robot(){}
    bool getWallsReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates);
    void choosePathToRide();
    bool changeDirection(float robot_pose_x, float robot_pose_y);
    bool newTile() const;
    float xVel() const;
    float yVel() const;
    Direction robotDirection() const;
private:
    void changeVelocities();
    TileWalls convertReadingsToMap(SensorReadings readings);
    Direction robot_direction_;
    Sensor* sensor_;
    IrSensor ir_sensor_;
    PathAlgorithm* path_algorithm_;
    WallFollower wall_follower_;
    std::vector<std::vector<TileWalls>> labyrinth_map_;
    std::pair<size_t, size_t> robot_maze_coordinates_;
    bool new_tile_;
    bool first_tile_;
    float velocity_;
    float x_vel_;
    float y_vel_;
    std::string dir_str;
    std::list<std::string> move_instructions_str_;
    std::list<Direction> move_instructions_;
};

#endif // ROBOT_H
