#ifndef LABYRINTH_TILE_H
#define LABYRINTH_TILE_H

#include "entity.h"

class LabyrinthTile : public Entity {
public:
    LabyrinthTile();
    virtual ~LabyrinthTile();
    void loadTextureFromFile(const std::string& filename);
    void draw();
    void update();
private:
};

#endif // LABYRINTH_TILE_H
