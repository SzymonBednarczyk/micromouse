#ifndef ROBOT_H
#define ROBOT_H


class Robot {
public:
    enum class Direction {N = 0, E, S, W};

    Robot();
    virtual ~Robot(){}
private:
    Direction robot_direction_;
};

#endif // ROBOT_H
