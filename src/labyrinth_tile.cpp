#include "labyrinth_tile.h"

LabyrinthTile::LabyrinthTile()
{
    ;
}

LabyrinthTile::~LabyrinthTile()
{
    ;
}

WallsType LabyrinthTile::wallType() const { return wall_type_; }

void LabyrinthTile::setWallType(const WallsType &value) { wall_type_ = value; }
