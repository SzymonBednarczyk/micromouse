#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <list>
#include <cmath>

#include "ir_sensor.h"
#include "sensor.h"
#include "data_structures.h"
#include "sensor_readings.h"
#include "labyrinth.h"
#include "path_algorythm.h"
#include "wall_follower.h"
#include "labyrinth_tile.h"
#include "brute_force.h"

class Robot {
public:
    Robot();
    virtual ~Robot();
    bool getWallsReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates);
    void choosePathToRide();
    bool changeDirection(float robot_pose_x, float robot_pose_y);
    bool newTile() const;
    float xVel() const;
    float yVel() const;
    Direction robotDirection() const;
    void setPathAlgorithm(GuiType algorithm);
private:
    void changeVelocities();
    TileWalls convertReadingsToMap(SensorReadings readings);
    Direction robot_direction_;
    Sensor* sensor_{nullptr};
    IrSensor ir_sensor_;
    PathAlgorithm* path_algorithm_{nullptr};
    WallFollower wall_follower_;
    BruteForce brute_force_;
    std::vector<std::vector<TileWalls>> labyrinth_map_;
    std::pair<size_t, size_t> robot_maze_coordinates_;
    bool new_tile_;
    bool first_tile_;
    float velocity_;
    float x_vel_;
    float y_vel_;
    std::list<Direction> move_instructions_;
};

#endif // ROBOT_H
