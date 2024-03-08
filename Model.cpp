//
// Created by kenul on 19/Feb/2024.
//

#include "Model.h"

float Model::getUltrasonic() {
    distance = ultrasonic.setDistance();
    return distance;
}

double Model::getSpeed() {
    return speed.getSpeed(distance);
}

double Model::getLatitude() {
    return gps.getLatitude();
}

double Model::getLongitude() {
    return gps.getLongitude();
}

uint32_t Model::getSatelliteCount() {
    return gps.getSatteliteCount();
}

bool Model::getBreak() {
    return breaks.getBreak();
}

void Model::setBreak(bool isBreak) {
    if (isBreak){
        breaks.setBreakOn();
    }
    else{
        breaks.setBreakOff();
    }
}