//
// Created by kenul on 19/Feb/2024.
//

#ifndef DRAFTTWO_MODEL_H
#define DRAFTTWO_MODEL_H

#include <iostream>

#include "sensor-ULTRASONIC.h"
#include "sensor-GPS.h"
#include "sensor-SPEED.h"
#include "sensor-BREAK.h"

class Model {
private:
    sensor_ultrasonic ultrasonic;
    sensor_GPS gps;
    SensorSpeed speed;
    sensor_Break breaks;

    float distance;

public:
    float getUltrasonic();
    double getSpeed();
    double getLatitude();
    double getLongitude();
    uint32_t getSatelliteCount();
    bool getBreak();
    void setBreak(bool);
};


#endif //DRAFTTWO_MODEL_H
