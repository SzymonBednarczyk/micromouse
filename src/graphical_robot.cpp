#include "graphical_robot.h"

GraphicalRobot::GraphicalRobot(/* args */) {
    this->setPosition(DRAWING_ORIGIN_X, DRAWING_ORIGIN_Y);
    this->setOrigin(static_cast<float>(PIXEL_SIZE_X / 2),
                    static_cast<float>(PIXEL_SIZE_Y / 2));
}

std::string GraphicalRobot::textureName() const {
     return texture_name_;
}

bool GraphicalRobot::updateRobotReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates) {
    return robot_.getWallsReadings(labyrinth, robot_maze_coordinates);
}

void GraphicalRobot::choosePathToRide() {
     robot_.choosePathToRide();
}

sf::Vector2f GraphicalRobot::getRobotVelocity() {
     return sf::Vector2f(robot_.xVel(), robot_.yVel());
}