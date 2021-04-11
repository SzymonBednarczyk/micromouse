
#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <vector>

#include "tile_walls.h"

class Labyrinth {
public:
    Labyrinth();
    virtual ~Labyrinth();
    const TileWalls* getLabirynthWalls();
    const TileWalls* const getSpecificWallOfLabirynth(int col, int row);
    void printLabyrinth();
private:
    TileWalls tile_walls_of_labirynth_ [3][3] = {{TileWalls(WallsType::ESW), TileWalls(WallsType::ESW), TileWalls(WallsType::ESW)}, // 0
                                                 {TileWalls(WallsType::EW), TileWalls(WallsType::W) , TileWalls(WallsType::NE)},  // 1
                                                 {TileWalls(WallsType::NW) , TileWalls(WallsType::N) , TileWalls(WallsType::NES)}}; // 2
    //  _______
    //2 |   __|
    //1 | |   |
    //0 |R| | |
    //  ^^^^^^^
    //   0 1 2

    bool isKthBitSet(int n, int k);
};

#endif // LABYRINTH_H
