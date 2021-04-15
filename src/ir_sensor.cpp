#include "ir_sensor.h"

IrSensor::IrSensor(/* args */)
{
    ;
}

SensorReadings
IrSensor::getReadings(Labyrinth* labyrinth,
                      std::pair<size_t, size_t> robot_pose,
                      Direction robot_direction) {
    bool left, front, right;

    TileWalls labyrinth_tile =
            labyrinth->getSpecificWallOfLabirynth(robot_pose.first, robot_pose.second);


    switch (robot_direction) {
        case Direction::N:
            left = labyrinth_tile.westWall();
            front = labyrinth_tile.northWall();
            right = labyrinth_tile.eastWall();
            break;
        case Direction::E:
            left = labyrinth_tile.northWall();
            front = labyrinth_tile.eastWall();
            right = labyrinth_tile.southWall();
            break;
        case Direction::S:
            left = labyrinth_tile.eastWall();
            front = labyrinth_tile.southWall();
            right = labyrinth_tile.westWall();
            break;
        case Direction::W:
            left = labyrinth_tile.southWall();
            front = labyrinth_tile.westWall();
            right = labyrinth_tile.northWall();
            break;
        default:
            return SensorReadings();
            break;
    }

    return SensorReadings({left}, {front}, {right});
}
