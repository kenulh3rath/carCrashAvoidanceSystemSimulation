//
// Created by kenul on 19/Feb/2024.
//

#ifndef DRAFTTWO_CONTROLLER_H
#define DRAFTTWO_CONTROLLER_H

#include <iostream>
//#include <unistd.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <memory>
#include <chrono>
#include <thread>

#include "Model.h"
#include "View.h"
#include "Authenticator.h"
#include "Resource.h"
#include "SensorData.h"
#include "loggSensorData.h"

class Controller {
private:
    unique_ptr<Model> model;
    unique_ptr<View> view;
    Authenticator authenticator;
    Authentication authInfo;
    ProofOfID proof;
    vector<Subject> subjects;
    Subject loggedInUser;
    Role role;
    Resource resource;
    secureData data;
    vector<SensorData> sensorData;
    SensorData loggedData;
    logSensorData loggData;

    string loggedInUsername;
    string loggedInRole;

    vector<string> header;
    vector<vector<string>> fileData;

    float ultrasonicVal;
    float speedVal;
    double latitude;
    double longitude;
    uint32_t satelliteCount;
    bool breakVal;

    vector<string> userLog;

public:

    Controller();
    void init();
    void drive();
    void setUltrasonic();
    void setSpeed();
    void setGPS();
    void setBreak();
    void breakInit();
    bool authenticateUser();
    void addPassenger();
    void viewPassengers();
    void dropPassenger();
    void readSubjects();
    void readSensorData();
    void saveSubjects();
    void saveRoles();
    void saveSensorData();
    string getCurrentTime();
    void logLiveData();

    ~Controller();



};

#endif //DRAFTTWO_CONTROLLER_H
