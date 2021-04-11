#include "graphical_simulation.h"

// public
GraphicalSimulation::GraphicalSimulation(){
    initVariables();
    initWindow();
    loadTextures();
    graphical_labyrinth_.setSprites(&tex_manager_);
    graphical_robot_.setSprite(&tex_manager_);
}

GraphicalSimulation::~GraphicalSimulation() {
    delete window_;
}

void GraphicalSimulation::update() {
    pollEvents();
}

void GraphicalSimulation::render() {
    // clear window
    window_->clear(sf::Color(255, 255, 255, 255));

    // draw objects
    graphical_labyrinth_.draw(window_);
    graphical_robot_.draw(window_);
    window_->display();
}

const bool GraphicalSimulation::getWindowIsOpen() const {
    return window_->isOpen();
}
// private
void GraphicalSimulation::initVariables() {
    window_ = nullptr;
}

void GraphicalSimulation::initWindow() {
    video_mode_.height = 760;
    video_mode_.width = 1024;
    window_ = new sf::RenderWindow(video_mode_, "Micromouse", sf::Style::Titlebar | sf::Style::Close);
    window_->setPosition(sf::Vector2i(1500, 100));
    window_->setFramerateLimit(1);

}

void GraphicalSimulation::pollEvents() {
    while (window_->pollEvent(ev_))
        {
            switch (ev_.type)
            {
            case sf::Event::Closed:
                window_->close();
                break;
            case sf::Event::KeyPressed:
                if (ev_.key.code == sf::Keyboard::Escape)
                {
                    window_->close();
                }
                break;
            }
        }
}

void GraphicalSimulation::loadTextures() {
    // Labyrinth
    tex_manager_.loadTexture("tile_E", "graphic_models/walls_E.png");
    tex_manager_.loadTexture("tile_ES", "graphic_models/walls_ES.png");
    tex_manager_.loadTexture("tile_ESW", "graphic_models/walls_ESW.png");
    tex_manager_.loadTexture("tile_EW", "graphic_models/walls_EW.png");
    tex_manager_.loadTexture("tile_N", "graphic_models/walls_N.png");
    tex_manager_.loadTexture("tile_NE", "graphic_models/walls_NE.png");
    tex_manager_.loadTexture("tile_NES", "graphic_models/walls_NES.png");
    tex_manager_.loadTexture("tile_NEW", "graphic_models/walls_NEW.png");
    tex_manager_.loadTexture("tile_NS", "graphic_models/walls_NS.png");
    tex_manager_.loadTexture("tile_NSW", "graphic_models/walls_NSW.png");
    tex_manager_.loadTexture("tile_NW", "graphic_models/walls_NW.png");
    tex_manager_.loadTexture("tile_S", "graphic_models/walls_S.png");
    tex_manager_.loadTexture("tile_SW", "graphic_models/walls_SW.png");
    tex_manager_.loadTexture("tile_W", "graphic_models/walls_W.png");
    // Robot
    tex_manager_.loadTexture("robot", "graphic_models/robot.png");
}