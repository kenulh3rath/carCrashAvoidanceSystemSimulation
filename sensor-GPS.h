//
// Created by kenul on 19/Feb/2024.
//

#ifndef DRAFTTWO_SENSOR_GPS_H
#define DRAFTTWO_SENSOR_GPS_H

#include <iostream>
#include <random>

using namespace std;

class sensor_GPS {
private:
    double latitude;
    double longitude;
    uint32_t numOfSatellites;

public:
    sensor_GPS();
    void setValues();
    void setsatelliteCount();
    static double randomGenerator(int32_t, int32_t);

    double getLatitude();
    double getLongitude();
    uint32_t getSatteliteCount();


};

#endif //DRAFTTWO_SENSOR_GPS_H
