#include "simulation.h"

Simulation::Simulation(int maze_tile_size) {
    clock_.restart();
    robot_won_ = false;
    maze_tile_size_ = static_cast<float>(maze_tile_size);
}

Simulation::~Simulation() {
}

void Simulation::start() {
    clock_.restart();
}

sf::Time Simulation::stop() {
    return clock_.restart();;
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

sf::Time Simulation::getTimeElapsed() const {
    return clock_.getElapsedTime();
}

bool Simulation::robotWon() const { return robot_won_; }

bool Simulation::hasRobotReachedTarget(std::pair<size_t, size_t> coordinates) {
    if (coordinates.second == Labyrinth::LABYRINTH_SIZE - 1 &&
        coordinates.first == Labyrinth::LABYRINTH_SIZE - 1) {

        return true;
    }

    return false;
}

