//
// Created by kenul on 03/Mar/2024.
//

#include "sensor-SPEED.h"

SensorSpeed::SensorSpeed() {
    speed = 0;
}

void SensorSpeed::setSpeed(float distance) {
    if (speed != 70){
        if (distance > 10){
            speed += 2;
        }
        else if (distance < 3){
            speed = 0;
        }
        else if (distance < 7){
            speed -= 2;
        }
        else if (distance > 10){
            speed -= 1;
        }
    }
}

double SensorSpeed::getSpeed(float distance) {
    setSpeed(distance);

    return speed;
}

