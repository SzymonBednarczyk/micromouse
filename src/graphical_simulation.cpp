#include "graphical_simulation.h"

// public
GraphicalSimulation::GraphicalSimulation() {
    input_text_ = false;
    frame_limit_ = 60;
    initVariables();
    initWindow();
    loadTextures();
    loadFonts();
    loadStylesheets();
    createGui();

    graphical_labyrinth_.loadEntity(&tex_manager_);

    graphical_robot_.load(sf::Vector2u(GraphicalRobot::PIXEL_SIZE_X,
                                       GraphicalRobot::PIXEL_SIZE_Y),
                          tex_manager_.getTextureRef(
                              graphical_robot_.textureName()));
    simulation_ = Simulation(LabyrinthTile::TILE_PIXEL_SIZE);
}

GraphicalSimulation::~GraphicalSimulation() {
    delete window_;
}

void GraphicalSimulation::update() {
    pollEvents();
    // pose relative to left bottom tile left bottom vertex of maze
    if (simulation_.started()) {
        sf::Vector2f robot_relative_pose = sf::Vector2f(
            graphical_robot_.getPosition().x - GraphicalLabyrinth::DRAWING_ORIGIN_X,
            GraphicalLabyrinth::DRAWING_ORIGIN_Y + LabyrinthTile::TILE_PIXEL_SIZE - graphical_robot_.getPosition().y);

        std::pair<size_t, size_t> robot_maze_coordinates =
            simulation_.checkRobotPositionInMaze(robot_relative_pose);


        if(simulation_.robotWon()) {
            announcement_ = "ROBOT WON!";
            guis_.at("announcements").setEntryText(0, announcement_);
            guis_.at("announcements").show();
            std::cout << "ROBOT WON IN " << simulation_.stop().asSeconds() << "SECONDS" << std::endl;
        } else{
            if (graphical_robot_.updateRobotReadings(
                graphical_labyrinth_.labirynth(), robot_maze_coordinates)) {

                graphical_robot_.choosePathToRide();
            }
            if (graphical_robot_.changeDirection(robot_relative_pose)) {
                graphical_robot_.changeAnimation();
            }

            graphical_robot_.move(graphical_robot_.getRobotVelocity());
        }

        guis_.at("info_bar").setEntryText(1, simulation_.getTimeElapsed());
    }

    guis_.at("main_menu").setEntryText(4, player_text_.getString().toAnsiString());
}

void GraphicalSimulation::render() {
    // clear window
    window_->clear(sf::Color(150, 255, 255, 0));

    // draw objects
    graphical_labyrinth_.draw(window_);
    window_->draw(graphical_robot_);
    // draw GUIs
    for(auto &gui : guis_) {
        window_->draw(gui.second);
    }
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
    video_mode_.height = 900;
    video_mode_.width = 1024;
    window_ = new sf::RenderWindow(video_mode_, "Micromouse", sf::Style::Titlebar | sf::Style::Close);
    window_->setPosition(sf::Vector2i(200, 200));
    window_->setFramerateLimit(frame_limit_);

}

