#ifndef LABYRINTH_TILE_H
#define LABYRINTH_TILE_H

#include "entity.h"
#include "utils.h"

class LabyrinthTile : public Entity {
public:
    LabyrinthTile();
    virtual ~LabyrinthTile();
    void update(sf::Vector2f pose);
    WallsType wallType() const;
    void setWallType(const WallsType &value);
    static const int TILE_PIXEL_SIZE = 76;
private:
    WallsType wall_type_;
};

#endif // LABYRINTH_TILE_H
