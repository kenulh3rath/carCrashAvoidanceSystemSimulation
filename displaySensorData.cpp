//
// Created by kenul on 29/Feb/2024.
//

#include "displaySensorData.h"

// Display Record ID of the drive
void DisplaySensorData::displayRecordID(uint32_t recordID) {
    cout << "Record : " << recordID << endl;
}

// Display Ultrasonic Values
void DisplaySensorData::displayUltrasonicValues(float ultrasonic) {
    cout << "Distance Between: "
         << fixed << setprecision(2)
         << ultrasonic << "cm" << endl;

    displayWarnings.ultrasonicDistanceWarning(ultrasonic);
}

// Display Speed Values
void DisplaySensorData::displaySpeedValues(float speed) {
    cout << "Speed: " << fixed << setprecision(2) << speed << "km/h" << endl;
}

// Display GPS Values
void DisplaySensorData::displayGPSValues(double latitude, double longitude, uint32_t satelliteCount) {
    cout << "Latitude: " << fixed << setprecision(6) << latitude << endl;
    cout << "Longitude: " << fixed << setprecision(6) << longitude << endl;
    cout << "Satellite Count: " << satelliteCount << endl << endl;
}