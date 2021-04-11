#include "labyrinth_tile.h"

LabyrinthTile::LabyrinthTile()
{
    ;
}

LabyrinthTile::~LabyrinthTile()
{
    ;
}

void LabyrinthTile::update(sf::Vector2f pose) {
    sprite_.setPosition(pose);
}

WallsType LabyrinthTile::wallType() const { return wall_type_; }

void LabyrinthTile::setWallType(const WallsType &value) { wall_type_ = value; }
