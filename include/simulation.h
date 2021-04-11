#ifndef SIMULATION_H
#define SIMULATION_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "labyrinth.h"


class Simulation {
public:
    Simulation(){}
    Simulation(int maze_tile_size);
    ~Simulation();
    /**
     * @brief starts simulation and timer
     *
     */
    void start();
    /**
     * @brief stops robots simulation
     *
     * @return sf::Time - time elapsed before stop
     */
    sf::Time stop();
    std::pair<size_t, size_t> checkRobotPositionInMaze(sf::Vector2f robots_position_in_maze);
    /**
     * @brief Get time elapsed from start of clock
     *
     * @return sf::Time time elapsed
     */
    sf::Time getTimeElapsed() const;
    /**
     * @brief getter if robot reached end of labyrinth
     *
     * @return true - robot reached end
     * @return false - robot did not reached end
     */
    bool robotWon() const;
private:
    bool hasRobotReachedTarget(std::pair<size_t, size_t> coordinates);

    sf::Clock clock_;
    bool robot_won_;
    float maze_tile_size_;
};

#endif // SIMULATION_H
