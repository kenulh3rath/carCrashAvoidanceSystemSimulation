//
// Created by kenul on 19/Feb/2024.
//

#include "View.h"

using namespace std;

// Lgin Menu
uint32_t View::loginMenu() {
    return displayMenu.loginMenu();
}

// Main Menu
uint32_t View::addUserMenu() {
    return displayMenu.addUserMenu();
}

// Passenger Menu
uint32_t View::dropUserMenu() {
    return displayMenu.dropUserMenu();
}

// User invalid choice warning message
void View::invalidChoiceWarning() {
    displayWarnings.invalidChoiceWarning();
}

// No access warnging message
void View::noAccessWarning(string warningMessage) {
    displayWarnings.noAccessWarning(warningMessage);
}

// Driving Stopped message
void View::drivingStopped() {
    displayWarnings.drivingStopped();
}

// Vehicle Description
void View::vehicleDescription() {
    displayVehicleData.vehicleDescription();
}

// Sensor Description
void View::sensorDescription() {
    displayVehicleData.sensorDescription();
}

// Display Record ID of the drive
void View::displayRecordID(uint32_t recordID) {
    displaySensorData.displayRecordID(recordID);
}

// Display Ultrasonic Values
void View::displayUltrasonicValues(float ultrasonic) {
    displaySensorData.displayUltrasonicValues(ultrasonic);
}

// Display Speed Values
void View::displaySpeedValues(float speed) {
    displaySensorData.displaySpeedValues(speed);
}

// Display distance warning
void View::ultrasonicDistanceWarning(float ultrasonic) {
    displayWarnings.ultrasonicDistanceWarning(ultrasonic);
}

// Display GPS Values
void View::displayGPSValues(double latitude, double longitude, uint32_t satelliteCount) {
    displaySensorData.displayGPSValues(latitude, longitude, satelliteCount);
}

// Display Break Status
void View::displayBreakStatus(bool isBreak) {
    displayWarnings.displayBreakStatus(isBreak);
}

// Login Success message
void View::logginSuccess(string v_username, string v_role) {
    displayWarnings.logginSuccess(v_username, v_role);
}

// Invalid User Login Credentials message
void View::invalidCredentials() {
    displayWarnings.invalidCredentials();
}

// Passenger Added message
void View::passengerAdded(){
    displayWarnings.passengerAdded();
}

// Passenger Dropped message
void View::passengerDropped() {
    displayWarnings.passengerDropped();
}

// Passenger Already Exists message
void View::passengerNotExists(string passengerName) {
    displayWarnings.passengerNotExists(passengerName);
}

// Passenger List Header
void View::passengersHeader() {
    displayUserData.passengersHeader();
}

// Display Passenger list Details
void View::passengerDetails(string v_firstName, string v_lastName, string v_username) {
    displayUserData.passengerDetails(v_firstName, v_lastName, v_username);
}

// input new user first name
string View::getfirstName() {
    while (true){
        string firstName = userInput.getfirstName();
        if (inputValidation.nameValidation(firstName)) {
            return firstName;
        } else {
            displayWarnings.invalidNameWarning();
        }
    }
}

// input new user last name
string View::getlastName() {
    while (true){
        string lastName = userInput.getlastName();
        if (inputValidation.nameValidation(lastName)) {
            return lastName;
        } else {
            displayWarnings.invalidNameWarning();
        }
    }
}

// input new user role
string View::getRole() {
    return userInput.getRole();
}

// input new user username
string View::getUserUsername() {
    return userInput.getUserUsername();
}

// input new user password
string View::getUserPassword() {
    return userInput.getUserPassword();
}