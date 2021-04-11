#ifndef TILE_WALLS_H
#define TILE_WALLS_H

#include "utils.h"
#include <iostream>


class TileWalls {
public:
    TileWalls(bool north = false, bool east = false, bool south = false, bool west = false);
    TileWalls(WallsType walls_type);
    TileWalls(const int coded_walls);
    virtual ~TileWalls();
    bool northWall() const;
    void setNorthWall(bool value);
    bool eastWall() const;
    void setEastWall(bool value);
    bool southWall() const;
    void setSouthWall(bool value);
    bool westWall() const;
    void setWestWall(bool value);
    WallsType wallsType() const;
private:
    bool north_wall_;
    bool east_wall_;
    bool south_wall_;
    bool west_wall_;
    /**
     * @brief function checking if bit is set in integer
     * @param n - integer to check
     * @param k - which bit to check
     * @return true if bit is 1, false if 0
     */
    bool isKthBitSet(int n, int k);
    WallsType walls_type_;
};

#endif // TILE_WALLS_H
