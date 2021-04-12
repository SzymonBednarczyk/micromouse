#ifndef SENSOR_READINGS_H
#define SENSOR_READINGS_H


class SensorReadings {
public:
    SensorReadings(bool left_reading = false,
                   bool front_reading = false,
                   bool right_reading = false);
    virtual ~SensorReadings(){}

    bool left;
    bool front;
    bool right;
};

#endif // SENSOR_READINGS_H
