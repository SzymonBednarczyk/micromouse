#ifndef GRAPHICALSIMULATION_H
#define GRAPHICALSIMULATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "graphical_labyrinth.h"
#include "graphical_robot.h"
#include "texture_manager.h"

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
    void loadTextures();

    sf::RenderWindow* window_;
    sf::Event ev_;
    sf::VideoMode video_mode_;
    TextureManager tex_manager_;
    GraphicalLabyrinth graphical_labyrinth_;
    Graphical_Robot graphical_robot_;
};

#endif