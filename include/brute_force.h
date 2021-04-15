#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include "path_algorythm.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>


class BruteForce : public PathAlgorithm {
public:
    BruteForce();
    virtual ~BruteForce(){}

    Direction makeMoveDecision(
        const std::vector<std::vector<TileWalls>> &map,
        std::pair<size_t, size_t> robot_position,
        Direction robot_direction);
private:

};

#endif // BRUTE_FORCE_H
