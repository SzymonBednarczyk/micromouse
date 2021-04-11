#include "graphical_robot.h"

GraphicalRobot::GraphicalRobot(/* args */) {
    this->setPosition(DRAWING_ORIGIN_X, DRAWING_ORIGIN_Y);
    this->setOrigin(static_cast<float>(PIXEL_SIZE_X / 2),
                    static_cast<float>(PIXEL_SIZE_Y / 2));
}

std::string GraphicalRobot::textureName() const {
     return texture_name_;
}