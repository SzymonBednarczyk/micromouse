#include "graphical_labyrinth.h"

GraphicalLabyrinth::GraphicalLabyrinth(){
    int rows = sizeof tiles_ / sizeof tiles_[0];
    int cols = sizeof tiles_[0] / sizeof(LabyrinthTile);

    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++) {
            tiles_[i][j].setWallType(
                labirynth_.getSpecificWallOfLabirynth(i, j)->wallsType());
        }
    }
}

void GraphicalLabyrinth::setSprites(TextureManager *texture_manager) {
    int rows = sizeof tiles_ / sizeof tiles_[0];
    int cols = sizeof tiles_[0] / sizeof(LabyrinthTile);

    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++) {
            tiles_[i][j].setTexture(
                texture_manager->getTextureRef(
                    wallsTypeToStr(tiles_[i][j].wallType())));
            int pixel_size = tiles_[i][j].tilePixelSize();
            tiles_[i][j].update(
                sf::Vector2f(
                    drawing_origin_x_ + j * pixel_size,
                    drawing_origin_y_ - i * pixel_size));
        }
    }
}

void GraphicalLabyrinth::draw(sf::RenderWindow* window) {
    int rows = sizeof tiles_ / sizeof tiles_[0];
    int cols = sizeof tiles_[0] / sizeof(LabyrinthTile);

    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++) {
            tiles_[i][j].draw(window);
            ;
        }
    }
}

void GraphicalLabyrinth::update() {
    ;
}

Labyrinth GraphicalLabyrinth::labirynth() const { return labirynth_; }
