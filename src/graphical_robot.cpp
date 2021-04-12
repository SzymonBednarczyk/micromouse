#include "graphical_robot.h"

GraphicalRobot::GraphicalRobot(/* args */) {
    this->setPosition(DRAWING_ORIGIN_X, DRAWING_ORIGIN_Y);
    this->setOrigin(static_cast<float>(PIXEL_SIZE_X / 2),
                    static_cast<float>(PIXEL_SIZE_Y / 2));
}

std::string GraphicalRobot::textureName() const {
     return texture_name_;
}

void GraphicalRobot::updateRobotReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates) {
    robot_.getWallsReadings(labyrinth, robot_maze_coordinates);
}