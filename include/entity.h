#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>


class Entity : public sf::Drawable, public sf::Transformable{
public:
    void load(sf::Vector2u tileSize, sf::Texture &texture, unsigned int number_of_elements = 1);
    void load(sf::Vector2u tileSize, sf::Color color);
    void setColor(sf::Color color);
    void setTextureArea(sf::Vector2u top_left, sf::Vector2u top_right,
                        sf::Vector2u bottom_right, sf::Vector2u bottom_left);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray vertices_;
    sf::Texture textures_;
};

#endif // ENTITY_H
