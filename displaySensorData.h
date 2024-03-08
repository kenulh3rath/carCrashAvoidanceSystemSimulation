//
// Created by kenul on 29/Feb/2024.
//

#ifndef DRAFTTWO_DISPLAYSENSORDATA_H
#define DRAFTTWO_DISPLAYSENSORDATA_H

#include <iostream>
#include <iomanip>
#include <cstdint>

#include "displayWarnings.h"

using namespace std;

class DisplaySensorData {
private:
    DisplayWarnings displayWarnings;

public:
    void displayRecordID(uint32_t);
    void displayUltrasonicValues(float);
    void displaySpeedValues(float);
    void displayGPSValues(double, double, uint32_t);
};

#endif //DRAFTTWO_DISPLAYSENSORDATA_H
