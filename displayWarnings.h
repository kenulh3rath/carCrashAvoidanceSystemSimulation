//
// Created by kenul on 28/Feb/2024.
//

#ifndef DRAFTTWO_DISPLAYWARNINGS_H
#define DRAFTTWO_DISPLAYWARNINGS_H

#include <iostream>

using namespace std;

class DisplayWarnings {
public:
    void invalidChoiceWarning();
    void noAccessWarning(string);
    void drivingStopped();
    void invalidCredentials();
    void passengerAdded();
    void passengerDropped();
    void passengerNotExists(string);
    void ultrasonicDistanceWarning(float);
    void displayBreakStatus(bool);
    void logginSuccess(string, string);
    void invalidNameWarning();

};

#endif //DRAFTTWO_DISPLAYWARNINGS_H
