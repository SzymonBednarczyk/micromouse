#include "laser_scanner.h"

SensorReadings LaserScanner::getReadings(Labyrinth* labyrinth,
                                         std::pair<size_t, size_t> robot_pose,
                                         Direction robot_direction) {
    std::vector<bool> left, front, right;

    TileWalls labyrinth_tile =
            labyrinth->getSpecificWallOfLabirynth(robot_pose.first, robot_pose.second);


    switch (robot_direction) {
        case Direction::N:
            left.push_back(labyrinth_tile.westWall());
            front.push_back(labyrinth_tile.northWall());
            right.push_back(labyrinth_tile.eastWall());

            if (!left.front() && robot_pose.first != 0) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first - 1, robot_pose.second);
                left.push_back(labyrinth_tile.westWall());
            }

            if (!front.front() && robot_pose.second != labyrinth->LABYRINTH_SIZE - 1) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first, robot_pose.second + 1);
                front.push_back(labyrinth_tile.northWall());
            }

            if (!right.front() && robot_pose.first != labyrinth->LABYRINTH_SIZE - 1) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first + 1, robot_pose.second);
                right.push_back(labyrinth_tile.eastWall());
            }
            break;
        case Direction::E:
            left.push_back(labyrinth_tile.northWall());
            front.push_back(labyrinth_tile.eastWall());
            right.push_back(labyrinth_tile.southWall());

            if (!left.front() && robot_pose.second != labyrinth->LABYRINTH_SIZE - 1) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first, robot_pose.second + 1);
                left.push_back(labyrinth_tile.northWall());
            }

            if (!front.front() && robot_pose.first != labyrinth->LABYRINTH_SIZE - 1) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first + 1, robot_pose.second);
                front.push_back(labyrinth_tile.eastWall());
            }

            if (!right.front() && robot_pose.second != 0) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first, robot_pose.second - 1);
                right.push_back(labyrinth_tile.southWall());
            }
            break;
        case Direction::S:
            left.push_back(labyrinth_tile.eastWall());
            front.push_back(labyrinth_tile.southWall());
            right.push_back(labyrinth_tile.westWall());

            if (!left.front() && robot_pose.first != labyrinth->LABYRINTH_SIZE - 1) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first + 1, robot_pose.second);
                left.push_back(labyrinth_tile.eastWall());
            }

            if (!front.front() && robot_pose.second != 0) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first, robot_pose.second - 1);
                front.push_back(labyrinth_tile.southWall());
            }

            if (!right.front() && robot_pose.first != 0) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first - 1, robot_pose.second);
                right.push_back(labyrinth_tile.westWall());
            }
            break;
        case Direction::W:
            left.push_back(labyrinth_tile.southWall());
            front.push_back(labyrinth_tile.westWall());
            right.push_back(labyrinth_tile.northWall());

            if (!left.front() && robot_pose.second != 0) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first, robot_pose.second - 1);
                left.push_back(labyrinth_tile.southWall());
            }

            if (!front.front() && robot_pose.first != 0) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first - 1, robot_pose.second);
                front.push_back(labyrinth_tile.westWall());
            }

            if (!right.front() && robot_pose.second != labyrinth->LABYRINTH_SIZE - 1) {
                labyrinth_tile =
                    labyrinth->getSpecificWallOfLabirynth(
                        robot_pose.first, robot_pose.second + 1);
                right.push_back(labyrinth_tile.northWall());
            }
            break;
        default:
            return SensorReadings();
            break;
    }

    return SensorReadings(left, front, right);
}
