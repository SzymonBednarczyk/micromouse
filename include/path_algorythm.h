#ifndef PATH_ALGORYTHM_H
#define PATH_ALGORYTHM_H

#include "data_structures.h"
#include "tile_walls.h"
#include "vector"


class PathAlgorithm {
public:
    PathAlgorithm(){}
    virtual ~PathAlgorithm(){}
    virtual Direction makeMoveDecision(
        const std::vector<std::vector<TileWalls>> &map,
        std::pair<size_t, size_t> robot_position,
        Direction robot_direction) = 0;
private:

};


#endif // PATH_ALGORYTHM_H
