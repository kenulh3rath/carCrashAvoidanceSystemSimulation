//
// Created by kenul on 29/Feb/2024.
//

#include "displayVehicleData.h"

// Vehicle Description
void DisplayVehicleData::vehicleDescription() {
    cout << "-----Mitsubishi Outlander SE 2022-----" << endl;
    cout << "-> 2.5L 4-cylinder engine" << endl;
    cout << "-> 8-speed CVT transmission" << endl;
    cout << "-> 11.6 kWh battery" << endl;
    cout << "-> 24 miles electric range" << endl;
    cout << "-> 74 MPGe" << endl;
    cout << "-> 30/31 mpg" << endl;
    cout << "-> 7 passenger seating" << endl;
    cout << "-> 10.8 inch infotainment screen" << endl;
    cout << "-> 12.3 inch digital gauge cluster" << endl;
    cout << "-> 9 speaker Bose sound system" << endl;
    cout << "-> 360 degree camera" << endl;
    cout << "-> 10 airbags" << endl;
    cout << "-> 3 year/36,000 mile warranty" << endl << endl;
}

// Sensor Description
void DisplayVehicleData::sensorDescription() {
    cout << "-----Ultrasonic Sensor-----" << endl;
    cout << "Ultrasonic sensors are used to detect objects and measure \n"
            "distances. It emits a sound wave and then listens for the \n"
            "echo. The sensor measures the time it takes for the echo \n"
            "to arrive, and uses this information to calculate the distance \n"
            "to the object. Ultrasonic sensors are commonly used in robotics, \n"
            "security systems, and industrial automation. They are also used \n"
            "in cars to assist with parking and collision avoidance." << endl << endl;

    cout << "-----GPS Sensor-----" << endl;
    cout << "GPS sensors are used to determine the location of an object. \n"
            "They work by receiving signals from satellites and using this \n"
            "information to calculate the object's position. GPS sensors are \n"
            "commonly used in navigation systems, mapping applications, and \n"
            "location-based services. They are also used in cars to provide \n"
            "directions and track the vehicle's location." << endl << endl;

    cout << "-----Break Sensor-----" << endl;
    cout << "Break sensors are used to detect when a vehicle's breaks are \n"
            "applied. They work by measuring the pressure applied to the \n"
            "break pedal and using this information to determine if the \n"
            "breaks are engaged. Break sensors are commonly used in cars to \n"
            "activate the break lights and alert other drivers when the \n"
            "vehicle is slowing down or stopping." << endl << endl << endl;
}