#include "graphical_robot.h"

Graphical_Robot::Graphical_Robot(/* args */) {
    this->setPosition(DRAWING_ORIGIN_X, DRAWING_ORIGIN_Y);
}

std::string Graphical_Robot::TEXTURENAME() const { return TEXTURE_NAME_; }