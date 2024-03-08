//
// Created by kenul on 20/Feb/2024.
//

#include "sensor-BREAK.h"

sensor_Break::sensor_Break() {
    isBreak = false;
}

void sensor_Break::setBreakOn() {
    isBreak = true;
}

void sensor_Break::setBreakOff() {
    isBreak = false;
}

bool sensor_Break::getBreak() {
    return isBreak;
}