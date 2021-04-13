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
    first_tile_ = true;

    for (auto &val : labyrinth_map_) {
        val.resize(Labyrinth::LABYRINTH_SIZE);
    }
}

bool Robot::getWallsReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates) {

    if (robot_maze_coordinates_ == robot_maze_coordinates) {
        return false;
    }
    SensorReadings readings =
        sensor_->getReadings(labyrinth, robot_maze_coordinates, robot_direction_);

    labyrinth_map_[robot_maze_coordinates.first][robot_maze_coordinates.second]
        = convertReadingsToMap(readings);

    std::cout << "left reading: " << readings.left << " front: " << readings.front << " right: " <<readings.right << " robot direction: " << dir_str << std::endl;

    robot_maze_coordinates_ = robot_maze_coordinates;

    new_tile_ = true;

    return true;
}

void Robot::choosePathToRide() {
    Direction direction_to_move = path_algorithm_->makeMoveDecision(
        labyrinth_map_, robot_maze_coordinates_, robot_direction_);
    // std::string dir_str;

    switch (direction_to_move) {
        case Direction::N:
            dir_str = 'N';
            break;
        case Direction::E:
            dir_str = 'E';
            break;
        case Direction::S:
            dir_str = 'S';
            break;
        case Direction::W:
            dir_str = 'W';
            break;
    }

    move_instructions_.push_back(direction_to_move);
    move_instructions_str_.push_back(dir_str);

    std::string directions = "";
    for (auto const &dir : move_instructions_str_) {
        directions += dir + " -> ";
    }
    std::cout << "directions: " << directions << std::endl;
}

bool Robot::changeDirection(float robot_pose_x, float robot_pose_y) {

    if (!new_tile_)
        return false;

    float middle_of_tile_x =
        LabyrinthTile::TILE_PIXEL_SIZE * robot_maze_coordinates_.second
            + LabyrinthTile::TILE_PIXEL_SIZE / 2;
    float middle_of_tile_y =
        LabyrinthTile::TILE_PIXEL_SIZE * robot_maze_coordinates_.first
            + LabyrinthTile::TILE_PIXEL_SIZE / 2;
    if (std::abs(middle_of_tile_x - robot_pose_x) <= 5 &&
        std::abs(middle_of_tile_y - robot_pose_y) <= 5) {

        if (!first_tile_) {
            robot_direction_ = *std::next(move_instructions_.begin());
            move_instructions_.pop_front();
            move_instructions_str_.pop_front();
        } else {
            robot_direction_ = move_instructions_.back();
            first_tile_ = false;
        }

        new_tile_ = false;
        changeVelocities();

        return true;
    } else {
        return false;
    }
}

bool Robot::newTile() const { return new_tile_; }

float Robot::xVel() const { return x_vel_; }

float Robot::yVel() const { return y_vel_; }

Direction Robot::robotDirection() const { return robot_direction_; }

void Robot::changeVelocities() {
    switch (robot_direction_) {
        case Direction::N:
            x_vel_ = 0;
            y_vel_ = -velocity_;
            break;
        case Direction::E:
            x_vel_ = velocity_;
            y_vel_ = 0;
            break;
        case Direction::S:
            x_vel_ = 0;
            y_vel_ = velocity_;
            break;
        case Direction::W:
            x_vel_ = -velocity_;
            y_vel_ = 0;
            break;
        default:
            x_vel_ = 0;
            y_vel_ = 0;
            break;
    }
}

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
