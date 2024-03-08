//
// Created by kenul on 27/Feb/2024.
//

#ifndef DRAFTTWO_SENSORDATA_H
#define DRAFTTWO_SENSORDATA_H

#include <iostream>
#include <cstdint>

using namespace std;

class SensorData {
private:
    string dateAndTime;
    uint32_t recordID;
    double ultrasonicVal;
    float speedVal;
    bool breakVal;
    double latitude;
    double longitude;
    uint32_t satelliteCount;

public:
    SensorData();
    SensorData(string, uint32_t, double, float, bool, double, double, uint32_t);
    void setRecordID(uint32_t);
    void setUltrasonicVal(float);
    void setSpeedVal(float);
    void setBreakVal(bool);
    void setGPS(double, double, uint32_t);
    void setDateAndTime(string);

    uint32_t getRecordID();
    double getUltrasonicVal();
    float getSpeedVal();
    bool getBreakVal();
    double getLatitude();
    double getLongitude();
    uint32_t getSatelliteCount();
    string getdateAndTime();
};

#endif //DRAFTTWO_SENSORDATA_H
