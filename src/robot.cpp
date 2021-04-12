#include "robot.h"

Robot::Robot() {
    robot_direction_ = Direction::N;
    sensor_ = &ir_sensor_;
    path_algorithm_ = &wall_follower_;
    labyrinth_map_.resize(Labyrinth::LABYRINTH_SIZE);
    velocity_ = 10.f;
    x_vel_ = 0.f;
    y_vel_ = 0.f;
    robot_maze_coordinates_.first = 1;
    dir_str = "N";

    for (auto &val : labyrinth_map_) {
        val.resize(Labyrinth::LABYRINTH_SIZE);
    }
}

bool Robot::getWallsReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates) {

    SensorReadings readings =
        sensor_->getReadings(labyrinth, robot_maze_coordinates, robot_direction_);

    labyrinth_map_[robot_maze_coordinates.first][robot_maze_coordinates.second]
        = convertReadingsToMap(readings);

    std::cout << "left reading: " << readings.left << " front: " << readings.front << " right: " <<readings.right << " robot direction: " << dir_str << std::endl;

    if (robot_maze_coordinates_ != robot_maze_coordinates) {
        robot_maze_coordinates_ = robot_maze_coordinates;

        return true;
    }

    return false;
}

void Robot::choosePathToRide() {
    Direction direction_to_move = path_algorithm_->makeMoveDecision(
        labyrinth_map_, robot_maze_coordinates_, robot_direction_);
    // std::string dir_str;

    switch (direction_to_move) {
        case Direction::N:
            x_vel_ = 0;
            y_vel_ = -velocity_;
            dir_str = 'N';
            break;
        case Direction::E:
            x_vel_ = velocity_;
            y_vel_ = 0;
            dir_str = 'E';
            break;
        case Direction::S:
            x_vel_ = 0;
            y_vel_ = velocity_;
            dir_str = 'S';
            break;
        case Direction::W:
            x_vel_ = -velocity_;
            y_vel_ = 0;
            dir_str = 'W';
            break;
    }
    robot_direction_ = direction_to_move;
    std::cout << "Direction to move: " << dir_str << std::endl;
}

bool Robot::newTile() const { return new_tile_; }

float Robot::xVel() const { return x_vel_; }

float Robot::yVel() const { return y_vel_; }

TileWalls Robot::convertReadingsToMap(SensorReadings readings) {
    switch (robot_direction_) {
        case Direction::N:
            return TileWalls(readings.front, readings.right, false, readings.left, WallsType::N);
            break;
        case Direction::E:
            return TileWalls(readings.left, readings.front, readings.right, false, WallsType::E);
            break;
        case Direction::S:
            return TileWalls(false, readings.left, readings.front, readings.right, WallsType::S);
            break;
        case Direction::W:
            return TileWalls(readings.right, false, readings.left, readings.front, WallsType::W);
            break;
        default:
            return TileWalls();
            break;
    }
}
