#ifndef GRAPHICALSIMULATION_H
#define GRAPHICALSIMULATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "labyrinth_tile.h"

class GraphicalSimulation {
public:
    GraphicalSimulation();
    virtual ~GraphicalSimulation();
    /**
     * @brief function for updating logic
     *
     */
    void update();
    /**
     * @brief function for drawing on screen
     *
     */
    void render();
    const bool getWindowIsOpen() const;

private:
    void initVariables();
    void initWindow();
    void pollEvents();

    sf::RenderWindow* window_;
    sf::Event ev_;
    sf::VideoMode video_mode_;
    LabyrinthTile tiles_ [3][3];
};

#endif