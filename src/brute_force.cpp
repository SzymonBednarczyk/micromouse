#include "brute_force.h"

BruteForce::BruteForce(){
    std::srand(time(0));
}

Direction BruteForce::makeMoveDecision(
        const std::vector<std::vector<TileWalls>> &map,
        std::pair<size_t, size_t> robot_position,
        Direction robot_direction) {

    TileWalls map_tile = map.at(robot_position.first).at(robot_position.second);

    int number_of_free_walls = !map_tile.northWall() + !map_tile.eastWall()
                               + !map_tile.southWall() + !map_tile.westWall();

    if (number_of_free_walls < 3) {
        switch (robot_direction) {
            case Direction::N:
                if (!map_tile.eastWall()){
                    return Direction::E;
                }
                else if (!map_tile.northWall())
                    return Direction::N;
                else if (!map_tile.westWall())
                    return Direction::W;
                else
                    return Direction::S;
                break;
            case Direction::E:
                if (!map_tile.southWall())
                    return Direction::S;
                else if (!map_tile.eastWall())
                    return Direction::E;
                else if (!map_tile.northWall())
                    return Direction::N;
                else
                    return Direction::W;
                break;
            case Direction::S:
                if (!map_tile.westWall())
                    return Direction::W;
                else if (!map_tile.southWall())
                    return Direction::S;
                else if (!map_tile.eastWall())
                    return Direction::E;
                else
                    return Direction::N;
                break;
            case Direction::W:
                if (!map_tile.northWall())
                    return Direction::N;
                else if (!map_tile.westWall())
                    return Direction::W;
                else if (!map_tile.southWall())
                    return Direction::S;
                else
                    return Direction::E;
                break;
        }
    }

    int random_number = rand() % (number_of_free_walls - 1) + 1;

    switch (robot_direction) {
        case Direction::N:
            random_number -= !map_tile.eastWall();

            if (random_number == 0) {
                return Direction::E;
            }
            random_number -= !map_tile.northWall();

            if (random_number == 0) {
                return Direction::N;
            }
            random_number -= !map_tile.westWall();

            if (random_number == 0) {
                return Direction::W;
            }
            break;
        case Direction::E:
            random_number -= !map_tile.eastWall();

            if (random_number == 0) {
                return Direction::E;
            }
            random_number -= !map_tile.northWall();

            if (random_number == 0) {
                return Direction::N;
            }
            random_number -= !map_tile.southWall();

            if (random_number == 0) {
                return Direction::S;
            }
        case Direction::S:
            random_number -= !map_tile.eastWall();

            if (random_number == 0) {
                return Direction::E;
            }
            random_number -= !map_tile.westWall();

            if (random_number == 0) {
                return Direction::W;
            }
            random_number -= !map_tile.southWall();

            if (random_number == 0) {
                return Direction::S;
            }
        case Direction::W:
            random_number -= !map_tile.northWall();

            if (random_number == 0) {
                return Direction::N;
            }
            random_number -= !map_tile.westWall();

            if (random_number == 0) {
                return Direction::W;
            }
            random_number -= !map_tile.southWall();

            if (random_number == 0) {
                return Direction::S;
            }
    }

    return Direction::N;
}
