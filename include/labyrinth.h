
#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "tile_walls.h"

class Labyrinth {
public:
    Labyrinth();
    virtual ~Labyrinth();
    const TileWalls* getLabirynthWalls();
    const TileWalls& getSpecificWallOfLabirynth(int row, int col);
    void printLabyrinth();
    static const size_t LABYRINTH_SIZE = 4;
    bool loadLabyrinthFromFile(std::string file_path);
    void saveLabyrinthToFile(std::string file_path);
private:
    TileWalls tile_walls_of_labirynth_ [LABYRINTH_SIZE][LABYRINTH_SIZE] = {{TileWalls(14), TileWalls(WallsType::ESW), TileWalls(WallsType::SW), TileWalls(WallsType::ES)}, // 0
                                                                           {TileWalls(WallsType::EW), TileWalls(WallsType::W) , TileWalls(WallsType::NE), TileWalls(WallsType::EW)},    // 1
                                                                           {TileWalls(WallsType::EW) , TileWalls(WallsType::NW) , TileWalls(WallsType::ES), TileWalls(WallsType::EW)},
                                                                           {TileWalls(WallsType::NW) , TileWalls(WallsType::NS) , TileWalls(WallsType::NE), TileWalls(WallsType::NEW)}}; // 2
    //  _______
    //2 |   __|
    //1 | |   |
    //0 |R| | |
    //  ^^^^^^^
    //   0 1 2

    bool isKthBitSet(int n, int k);
};

#endif // LABYRINTH_H
