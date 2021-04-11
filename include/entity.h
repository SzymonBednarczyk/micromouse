#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>


class Entity : public sf::Drawable, public sf::Transformable{
public:
    void load(sf::Vector2u tileSize, sf::Texture &texture, unsigned int number_of_elements = 1);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray vertices_;
    sf::Texture textures_;
};

#endif // ENTITY_H
