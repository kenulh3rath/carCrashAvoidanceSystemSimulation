//
// Created by kenul on 19/Feb/2024.
//

#ifndef DRAFTTWO_VIEW_H
#define DRAFTTWO_VIEW_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "userInput.h"
#include "displayMenu.h"
#include "displayWarnings.h"
#include "displayVehicleData.h"
#include "displayUserData.h"
#include "displaySensorData.h"
#include "inputValidation.h"

using namespace std;

class View {
private:
    UserInput userInput;
    DisplayMenu displayMenu;
    DisplayWarnings displayWarnings;
    DisplayVehicleData displayVehicleData;
    DisplayUserData displayUserData;
    DisplaySensorData displaySensorData;
    InputValidation inputValidation;


public:

    uint32_t loginMenu();
    uint32_t addUserMenu();
    uint32_t dropUserMenu();

    void invalidChoiceWarning();
    void noAccessWarning(string);
    void drivingStopped();

    void vehicleDescription();
    void sensorDescription();

    void displayRecordID(uint32_t);
    void displayUltrasonicValues(float);
    void displaySpeedValues(float);
    void ultrasonicDistanceWarning(float);
    void displayGPSValues(double, double, uint32_t);
    void displayBreakStatus(bool);

    void logginSuccess(string, string);
    void invalidCredentials();
    void passengerAdded();
    void passengerDropped();
    void passengerNotExists(string);
    void passengersHeader();
    void passengerDetails(string, string, string);

    string getfirstName();
    string getlastName();
    string getRole();
    string getUserUsername();
    string getUserPassword();
};

#endif //DRAFTTWO_VIEW_H
