//
// Created by kenul on 29/Feb/2024.
//

#include "displayUserData.h"

// Passenger List Header
void DisplayUserData::passengersHeader() {
    cout << "------- Passenger List -------" << endl;
}

// Display Passenger list Details
void DisplayUserData::passengerDetails(string v_firstName, string v_lastName, string v_username) {
    cout << v_firstName << " " << v_lastName << " - " << v_username << endl;
}