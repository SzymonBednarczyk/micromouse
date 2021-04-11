#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>


class Entity : public sf::Drawable, public sf::Transformable{
public:
    void load(sf::Vector2u tileSize, sf::Texture &texture, unsigned int number_of_elements = 1) {
        vertices_.setPrimitiveType(sf::Quads);
        vertices_.resize(number_of_elements * 4);
        textures_ = texture;

        for (size_t i = 0; i < number_of_elements; i++) {
            sf::Vertex* quad = &vertices_[i];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, 0);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, 0);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(i * tileSize.x, 0);
            quad[1].texCoords = sf::Vector2f((i + 1) * tileSize.x, 0);
            quad[2].texCoords = sf::Vector2f((i + 1) * tileSize.x, tileSize.y);
            quad[3].texCoords = sf::Vector2f(i * tileSize.x, tileSize.y);
        }

    }
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the entity's transform -- combine it with the one that was passed by the caller
        states.transform *= getTransform();

        // apply the texture
        states.texture = &textures_;

        // you may also override states.shader or states.blendMode if you want

        // draw the vertex array
        target.draw(vertices_, states);
    }

    sf::VertexArray vertices_;
    sf::Texture textures_;
};

#endif // ENTITY_H
