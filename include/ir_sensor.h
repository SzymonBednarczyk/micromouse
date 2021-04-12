#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#include "sensor.h"
#include <iostream>


class IrSensor : public Sensor {
public:
    IrSensor();
    ~IrSensor();
    SensorReadings getReadings(Labyrinth* labyrinth,
                               std::pair<size_t, size_t> robot_pose,
                               Direction robot_direction);
private:

};

#endif // IR_SENSOR_H
