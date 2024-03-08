//
// Created by kenul on 29/Feb/2024.
//

#ifndef DRAFTTWO_LOGGSENSORDATA_H
#define DRAFTTWO_LOGGSENSORDATA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "SensorData.h"

using namespace std;

enum class fileMethod {
    write,
    read,
    append,
    clear
};

class logSensorData {
private:
    vector<vector<SensorData>> logSensor;

    string fileName;
    fstream file;
    vector<string> header;
    vector<vector<string>> data;
public:
    void run(string, vector<string> &, vector<vector<string>> &, fileMethod);
    vector<vector<string>> fileRead(string);

    // write
    void fileWrite(vector<string> &, vector<vector<string>> &);
    void htmlStartWrite();
    void htmlEndWrite();
    void logHeader(vector<string> &);
    void logger(const vector<vector<string>> &);
    void logTable();

    void writeData(string, vector<string> &, vector<SensorData> &);

    // clear
    void clear(string);

    // read
    void fileRead();
    void readToConsole();
};

#endif //DRAFTTWO_LOGGSENSORDATA_H
