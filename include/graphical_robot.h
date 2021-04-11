#ifndef GRAPHICAL_ROBOT_H
#define GRAPHICAL_ROBOT_H

#include "robot.h"
#include "entity.h"
#include "texture_manager.h"


class Graphical_Robot : public Entity, public Robot {
public:
    Graphical_Robot();
    virtual ~Graphical_Robot(){}

    static const int DRAWING_ORIGIN_X = 310;
    static const int DRAWING_ORIGIN_Y = 320;
    static const int PIXEL_SIZE_X = 53;
    static const int PIXEL_SIZE_Y = 43;
    std::string TEXTURENAME() const;
private:
    const std::string TEXTURE_NAME_ = "robot";
};

#endif // GRAPHICAL_ROBOT_H
