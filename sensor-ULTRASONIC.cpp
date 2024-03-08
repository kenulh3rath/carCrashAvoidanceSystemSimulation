//
// Created by kenul on 19/Feb/2024.
//

#include "sensor-ULTRASONIC.h"

using namespace std;

sensor_ultrasonic::sensor_ultrasonic() {
    minDistance = 1;
    maxDistance = 8000;
    durationSimulation();

}

void sensor_ultrasonic::calDistance() {

    distance = (duration * speedOfSound) / 2;

    duration = duration + randomGenerator(-500, 500);

    if (distance <= 0)
    {
        distance = 0;
        duration = randomGenerator(minDistance, maxDistance);
    }
}

void sensor_ultrasonic::durationSimulation() {
    duration = randomGenerator(minDistance, maxDistance);
}

double  sensor_ultrasonic::randomGenerator(double min, double max) {
    random_device rd;  // Obtain a random number from hardware
    mt19937 gen(rd()); // Seed the random number generator
    uniform_real_distribution<double> dis(min, max); // Define the range
    return dis(gen);
}

float sensor_ultrasonic::setDistance() {
    calDistance();
    return distance;
}