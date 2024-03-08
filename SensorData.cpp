//
// Created by kenul on 27/Feb/2024.
//

#include "SensorData.h"

SensorData::SensorData() {
    dateAndTime = "";
    recordID = 0;
    ultrasonicVal = 0;
    speedVal = 0;
    breakVal = false;
    latitude = 0;
    longitude = 0;
    satelliteCount = 0;
}

SensorData::SensorData(string dateTime, uint32_t id, double ultrasonic, float speed, bool breakStatus, double lat, double lon, uint32_t satCount) {
    dateAndTime = dateTime;
    recordID = id;
    ultrasonicVal = ultrasonic;
    speedVal = speed;
    breakVal = breakStatus;
    latitude = lat;
    longitude = lon;
    satelliteCount = satCount;
}

void SensorData::setRecordID(uint32_t id) {
    recordID = id;
}

void SensorData::setUltrasonicVal(float val) {
    ultrasonicVal = val;
}

void SensorData::setSpeedVal(float val) {
    speedVal = val;
}

void SensorData::setBreakVal(bool val) {
    breakVal = val;
}

void SensorData::setGPS(double lat, double lon, uint32_t satCount) {
    latitude = lat;
    longitude = lon;
    satelliteCount = satCount;
}

void SensorData::setDateAndTime(string dateTime) {
    dateAndTime = dateTime;
}

uint32_t SensorData::getRecordID() {
    return recordID;
}

double SensorData::getUltrasonicVal() {
    return ultrasonicVal;
}

float SensorData::getSpeedVal() {
    return speedVal;
}

bool SensorData::getBreakVal() {
    return breakVal;
}

double SensorData::getLatitude() {
    return latitude;
}

double SensorData::getLongitude() {
    return longitude;
}

uint32_t SensorData::getSatelliteCount() {
    return satelliteCount;
}

string SensorData::getdateAndTime() {
    return dateAndTime;
}