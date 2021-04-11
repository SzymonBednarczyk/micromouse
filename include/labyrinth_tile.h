#ifndef LABYRINTH_TILE_H
#define LABYRINTH_TILE_H

#include "entity.h"
#include "utils.h"

class LabyrinthTile : public Entity {
public:
    LabyrinthTile();
    virtual ~LabyrinthTile();
    void draw(sf::RenderWindow* window);
    void update(sf::Vector2f pose);
    int tilePixelSize() const;
    WallsType wallType() const;
    void setWallType(const WallsType &value);
private:
    const int tile_pixel_size_ = 76;
    WallsType wall_type_;
};

#endif // LABYRINTH_TILE_H
