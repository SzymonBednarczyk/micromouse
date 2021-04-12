#include "tile_walls.h"

TileWalls::TileWalls(bool north, bool east, bool south, bool west, WallsType type) {
    north_wall_ = north;
    east_wall_ = east;
    south_wall_ = south;
    west_wall_ = west;
    walls_type_ = type;
    tile_distance_ = -1;
}

TileWalls::TileWalls(WallsType walls_type) {
    int coded_walls = static_cast<int>(walls_type);
    walls_type_ = walls_type;

    north_wall_ = isKthBitSet(coded_walls, 1);
    east_wall_ = isKthBitSet(coded_walls, 2);
    south_wall_ = isKthBitSet(coded_walls, 3);
    west_wall_ = isKthBitSet(coded_walls, 4);

    tile_distance_ = -1;
}

TileWalls::TileWalls(const int coded_walls) {
    walls_type_ = static_cast<WallsType>(coded_walls);

    north_wall_ = isKthBitSet(coded_walls, 1);
    east_wall_ = isKthBitSet(coded_walls, 2);
    south_wall_ = isKthBitSet(coded_walls, 3);
    west_wall_ = isKthBitSet(coded_walls, 4);

    tile_distance_ = -1;
}

TileWalls::~TileWalls(){}

bool TileWalls::northWall() const { return north_wall_; }

void TileWalls::setNorthWall(bool value) { north_wall_ = value; }

bool TileWalls::eastWall() const { return east_wall_; }

void TileWalls::setEastWall(bool value) { east_wall_ = value; }

bool TileWalls::southWall() const { return south_wall_; }

void TileWalls::setSouthWall(bool value) { south_wall_ = value; }

bool TileWalls::westWall() const { return west_wall_; }

void TileWalls::setWestWall(bool value) { west_wall_ = value; }

WallsType TileWalls::wallsType() const { return walls_type_; }

int TileWalls::tileDistance() const { return tile_distance_; }

void TileWalls::setTileDistance(int tile_distance) { tile_distance_ = tile_distance; }

bool TileWalls::isKthBitSet(int n, int k)
{
    if (n & (1 << (k - 1))){
        // std::cout << "Number: " << n << "bit " << k << " SET" << std::endl;
        return true;
    }
    else {
        // std::cout << "Number: " << n << "bit " << k << " NOT SET" << std::endl;
        return false;
    }
}