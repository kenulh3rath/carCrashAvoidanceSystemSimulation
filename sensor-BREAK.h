//
// Created by kenul on 20/Feb/2024.
//

#ifndef DRAFTTWO_SENSOR_BREAK_H
#define DRAFTTWO_SENSOR_BREAK_H

#include <iostream>

using namespace std;

class sensor_Break {
private:
    bool isBreak;

public:
    sensor_Break();
    void setBreakOff();
    void setBreakOn();

    bool getBreak();
};

#endif //DRAFTTWO_SENSOR_BREAK_H
