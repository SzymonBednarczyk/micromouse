#include "graphical_simulation.h"

// public
GraphicalSimulation::GraphicalSimulation(){
    initVariables();
    initWindow();
}

GraphicalSimulation::~GraphicalSimulation() {
    delete window_;
}

void GraphicalSimulation::update() {
    pollEvents();
}

void GraphicalSimulation::render() {
    // clear window
    window_->clear(sf::Color(0, 0, 0, 255));
    // draw objects
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