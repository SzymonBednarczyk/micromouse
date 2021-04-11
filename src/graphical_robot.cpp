#include "graphical_robot.h"

Graphical_Robot::Graphical_Robot(/* args */) {
    ;
}

void Graphical_Robot::update(sf::Vector2f pose) {
    sprite_.setPosition(pose);
}

void Graphical_Robot::setSprite(TextureManager *texture_manager) {
    sprite_.setTexture(
        texture_manager->getTextureRef(TEXTURE_NAME_));
    this->update(sf::Vector2f(DRAWING_ORIGIN_X, DRAWING_ORIGIN_Y));
}
