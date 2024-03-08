//
// Created by kenul on 28/Feb/2024.
//

#include "displayWarnings.h"
#include "color.hpp"

// User invalid choice warning message
void DisplayWarnings::invalidChoiceWarning() {
    cout << hue::light_red << "Invalid Choice"
         << hue::reset << endl << endl;
}

// No access warnging message
void DisplayWarnings::noAccessWarning(string warningMessage) {
    cout << hue::light_red << "Sorry, Passenger does not have access to " <<  warningMessage
         << hue::reset << endl << endl;
}

// Driving Stopped message
void DisplayWarnings::drivingStopped() {
    cout << hue::light_yellow << "Driving Stopped"
         << hue::reset << endl << endl;
}

// Invalid User Login Credentials message
void DisplayWarnings::invalidCredentials() {
    cout << hue::light_red << "Invalid username or password"
         << hue::reset << endl << endl;
}

// Passenger Added message
void DisplayWarnings::passengerAdded(){
    cout << hue::light_green << "New Passenger Added"
         << hue::reset << endl << endl;
}

// Passenger Dropped message
void DisplayWarnings::passengerDropped() {
    cout << hue::light_green << "Passenger Dropped Safely"
         << hue::reset << endl << endl;
}

// Passenger Already Exists message
void DisplayWarnings::passengerNotExists(string passengerName) {
    // no passenger under the name
    cout << hue::light_red << "No passenger found under the username " << passengerName
         << hue::reset << endl << endl;
}

// Display distance warning
void DisplayWarnings::ultrasonicDistanceWarning(float ultrasonic) {
    if (ultrasonic < 3){
        cout << hue::yellow << "Warning: "
             << hue::light_red << "Stop!!"
             << hue::reset << endl;
    }
    else if (ultrasonic < 7){
        cout << hue::yellow << "Warning: "
             << hue::light_yellow << "Slow Down"
             << hue::reset << endl;
    }
    else if (ultrasonic < 10) {
        cout << hue::yellow << "Warning: "
             << hue::light_yellow << "Object is too close"
             << hue::reset << endl;
    }
    else {
        cout << hue::light_green << "Front Clear"
             << hue::reset << endl;
    }
}

// Display Break Status
void DisplayWarnings::displayBreakStatus(bool isBreak) {
    if (isBreak){
        cout << hue::light_red << "Auto Brake Activated"
             << hue::reset << endl;
    }
    else{
        cout << hue::light_green << "Brake is Off"
             << hue::reset << endl;
    }
}

// Login Success message
void DisplayWarnings::logginSuccess(string v_username, string v_role) {
    cout << hue::light_green << "Login Successful as a "<< v_role << hue::reset << endl;
    cout << hue::light_green << "Welcome " << v_username << hue::reset << endl << endl;
}

// Invalid User Name message
void DisplayWarnings::invalidNameWarning() {
    cout << hue::light_red << "Invalid Name"
         << hue::reset << endl << endl;
}