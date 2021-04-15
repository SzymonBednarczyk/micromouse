#include "entity.h"

void Entity::load(sf::Vector2u tileSize, sf::Texture &texture, unsigned int number_of_elements) {
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

void Entity::load(sf::Vector2u tileSize, sf::Color color) {
    vertices_.setPrimitiveType(sf::Quads);
    vertices_.resize(4);
    sf::Vertex* quad = &vertices_[0];

    // define its 4 corners
    quad[0].position = sf::Vector2f(0, 0);
    quad[0].color = color;
    quad[1].position = sf::Vector2f(tileSize.x, 0);
    quad[1].color = color;
    quad[2].position = sf::Vector2f(tileSize.x, tileSize.y);
    quad[2].color = color;
    quad[3].position = sf::Vector2f(0, tileSize.y);
    quad[3].color = color;
}

void Entity::setColor(sf::Color color) {
    sf::Vertex* quad = &vertices_[0];

    quad[0].color = color;
    quad[1].color = color;
    quad[2].color = color;
    quad[3].color = color;
}

void Entity::setTextureArea(sf::Vector2u top_left, sf::Vector2u top_right,
                            sf::Vector2u bottom_right, sf::Vector2u bottom_left) {
    sf::Vertex* quad = &vertices_[0];

    quad[0].texCoords = sf::Vector2f(bottom_left.x, bottom_left.y);
    quad[1].texCoords = sf::Vector2f(bottom_right.x, bottom_right.y);
    quad[2].texCoords = sf::Vector2f(top_right.x, top_right.y);
    quad[3].texCoords = sf::Vector2f(top_left.x, top_left.y);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= getTransform();

    // apply the texture
    states.texture = &textures_;

    // you may also override states.shader or states.blendMode if you want

    // draw the vertex array
    target.draw(vertices_, states);
}

