//
// Created by kenul on 03/Mar/2024.
//

#ifndef DRAFTTWO_SENSOR_SPEED_H
#define DRAFTTWO_SENSOR_SPEED_H

#include <iostream>

using namespace std;

class SensorSpeed {
    double speed;

public:
    SensorSpeed();
    void setSpeed(float);

    double getSpeed(float);
};

#endif //DRAFTTWO_SENSOR_SPEED_H