void GraphicalSimulation::pollEvents() {
    sf::Vector2f mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window_));
    // std::cout << "Mouse position X: " << mouse_position.x << " Y: " << mouse_position.y <<std::endl;

    while (window_->pollEvent(ev_)) {
        switch (ev_.type) {
            // close window
            case sf::Event::Closed:
                window_->close();
                break;
            case sf::Event::KeyPressed:
                if (ev_.key.code == sf::Keyboard::Escape) {
                    window_->close();
                }
                break;
            // enter text
            case sf::Event::TextEntered:
                if (input_text_) {
                    if (ev_.text.unicode == '\b') {
                        if (player_input_.size() > 0) {
                            player_input_.erase(player_input_.size() - 1, 1);
                        }
                    }
                    else if (ev_.text.unicode < 128)
                        player_input_ += static_cast<char>(ev_.text.unicode);
                    player_text_.setString(player_input_);
                }
                break;
            // mouse moved
            case sf::Event::MouseMoved:
                guis_.at("main_menu").highlight(
                    guis_.at("main_menu").getEntry(mouse_position));
                break;
            // mouse button pressed
            case sf::Event::MouseButtonPressed:
                if(ev_.mouseButton.button == sf::Mouse::Left) {
                    GuiType gui_button_pressed;

                    if (guis_.at("sensors").visible()) {
                        gui_button_pressed =
                            guis_.at("sensors").activate(mouse_position);

                        handleSensorButtonPressed(gui_button_pressed);
                    }

                    if (guis_.at("path_algorithm").visible()) {
                        gui_button_pressed =
                            guis_.at("path_algorithm").activate(mouse_position);

                        handlePathAlgorithmButtonPressed(gui_button_pressed);
                    }

                    gui_button_pressed =
                        guis_.at("main_menu").activate(mouse_position);

                    if (gui_button_pressed != GuiType::NONE) {
                        handleGuiButtonPressed(gui_button_pressed);
                    } else {
                        input_text_ = false;
                    }
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
    tex_manager_.loadTexture("tile_NESW", "graphic_models/walls_NESW.png");
    tex_manager_.loadTexture("tile_NONE", "graphic_models/walls_NONE.png");
    // Robot
    tex_manager_.loadTexture("robot", "graphic_models/robot_sprite.png");
}

void GraphicalSimulation::loadFonts() {
    sf::Font font;
    font.loadFromFile("graphic_models/font.ttf");
    fonts_["main_font"] = font;
    player_text_.setFont(fonts_.at("main_font"));
    player_text_.setCharacterSize(10);
    player_text_.setPosition(1.f, 1.f);
    player_text_.setFillColor(sf::Color::Black);
}

void GraphicalSimulation::loadStylesheets() {

    stylesheets_["button"] = GuiStyle(&fonts_.at("main_font"), 1,
        sf::Color(0xc6,0xc6,0xc6), sf::Color(0x94,0x94,0x94), sf::Color(0x00,0x00,0x00),
        sf::Color(0x61,0x61,0x61), sf::Color(0x94,0x94,0x94), sf::Color(0x00,0x00,0x00));
    stylesheets_["text"] = GuiStyle(&fonts_.at("main_font"), 0,
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0x00,0x00,0x00),
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0xff,0x00,0x00));
    stylesheets_["announcements"] = GuiStyle(&fonts_.at("main_font"), 0,
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0xff,0x00,0x00),
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0xff,0x00,0x00));
}

void GraphicalSimulation::createGui() {
    guis_.emplace("main_menu", Gui(sf::Vector2f(140, 20), 4, false, stylesheets_.at("button"),
        {std::make_pair("START", GuiType::START),
         std::make_pair("STOP", GuiType::STOP),
         std::make_pair("SENSORS", GuiType::SENSORS),
         std::make_pair("PATH_ALGORITHMS", GuiType::PATH_ALGORITHMS),
         std::make_pair("TEXT", GuiType::TEXT),
         std::make_pair("SAVE", GuiType::SAVE),
         std::make_pair("LOAD FROM FILE", GuiType::LOAD)}));

    guis_.emplace("info_bar", Gui(sf::Vector2f(130, 20), 4, true, stylesheets_.at("text"),
        {std::make_pair("Time elapsed:", GuiType::TEXT),
         std::make_pair("0", GuiType::TEXT)}));

    guis_.emplace("announcements", Gui(sf::Vector2f(230, 50), 4, true, stylesheets_.at("announcements"),
        {std::make_pair(announcement_, GuiType::TEXT)}));

    guis_.emplace("path_algorithm", Gui(sf::Vector2f(140, 20), 4, true, stylesheets_.at("button"),
        {std::make_pair("BRUTE_FORCE", GuiType::BRUTE_FORCE),
         std::make_pair("WALL_FOLLOWER", GuiType::WALL_FOLLOWER)}));

    guis_.emplace("sensors", Gui(sf::Vector2f(140, 20), 4, true, stylesheets_.at("button"),
        {std::make_pair("IR SENSOR", GuiType::IR_SENSOR),
         std::make_pair("LASER SCANNER", GuiType::LASER_SCANNER)}));

    guis_.at("main_menu").setPosition(1.f, 1.f);
    guis_.at("main_menu").show();
    guis_.at("info_bar").setPosition(window_->getSize().x / 2 - guis_.at("info_bar").getSize().x / 2, 0.f);
    guis_.at("info_bar").show();
    guis_.at("announcements").setPosition(window_->getSize().x / 2 - 140, 40);
    guis_.at("announcements").hide();
    guis_.at("path_algorithm").setPosition(
        guis_.at("main_menu").getSize().x,
        guis_.at("main_menu").getPosition().y + guis_.at("main_menu").getSize().y / guis_.at("main_menu").entries().size() * 3);
    guis_.at("path_algorithm").highlight(1);
    guis_.at("path_algorithm").hide();
    guis_.at("sensors").setPosition(
        guis_.at("main_menu").getSize().x,
        guis_.at("main_menu").getPosition().y + guis_.at("main_menu").getSize().y / guis_.at("main_menu").entries().size() * 2);
    guis_.at("sensors").highlight(0);
    guis_.at("sensors").hide();

}

