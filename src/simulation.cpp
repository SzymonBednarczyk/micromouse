#include "simulation.h"

Simulation::Simulation(int maze_tile_size) {
    robot_won_ = false;
    maze_tile_size_ = static_cast<float>(maze_tile_size);
    started_ = false;
}

Simulation::~Simulation() {
}

void Simulation::start() {
    started_ = true;
    clock_.restart();
}

sf::Time Simulation::stop() {
    started_ = false;
    return clock_.getElapsedTime();
}

std::pair<size_t, size_t>
Simulation::checkRobotPositionInMaze(sf::Vector2f robots_position_in_maze) {
    std::pair<size_t, size_t> coordinate_in_maze;

    // X, second parameter in labyrinth table
    coordinate_in_maze.second =
        static_cast<int>(robots_position_in_maze.x / maze_tile_size_);
    // Y, first parameter in labyrinth table
    coordinate_in_maze.first =
        static_cast<int>(robots_position_in_maze.y / maze_tile_size_);
    std::cout << "Coordinate in maze: X: " << coordinate_in_maze.second <<" Y: " << coordinate_in_maze.first << std::endl;

    robot_won_ = hasRobotReachedTarget(coordinate_in_maze);

    return coordinate_in_maze;
}

std::string Simulation::getTimeElapsed() const {
    return std::to_string(static_cast<int>(clock_.getElapsedTime().asSeconds()));
}

bool Simulation::robotWon() const { return robot_won_; }

bool Simulation::started() const { return started_; }

bool Simulation::hasRobotReachedTarget(std::pair<size_t, size_t> coordinates) {
    if (coordinates.second == Labyrinth::LABYRINTH_SIZE - 1 &&
        coordinates.first == Labyrinth::LABYRINTH_SIZE - 1) {

        return true;
    }

    return false;
}

