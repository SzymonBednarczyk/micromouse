#include "wall_follower.h"

WallFollower::WallFollower(/* args */) {
    ;
}

WallFollower::~WallFollower() {
    ;
}

Direction WallFollower::makeMoveDecision(
    const std::vector<std::vector<TileWalls>> &map,
    std::pair<size_t, size_t> robot_position,
    Direction robot_direction) {

    TileWalls map_tile = map.at(robot_position.first).at(robot_position.second);

    bool left_occupied = true, front_occupied = true, right_occupied = true;

    switch (robot_direction) {
        case Direction::N:
            left_occupied = map_tile.westWall();
            front_occupied = map_tile.northWall();
            right_occupied = map_tile.eastWall();

            if (!right_occupied){
                return Direction::E;
            }
            else if (!front_occupied)
                return Direction::N;
            else if (!left_occupied)
                return Direction::W;
            else
                return Direction::S;
            break;
        case Direction::E:
            left_occupied = map_tile.northWall();
            front_occupied = map_tile.eastWall();
            right_occupied = map_tile.southWall();

            if (!right_occupied)
                return Direction::S;
            else if (!front_occupied)
                return Direction::E;
            else if (!left_occupied)
                return Direction::N;
            else
                return Direction::W;
            break;
        case Direction::S:
            left_occupied = map_tile.eastWall();
            front_occupied = map_tile.southWall();
            right_occupied = map_tile.westWall();
            std::cout << "Wall follower left: " << left_occupied << " front: " << front_occupied << " right: " <<right_occupied << std::endl;

            if (!right_occupied)
                return Direction::W;
            else if (!front_occupied)
                return Direction::S;
            else if (!left_occupied)
                return Direction::E;
            else
                return Direction::N;
            break;
        case Direction::W:
            left_occupied = map_tile.southWall();
            front_occupied = map_tile.westWall();
            right_occupied = map_tile.northWall();

            if (!right_occupied)
                return Direction::N;
            else if (!front_occupied)
                return Direction::W;
            else if (!left_occupied)
                return Direction::S;
            else
                return Direction::E;
            break;
    }

    return robot_direction;
}

