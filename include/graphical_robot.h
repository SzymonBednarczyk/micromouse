#ifndef GRAPHICAL_ROBOT_H
#define GRAPHICAL_ROBOT_H

#include "robot.h"
#include "entity.h"
#include "texture_manager.h"
#include "labyrinth.h"


class GraphicalRobot : public Entity {
public:
    GraphicalRobot();
    virtual ~GraphicalRobot(){}

    static const int DRAWING_ORIGIN_X = 337;
    static const int DRAWING_ORIGIN_Y = 342;
    static const int PIXEL_SIZE_X = 53;
    static const int PIXEL_SIZE_Y = 43;
    std::string textureName() const;
    bool updateRobotReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates);
    void choosePathToRide();
    sf::Vector2f getRobotVelocity();
private:
    const std::string texture_name_ = "robot";
    Robot robot_;
};

#endif // GRAPHICAL_ROBOT_H
