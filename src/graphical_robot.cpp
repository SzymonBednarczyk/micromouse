#include "graphical_robot.h"

GraphicalRobot::GraphicalRobot() {
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

void GraphicalRobot::changeAnimation() {

     Direction robot_direction = robot_.robotDirection();
     switch (robot_direction) {
          case Direction::N:
               setTextureArea(sf::Vector2u(0, 0),
                              sf::Vector2u(PIXEL_SIZE_X, 0),
                              sf::Vector2u(PIXEL_SIZE_X, PIXEL_SIZE_Y),
                              sf::Vector2u(0, PIXEL_SIZE_Y));
               break;
          case Direction::W:
               setTextureArea(sf::Vector2u(PIXEL_SIZE_X + 2, 0),
                              sf::Vector2u(PIXEL_SIZE_X + PIXEL_SIZE_Y, 0),
                              sf::Vector2u(PIXEL_SIZE_X + PIXEL_SIZE_Y, PIXEL_SIZE_Y),
                              sf::Vector2u(PIXEL_SIZE_X + 2, PIXEL_SIZE_Y));
               break;
          case Direction::S:
               setTextureArea(sf::Vector2u(PIXEL_SIZE_X + 2 + PIXEL_SIZE_Y , 0),
                              sf::Vector2u(2 * PIXEL_SIZE_X + PIXEL_SIZE_Y + 4 , 0),
                              sf::Vector2u(2 * PIXEL_SIZE_X + PIXEL_SIZE_Y + 4, PIXEL_SIZE_Y),
                              sf::Vector2u(PIXEL_SIZE_X + 2 + PIXEL_SIZE_Y, PIXEL_SIZE_Y));
               break;
          case Direction::E:
               setTextureArea(sf::Vector2u(2 * PIXEL_SIZE_X + 4 + PIXEL_SIZE_Y, 0),
                              sf::Vector2u(2 * PIXEL_SIZE_X + 2 * PIXEL_SIZE_Y + 4, 0),
                              sf::Vector2u(2 * PIXEL_SIZE_X + 2 * PIXEL_SIZE_Y + 4, PIXEL_SIZE_Y),
                              sf::Vector2u(2 * PIXEL_SIZE_X + 4 + PIXEL_SIZE_Y, PIXEL_SIZE_Y));
               break;
          default:
               setTextureArea(sf::Vector2u(0, 0),
                              sf::Vector2u(PIXEL_SIZE_X, 0),
                              sf::Vector2u(PIXEL_SIZE_X, PIXEL_SIZE_Y),
                              sf::Vector2u(0, PIXEL_SIZE_Y));
               break;
     }
}

bool GraphicalRobot::changeDirection(sf::Vector2f robot_relative_pose) {
     return robot_.changeDirection(robot_relative_pose.x, robot_relative_pose.y);
}

void GraphicalRobot::setPathAlgorithm(GuiType algorithm) {
     robot_.setPathAlgorithm(algorithm);
}

void GraphicalRobot::setSensor(GuiType sensor) {
     robot_.setSensor(sensor);
}

void GraphicalRobot::setSensor(GuiType sensor, sf::Color color) {
     robot_.setSensor(sensor);
     graphical_sensor_.setColor(color);
}

GraphicalSensor* GraphicalRobot::graphicalSensor() { return &graphical_sensor_; }

std::string GraphicalRobot::getSensorName() {
     return robot_.getSensorName();
}