#include "robot.h"

Robot::Robot() {
    robot_direction_ = RobotDirection::N;
    sensor_ = &ir_sensor_;
}

void Robot::getWallsReadings(
        Labyrinth* labyrinth, const std::pair<size_t, size_t> &robot_maze_coordinates) {
    SensorReadings readings =
        sensor_->getReadings(labyrinth, robot_maze_coordinates, robot_direction_);
    std::cout << "left reading: " << readings.left << " front: " << readings.front << " right: " <<readings.right << std::endl;
}