void GraphicalSimulation::handleGuiButtonPressed(GuiType gui_button) {

    switch (gui_button) {
        case GuiType::NONE:
            input_text_ = false;
            std::cout << gui_button << " pressed" <<std::endl;
            break;
        case GuiType::START:
            simulation_.start();
            input_text_ = false;
            std::cout << gui_button << " pressed" <<std::endl;
            break;
        case GuiType::STOP:
            simulation_.stop();
            input_text_ = false;
            std::cout << gui_button << " pressed" <<std::endl;
            break;
        case GuiType::SENSORS:
            input_text_ = false;
            guis_.at("sensors").show();
            std::cout << gui_button << " pressed" <<std::endl;
            break;
        case GuiType::PATH_ALGORITHMS:
            input_text_ = false;
            guis_.at("path_algorithm").show();
            std::cout << gui_button << " pressed" <<std::endl;
            break;
        case GuiType::SAVE:
            input_text_ = false;
            graphical_labyrinth_.saveLabyrinthToFile(player_input_);
            std::cout << gui_button << " pressed" <<std::endl;
            break;
        case GuiType::LOAD:
            input_text_ = false;

            if(graphical_labyrinth_.loadLabyrinthFromFile(player_input_)) {
                graphical_labyrinth_.loadEntity(&tex_manager_);
            }
            std::cout << gui_button << " pressed" <<std::endl;
            break;
        case GuiType::TEXT:
            input_text_ = true;
            std::cout << gui_button << " pressed" <<std::endl;
            break;
        default:
            input_text_ = false;
            break;
    }
}

void GraphicalSimulation::handlePathAlgorithmButtonPressed(GuiType path_algorithm) {

    switch (path_algorithm) {
        case GuiType::NONE:
            guis_.at("path_algorithm").hide();
            std::cout << path_algorithm << " pressed" <<std::endl;
            break;
        case GuiType::BRUTE_FORCE:
            guis_.at("path_algorithm").highlight(0);
            graphical_robot_.setPathAlgorithm(path_algorithm);
            std::cout << path_algorithm << " pressed" <<std::endl;
            break;
        case GuiType::WALL_FOLLOWER:
            guis_.at("path_algorithm").highlight(1);
            graphical_robot_.setPathAlgorithm(path_algorithm);
            std::cout << path_algorithm << " pressed" <<std::endl;
            break;
    }
}

void GraphicalSimulation::handleSensorButtonPressed(GuiType sensors_button) {

    switch (sensors_button) {
        case GuiType::NONE:
            guis_.at("sensors").hide();
            std::cout << sensors_button << " pressed" <<std::endl;
            break;
        case GuiType::IR_SENSOR:
            guis_.at("sensors").highlight(0);
            graphical_robot_.setSensor(sensors_button);
            std::cout << sensors_button << " pressed" <<std::endl;
            break;
        case GuiType::LASER_SCANNER:
            guis_.at("sensors").highlight(1);
            graphical_robot_.setSensor(sensors_button);
            std::cout << sensors_button << " pressed" <<std::endl;
            break;
    }
}