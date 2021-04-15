
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
    static const size_t LABYRINTH_SIZE = 10;
    bool loadLabyrinthFromFile(std::string file_path);
    void saveLabyrinthToFile(std::string file_path);
private:
    TileWalls tile_walls_of_labirynth_ [LABYRINTH_SIZE][LABYRINTH_SIZE] =
    {{TileWalls(TileWalls(WallsType::SW)), TileWalls(WallsType::NS), TileWalls(WallsType::ES), TileWalls(WallsType::NESW), TileWalls(WallsType::ESW),
      TileWalls(TileWalls(WallsType::NESW)), TileWalls(WallsType::SW), TileWalls(WallsType::NS), TileWalls(WallsType::NS), TileWalls(WallsType::ES)}, // 0
     {TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::ESW), TileWalls(WallsType::NW), TileWalls(WallsType::NS), TileWalls(WallsType::NONE),
      TileWalls(TileWalls(WallsType::NS)), TileWalls(WallsType::NE), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW), TileWalls(WallsType::EW)}, // 1
     {TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::EW), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW), TileWalls(WallsType::EW),
      TileWalls(TileWalls(WallsType::NESW)), TileWalls(WallsType::NESW), TileWalls(WallsType::ESW), TileWalls(WallsType::NESW), TileWalls(WallsType::EW)}, // 2
     {TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::EW), TileWalls(WallsType::SW), TileWalls(WallsType::S), TileWalls(WallsType::N),
      TileWalls(TileWalls(WallsType::S)), TileWalls(WallsType::NS), TileWalls(WallsType::NE), TileWalls(WallsType::NESW), TileWalls(WallsType::EW)}, // 3
     {TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::EW), TileWalls(WallsType::NW), TileWalls(WallsType::E), TileWalls(WallsType::NESW),
      TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW), TileWalls(WallsType::EW)}, // 4
     {TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::W), TileWalls(WallsType::NES), TileWalls(WallsType::EW), TileWalls(WallsType::NESW),
      TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW), TileWalls(WallsType::EW)}, // 5
     {TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::EW), TileWalls(WallsType::SW), TileWalls(WallsType::N), TileWalls(WallsType::NS),
      TileWalls(TileWalls(WallsType::N)), TileWalls(WallsType::NS), TileWalls(WallsType::NES), TileWalls(WallsType::NESW), TileWalls(WallsType::NEW)}, // 6
     {TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::EW), TileWalls(WallsType::EW), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW),
      TileWalls(TileWalls(WallsType::NESW)), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW)}, // 7
     {TileWalls(TileWalls(WallsType::EW)), TileWalls(WallsType::NEW), TileWalls(WallsType::W), TileWalls(WallsType::NS), TileWalls(WallsType::ES),
      TileWalls(TileWalls(WallsType::NESW)), TileWalls(WallsType::SW), TileWalls(WallsType::NS), TileWalls(WallsType::NS), TileWalls(WallsType::ES)}, // 8
     {TileWalls(TileWalls(WallsType::NW)), TileWalls(WallsType::NS), TileWalls(WallsType::NE), TileWalls(WallsType::NESW), TileWalls(WallsType::NW),
      TileWalls(TileWalls(WallsType::NS)), TileWalls(WallsType::NE), TileWalls(WallsType::NESW), TileWalls(WallsType::NESW), TileWalls(WallsType::NEW)}}; // 9

    bool isKthBitSet(int n, int k);
};

#endif // LABYRINTH_H
