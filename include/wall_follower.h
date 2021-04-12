#ifndef WALL_FOLLOWER_H
#define WALL_FOLLOWER_H

#include "path_algorythm.h"
#include <iostream>


class WallFollower : public PathAlgorithm {
public:
    WallFollower(/* args */);
    ~WallFollower();
    Direction makeMoveDecision(
        const std::vector<std::vector<TileWalls>> &map,
        std::pair<size_t, size_t> robot_position,
        Direction robot_direction);
private:
    /* data */
};

#endif // WALL_FOLLOWER_H
