#include "graphical_labyrinth.h"

GraphicalLabyrinth::GraphicalLabyrinth(){

    for (size_t i = 0; i < Labyrinth::LABYRINTH_SIZE; i++)
    {
        for (size_t j = 0; j < Labyrinth::LABYRINTH_SIZE; j++) {
            tiles_[i][j].setWallType(
                labirynth_.getSpecificWallOfLabirynth(i, j)->wallsType());
        }
    }
}

void GraphicalLabyrinth::loadEntity(TextureManager *texture_manager) {

    for (size_t i = 0; i < Labyrinth::LABYRINTH_SIZE; i++)
    {
        for (size_t j = 0; j < Labyrinth::LABYRINTH_SIZE; j++) {
            tiles_[i][j].load(
                sf::Vector2u(LabyrinthTile::TILE_PIXEL_SIZE,
                             LabyrinthTile::TILE_PIXEL_SIZE),
                texture_manager->getTextureRef(
                    wallsTypeToStr(tiles_[i][j].wallType())));
            tiles_[i][j].setPosition(
                sf::Vector2f(
                    DRAWING_ORIGIN_X + j * LabyrinthTile::TILE_PIXEL_SIZE,
                    DRAWING_ORIGIN_Y - i * LabyrinthTile::TILE_PIXEL_SIZE));
        }
    }
}

void GraphicalLabyrinth::draw(sf::RenderWindow* window) {

    for (size_t i = 0; i < Labyrinth::LABYRINTH_SIZE; i++)
    {
        for (size_t j = 0; j < Labyrinth::LABYRINTH_SIZE; j++) {
            window->draw(tiles_[i][j]);
        }
    }
}

void GraphicalLabyrinth::update() {
    ;
}

Labyrinth GraphicalLabyrinth::labirynth() const { return labirynth_; }
