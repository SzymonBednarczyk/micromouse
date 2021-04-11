#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>


class Entity {
public:
    void setTexture(sf::Texture &texture) {
        sprite_.setTexture(texture);
    }

    virtual void draw(sf::RenderWindow* window) {
        window->draw(sprite_);
    };
    virtual void update(sf::Vector2f pose) = 0;
protected:
    sf::RectangleShape rectangle_;
    sf::Sprite sprite_;
};

#endif // ENTITY_H
