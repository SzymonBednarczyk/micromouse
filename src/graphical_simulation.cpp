#include "graphical_simulation.h"

// public
GraphicalSimulation::GraphicalSimulation() {
    initVariables();
    initWindow();
    loadTextures();
    graphical_labyrinth_.loadEntity(&tex_manager_);
    graphical_robot_.load(sf::Vector2u(GraphicalRobot::PIXEL_SIZE_X,
                                       GraphicalRobot::PIXEL_SIZE_Y),
                          tex_manager_.getTextureRef(
                              graphical_robot_.textureName()));
    simulation_ = Simulation(LabyrinthTile::TILE_PIXEL_SIZE);
    simulation_.start();
}

GraphicalSimulation::~GraphicalSimulation() {
    delete window_;
}

void GraphicalSimulation::update() {
    pollEvents();
    // pose relative to left bottom tile left bottom vertex of maze
    sf::Vector2f robot_relative_pose = sf::Vector2f(
        graphical_robot_.getPosition().x - GraphicalLabyrinth::DRAWING_ORIGIN_X,
        GraphicalLabyrinth::DRAWING_ORIGIN_Y + LabyrinthTile::TILE_PIXEL_SIZE - graphical_robot_.getPosition().y);

    std::pair<size_t, size_t> robot_maze_coordinates =
        simulation_.checkRobotPositionInMaze(robot_relative_pose);

    if (robot_maze_coordinates.second == 2)
        graphical_robot_.move(10.0f, 0.f);
    else
        graphical_robot_.move(0.0f, -10.f);
}

void GraphicalSimulation::render() {
    // clear window
    window_->clear(sf::Color(255, 255, 255, 255));

    // draw objects
    graphical_labyrinth_.draw(window_);
    window_->draw(graphical_robot_);
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
    window_->setPosition(sf::Vector2i(2000, 200));
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