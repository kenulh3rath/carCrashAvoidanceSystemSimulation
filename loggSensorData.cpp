//
// Created by kenul on 29/Feb/2024.
//

#include "loggSensorData.h"

void logSensorData::run(string v_file, vector<string> &v_header, vector<vector<string>> &v_data , fileMethod method) {
    this->fileName = v_file;
    if (method == fileMethod::write)  // Write
    {
        file.open(fileName, ios::out);

        // check 1/3
        if (!file.is_open()){
            cout << "Error: File not opened" << endl;
        }
        else {
            // check 2/3
            if (file.good()) {
                // check 3/3
                fileWrite(v_header, v_data);  // write the data to the file
            }
            else {
                std::cerr << "Error: File stream is in a bad state.\n";
            }
            file.close();
        }
        data.clear();  // Clear the data vector
    }

    else if (method == fileMethod::read)  // Read
    {
        file.open(fileName, ios::in);

        // check 1/3
        if (file.is_open())
        {
            // check 2/3
            if (file.good())
            {
                // check 3/3
                fileRead();  // read the data from the file
            }
            else
            {
                cout << "Error: File stream is in a bad state.\n";
            }
            file.close();
        }
        else
        {
            cout << "Error: Unable to open file " << fileName << " for reading.\n";
        }
    }
    else if (method == fileMethod::append)  // Append
    {
        data.clear();  // Clear the data vector
        file.open(fileName, ios::in);
        fileRead();  // read the data from the file
        file.close();
        file.open(fileName, ios::out);
        fileWrite(v_header, v_data);  // write the data to the file
        file.close();  // Close the file
    }
    else if (method == fileMethod::clear)  // Clear
    {
        file.open(fileName, ios::out);
        logHeader(v_header);  // input header into the header vector
        htmlStartWrite();  // html start tags
        htmlEndWrite();  // html end tags
        file.close();  // Close the file
    }
}

vector<vector<string>> logSensorData::fileRead(string v_fileName) {
    fileName = v_fileName;
    file.open(fileName, ios::in);
    fileRead();  // read the data from the file
    file.close();

    return data;
}

void logSensorData::fileWrite(vector<string> &v_header, vector<vector<string>> &v_data) {
    logHeader(v_header);  // input header into the header vector
    logger(v_data);  // input data into the data vector
    htmlStartWrite();  // html start tags
    logTable();  // log the table
    htmlEndWrite();  // html end tags
}

void logSensorData::clear(string v_fileName) {
    file.open(v_fileName, ios::out);
    file.close();
}

void logSensorData::htmlStartWrite() {
    file << "<!doctype html>" << endl
         << "<html lang=\"en\">" << endl
         << "<head>" << endl
         << "<meta charset=\"utf-8\">" << endl
         << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" << endl
         << "<title>Sensor Data Logger</title>" << endl
         << "<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH\" crossorigin=\"anonymous\">" << endl
         << "</head>" << endl
         << "<body>" << endl
         << "<h1 class=\"text-center\">Sensor Data Logger</h1>" << endl
         << "<table class=\"table\">" << endl
         << "<thead>" << endl
         << "<tr>" << endl;

    for (int i = 0; i < header.size(); i++) {
        file << "<th scope=\"col\">" << header[i] << "</th>" << endl;
    }

    file << "</tr>" << endl
         << "</thead>" << endl
         << "<tbody>" << endl;
}

void logSensorData::htmlEndWrite() {
    file << "</tbody>" << endl
         << "</table>" << endl
         << "<script src=\"https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js\" integrity=\"sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz\" crossorigin=\"anonymous\"></script>" << endl
         << "</body>" << endl
         << "</html>"
         << endl;
}

void logSensorData::logHeader(vector<string> &headers) {
    header.clear();
    header = headers;
}

// make a html logger function that logs the sensor data to a html file which sending from a 2D vector and write them in a table
void logSensorData::logger(const vector<vector<string>> &v_data){
    vector<string> tempVec;
//    this->data = v_data;

    for (int i = 0; i < v_data.size(); ++i) {
        for (int j = 0; j < v_data[i].size(); ++j) {
            tempVec.push_back(v_data[i][j]);
        }
        data.emplace_back(tempVec);
        tempVec.clear();
    }


}

void logSensorData::logTable() {
    for (int i = 0; i < data.size(); i++) {
        file  << "<tr>" << endl
              << "<th scope=\"row\">" << data[i][0] << "</th>" << endl;
        for (int j = 1; j < data[i].size(); j++) {
            file << "<td>" << data[i][j] << "</td>" << endl;
        }
        file << "</tr>" << endl;
    }
}

void logSensorData::writeData(string v_fileName, vector<string> &v_header, vector<SensorData> &v_data) {
    data.clear();  // Clear the data vector
    file.open(fileName, ios::in);
    fileRead();  // read the data from the file
    file.close();
    file.open(fileName, ios::out);

    logHeader(v_header);  // input header into the header vector
    htmlStartWrite();  // html start tags
    for (int i = 0; i < v_data.size(); i++) {
        file  << "<tr>" << endl
              << "<th scope=\"row\">" << v_data[i].getRecordID() << "</th>" << endl
              << "<td>" << v_data[i].getdateAndTime() << "</td>" << endl
              << "<td>" << v_data[i].getUltrasonicVal() << "</td>" << endl
              << "<td>" << v_data[i].getLatitude() << "</td>" << endl
              << "<td>" << v_data[i].getLongitude() << "</td>" << endl
              << "<td>" << v_data[i].getSatelliteCount() << "</td>" << endl
              << "<td>" << v_data[i].getSpeedVal() << "</td>" << endl
              << "<td>" << v_data[i].getBreakVal() << "</td>" << endl
              << "</tr>" << endl;
    }
    htmlEndWrite();  // html end tags
    file.close();  // Close the file
}

void logSensorData::fileRead() {
    vector<string> lineRead;

    string line;
    bool startRead = false;

    while (getline(file, line)) {
        if (line == "<tbody>") {
            startRead = true;
            continue;
        }
        else if (line == "</tbody>") {
            break;
        }

        if (startRead) {
            if (line == "<tr>")
                continue;
            else if (line == "</tr>") {
                data.push_back(lineRead);
                lineRead.clear();
                continue;
            }
            // Find the position of the opening and closing angle brackets
            size_t start_pos = line.find('>') + 1;
            size_t end_pos = line.find('<', start_pos);

            // Extract the substring between the opening and closing angle brackets
            std::string value = line.substr(start_pos, end_pos - start_pos);

            lineRead.push_back(value);
        }
    }
}

// Testing Purpose
void logSensorData::readToConsole() {
    for (int i = 0; i < data.size(); i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < data[i].size(); j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}