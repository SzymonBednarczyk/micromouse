#include "robot.h"

Robot::Robot() {
    robot_direction_ = Direction::N;
    sensor_ = &ir_sensor_;
    path_algorithm_ = &wall_follower_;
    labyrinth_map_.resize(Labyrinth::LABYRINTH_SIZE);
    velocity_ = 5.f;
    x_vel_ = 0.f;
    y_vel_ = 0.f;
    robot_maze_coordinates_.first = 1;
    first_tile_ = true;

    for (auto &val : labyrinth_map_) {
        val.resize(Labyrinth::LABYRINTH_SIZE);
    }
}

Robot::~Robot(){
    // delete sensor_;
    // delete path_algorithm_;
}

bool Robot::getWallsReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates) {

    if (robot_maze_coordinates_ == robot_maze_coordinates) {
        return false;
    }
    SensorReadings readings =
        sensor_->getReadings(labyrinth, robot_maze_coordinates, robot_direction_);

    robot_maze_coordinates_ = robot_maze_coordinates;

    convertReadingsToMap(readings);

    std::cout << "left reading: " << readings.left.front() << " front: " << readings.front.front() << " right: " <<readings.right.front() << " robot direction: " << robot_direction_ << std::endl;

    new_tile_ = true;

    return true;
}

void Robot::choosePathToRide() {
    Direction direction_to_move = path_algorithm_->makeMoveDecision(
        labyrinth_map_, robot_maze_coordinates_, robot_direction_);

    move_instructions_.push_back(direction_to_move);

    for (auto const &dir : move_instructions_) {
        std::cout << "direction " << dir << " ";
    }
    std::cout << std::endl;
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
    if (std::abs(middle_of_tile_x - robot_pose_x) <= std::max(1, static_cast<int>(std::ceil(velocity_ / 3))) &&
        std::abs(middle_of_tile_y - robot_pose_y) <= std::max(1, static_cast<int>(std::ceil(velocity_ / 3)))) {

        if (!first_tile_) {
            robot_direction_ = *std::next(move_instructions_.begin());
            move_instructions_.pop_front();
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

void Robot::setPathAlgorithm(GuiType algorithm) {
    switch (algorithm) {
        case GuiType::WALL_FOLLOWER:
            path_algorithm_ = &wall_follower_;
            break;
        case GuiType::BRUTE_FORCE:
            path_algorithm_ = &brute_force_;
            break;
        default:
            path_algorithm_ = &wall_follower_;
            break;
    }
}

void Robot::setSensor(GuiType sensor) {
    switch (sensor) {
        case GuiType::IR_SENSOR:
            sensor_ = &ir_sensor_;
            break;
        case GuiType::LASER_SCANNER:
            sensor_ = &scanner_;
            break;
        default:
            sensor_ = &ir_sensor_;
            break;
    }
}

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

void Robot::convertReadingsToMap(SensorReadings readings) {
    switch (robot_direction_) {
        case Direction::N:
            labyrinth_map_[robot_maze_coordinates_.first][robot_maze_coordinates_.second] =
                TileWalls(readings.front.front(), readings.right.front(), false, readings.left.front(), WallsType::N);
            break;
        case Direction::E:
            labyrinth_map_[robot_maze_coordinates_.first][robot_maze_coordinates_.second] =
                TileWalls(readings.left.front(), readings.front.front(), readings.right.front(), false, WallsType::E);
            break;
        case Direction::S:
            labyrinth_map_[robot_maze_coordinates_.first][robot_maze_coordinates_.second] =
                TileWalls(false, readings.left.front(), readings.front.front(), readings.right.front(), WallsType::S);
            break;
        case Direction::W:
            labyrinth_map_[robot_maze_coordinates_.first][robot_maze_coordinates_.second] =
                TileWalls(readings.right.front(), false, readings.left.front(), readings.front.front(), WallsType::W);
            break;
        default:
            labyrinth_map_[robot_maze_coordinates_.first][robot_maze_coordinates_.second] = TileWalls();
            break;
    }
}
