//
// Created by kenul on 19/Feb/2024.
//

#ifndef DRAFTTWO_SENSOR_ULTRASONIC_H
#define DRAFTTWO_SENSOR_ULTRASONIC_H

#include <iostream>
#include <random>

class sensor_ultrasonic {
private:
    float duration;
    float distance;
    const float speedOfSound = 0.034;

    uint32_t minDistance;
    uint32_t maxDistance;

    void durationSimulation();
    void calDistance();
    double randomGenerator(double, double);

public:
    sensor_ultrasonic();
    float setDistance();
};

#endif //DRAFTTWO_SENSOR_ULTRASONIC_H
