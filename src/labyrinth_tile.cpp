#include "labyrinth_tile.h"

LabyrinthTile::LabyrinthTile()
{
    ;
}

LabyrinthTile::~LabyrinthTile()
{
    ;
}

void LabyrinthTile::draw(sf::RenderWindow* window) {
    window->draw(sprite_);
}

void LabyrinthTile::update(sf::Vector2f pose) {
    sprite_.setPosition(pose);
}

int LabyrinthTile::tilePixelSize() const { return tile_pixel_size_; }

WallsType LabyrinthTile::wallType() const { return wall_type_; }

void LabyrinthTile::setWallType(const WallsType &value) { wall_type_ = value; }
