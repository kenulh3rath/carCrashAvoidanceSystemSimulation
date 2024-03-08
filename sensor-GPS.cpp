//
// Created by kenul on 19/Feb/2024.
//

#include "sensor-GPS.h"

sensor_GPS::sensor_GPS() {
//    latitude = -16.998732;
//    longitude = -139.633455;

    latitude = randomGenerator(-90, 90);
    longitude = randomGenerator(-180, 180);

    numOfSatellites = 0;
}

void sensor_GPS::setValues() {
    // -90 to 90
    // -180 to 180
    if (latitude > 90) latitude = -90;
    if (latitude < -90) latitude = 90;
    if (longitude > 180) longitude = -180;
    if (longitude < -180) longitude = 180;

    latitude += randomGenerator(1, 5);
    longitude += randomGenerator(1, 5);
}

void sensor_GPS::setsatelliteCount() {
    numOfSatellites = randomGenerator(1, 12);
}

double sensor_GPS::randomGenerator(int32_t min, int32_t max) {
    random_device rd;  // Obtain a random number from hardware
    mt19937 gen(rd()); // Seed the random number generator
    uniform_real_distribution<double> dis(min, max); // Define the range

    return dis(gen);
}

double sensor_GPS::getLatitude() {
    setValues();

    return latitude;
}

double sensor_GPS::getLongitude() {
    setValues();

    return -(longitude);
}

uint32_t sensor_GPS::getSatteliteCount() {
    setsatelliteCount();

    return numOfSatellites;
}

