#ifndef GRAPHICALSIMULATION_H
#define GRAPHICALSIMULATION_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "graphical_labyrinth.h"
#include "graphical_robot.h"
#include "texture_manager.h"
#include "simulation.h"
#include "gui.h"

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
    void loadFonts();
    void loadStylesheets();
    void createGui();
    void handleGuiButtonPressed(GuiType gui_button);
    void handlePathAlgorithmButtonPressed(GuiType path_algorithm);
    void handleSensorButtonPressed(GuiType sensors_button);

    bool input_text_;
    sf::RenderWindow* window_;
    sf::Event ev_;
    sf::VideoMode video_mode_;
    TextureManager tex_manager_;
    GraphicalLabyrinth graphical_labyrinth_;
    GraphicalRobot graphical_robot_;
    Simulation simulation_;
    std::map<std::string, GuiStyle> stylesheets_;
    std::map<std::string, sf::Font> fonts_;
    std::map<std::string, Gui> guis_;
    std::string player_input_;
    sf::Text player_text_;
    std::string announcement_;
    unsigned int frame_limit_;
};

#endif