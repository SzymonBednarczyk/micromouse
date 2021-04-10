#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual void loadTextureFromFile(const std::string& filename) = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
protected:
    sf::Texture texture_;
    sf::RectangleShape rectangle_;
    sf::Sprite sprite_;
};

#endif // ENTITY_H
