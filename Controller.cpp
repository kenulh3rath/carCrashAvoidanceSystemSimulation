//
// Created by kenul on 19/Feb/2024.
//


#include "Controller.h"

using namespace std;

Controller::Controller() {
    model = make_unique<Model>();
    view = make_unique<View>();

    readSubjects();
    readSensorData();

    if (subjects.size() == 0){
        userLog.emplace_back(getCurrentTime() + " : No data to read found. Adding admin user.");  // user Log
        subjects.emplace_back("admin", " ", "admin", "driver");  // add admin user if no data to read found
    }
}

void Controller::init() {
    bool menu = true;
    uint32_t choice;

    while (menu){
        userLog.emplace_back(getCurrentTime() + " : Application Started by the user");  // user Log
        choice = view->loginMenu();

        if (choice == 1){  // login
            userLog.emplace_back(getCurrentTime() + " : User requests to login.");  // user Log
            bool authenticated = authenticateUser();

            while (authenticated){
                userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " logged in.");  // user Log

                choice = view->addUserMenu();

                if (choice == 1){  // drive
                    userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " requests to drive.");  // user Log
                    if(resource.accessGranted(loggedInUser, 0, READ)){  // check if user has access to drive
                        userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " is driving.");  // user Log
                        drive();
                        userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " stopped driving.");  // user Log
                    }
                    else{
                        userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " request rejected for not having access to drive");  // user Log
                        view->noAccessWarning("drive");
                    }
                }
                else if (choice == 2){  // add passenger
                    userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " requests to add a passenger.");  // user Log
                    if(resource.accessGranted(loggedInUser, 1, WRITE)){  // check if user has access to add passenger
                        userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " add passenger request granted");  // user Log
                        addPassenger();
                    }
                    else{
                        userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " request rejected for not having access to add passenger");  // user Log
                        view->noAccessWarning("add passenger");
                    }
                }
                else if (choice == 3){  // view passenger list
                    userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " requests to view passenger list.");  // user Log
                    viewPassengers();
                    userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " viewed passenger list.");  // user Log
                    choice = view->dropUserMenu();

                    if (choice == 1){  // drop passenger
                        userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " requests to drop a passenger.");  // user Log
                        if(resource.accessGranted(loggedInUser, 3, WRITE)){  // check if user has access to add passenger
                            dropPassenger();
                        }
                        else{
                            userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " request rejected for not having access to drop passenger");  // user Log
                            view->noAccessWarning("drop passenger");
                        }
                    }
                    else if (choice == 2){  // back
                        continue;
                    }
                    else{  // invalid choice
                        userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " entered an invalid choice");  // user Log
                        view->invalidChoiceWarning();
                    }

                }
                else if (choice == 4){  // logout
                    userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " logged out.");  // user Log
                    authenticated = false;
                }
                else{  // invalid choice
                    userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " entered an invalid choice");  // user Log
                    view->invalidChoiceWarning();
                }
            }
        }
        else if (choice == 2){  // vehicle description

            userLog.emplace_back(getCurrentTime() + " : User views vehicle description.");  // user Log

            view->vehicleDescription();
        }
        else if (choice == 3){  // sensor description

            userLog.emplace_back(getCurrentTime() + " : User views sensor description.");  // user Log

            view->sensorDescription();
        }
        else if (choice == 4){  // exit

            userLog.emplace_back(getCurrentTime() + " : User exits the application.");  // user Log

            menu = false;
        }
        else{  // invalid choice

            userLog.emplace_back(getCurrentTime() + " : User entered an invalid choice.");  // user Log

            view->invalidChoiceWarning();
        }
    }


}

void Controller::drive() {
    uint32_t i  = 0;

    while (!_kbhit()){
        i += 1;
        view->displayRecordID(i);
        setUltrasonic();
        setSpeed();
        setBreak();
        setGPS();
        cout << endl;

        loggedData.setRecordID(i);
        loggedData.setDateAndTime(getCurrentTime());
        loggedData.setSpeedVal(speedVal);

        sensorData.push_back(loggedData);

        //sleep(1);
        this_thread::sleep_for(chrono::seconds(1));
    }
    view->drivingStopped();

    _getch();
}

void Controller::setUltrasonic() {
    ultrasonicVal = model->getUltrasonic();
    view->displayUltrasonicValues(ultrasonicVal);

    if (ultrasonicVal < 3){
        model->setBreak(true);
    }
    else{
        model->setBreak(false);
    }

    loggedData.setUltrasonicVal(ultrasonicVal);
    loggedData.setBreakVal(model->getBreak());

}

void Controller::setSpeed() {
    speedVal = model->getSpeed();
    view->displaySpeedValues(speedVal);
}

void Controller::setGPS() {
    latitude = model->getLatitude();
    longitude = model->getLongitude();
    satelliteCount = model->getSatelliteCount();
    view->displayGPSValues(latitude, longitude, satelliteCount);

    loggedData.setGPS(latitude, longitude, satelliteCount);
}

void Controller::breakInit() {
    breakVal = model->getBreak();
}

void Controller::setBreak() {
    breakInit();
    view->displayBreakStatus(breakVal);
}

bool Controller::authenticateUser() {  // Login
    string username = view->getUserUsername();
    string password = view->getUserPassword();

    authenticator.getPassword(password);

    auto it = find_if(subjects.begin(), subjects.end(), [username](Subject& obj) { return obj.getUsername() == username; });

    if (it != subjects.end()){
        if(authenticator.authenticate(*it, proof)){
            view->logginSuccess(it->getUsername(), it->getRole());  // display login success message

            loggedInUser = *it;

            loggedInUsername = it->getUsername();  // remove if Subject loggedInUser = *it work
            loggedInRole = it->getRole();  // remove if Subject loggedInUser = *it work

            return true;
        }  // authenticate user
        else{
            view->invalidCredentials();  // display invalid credentials message
            return false;
        }
    }
    else{
        view->invalidCredentials();  // display invalid credentials message
        return false;
    }
}

void Controller::addPassenger() {
    string firstName = view->getfirstName();
    string lastName = view->getlastName();
    string userRole = "passenger";  // "passenger" role
    string username = view->getUserUsername();
    string password = view->getUserPassword();

    role.setRole(username, userRole);  // add user to role map (role.cpp
    subjects.emplace_back(firstName, lastName, username, userRole);  // add user to subject vector
    authInfo.addUser(username, password);  // add user to authenticator map
    view->passengerAdded();  // display success message

    userLog.emplace_back(getCurrentTime() + " : " + username + " added " + username + " as a passenger.");  // user Log
}

void Controller::viewPassengers() {
    view->passengersHeader();
    for (int i = 0; i < subjects.size(); i++) {
        if (role.getRoleName(subjects[i].getUsername()) == "passenger"){
            view->passengerDetails(subjects[i].getFirstName(), subjects[i].getLastName(), subjects[i].getUsername());
        }
    }
}

void Controller::dropPassenger() {
    string username = view->getUserUsername();

    auto it = find_if(subjects.begin(),
                            subjects.end(),
                            [username](Subject& obj)
                            { return obj.getUsername() == username; });

    if (it != subjects.end()){
        subjects.erase(it);  // remove user from subject vector
        authInfo.dropUser(username);  // remove user from authenticator
        role.dropRole(username);  // remove user from roles

        userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " dropped " + username + " as a passenger.");  // user Log

        view->passengerDropped();  // display success message
    }
    else{

        userLog.emplace_back(getCurrentTime() + " : " + loggedInUsername + " entered an invalid username to drop a passenger.");  // user Log

        view->passengerNotExists(username);  // display passenger not found message
    }
}

string Controller::getCurrentTime() {
    // Get the current time using std::chrono::system_clock
    chrono::system_clock::time_point now = chrono::system_clock::now();

    // Convert the time point to a time_t object
    time_t now_c = chrono::system_clock::to_time_t(now);

    // Convert the time_t object to a local time struct
    tm* local_time = localtime(&now_c);

    ostringstream oss;
    oss << put_time(local_time, "%c"); // Format specifier for date and time
    return oss.str();
}

void Controller::readSubjects() {
    string v_firstName, v_lastName, v_username, tempVal;
    string fileName = "subjects.txt";
    ifstream users(fileName);

    if (!users.is_open()) {
        cout << "Error: File not found" << endl;
        subjects.emplace_back("admin", " ", "admin", "driver");  // add admin user if no data to read found
    }

    string line;
    while (getline(users, line)) {
        stringstream ss(line);
        tempVal = " ";

        if (getline(ss, tempVal, ':')) {
            v_firstName = tempVal;

            if (getline(ss, tempVal, ':')) {
                v_lastName = tempVal;

                if (getline(ss, tempVal)) {
                    v_username = tempVal;
                }
            }
        }

        subjects.emplace_back(data.decryptData(v_firstName),
                              data.decryptData(v_lastName),
                              data.decryptData(v_username),
                              role.getRoleName(data.decryptData(v_username)));
    }
}

void Controller::readSensorData() {
    cout << "Reading sensor data from file..." << endl;
    fileData = loggData.fileRead("sensorDataLogger.html");

    for (int i = 0; i < fileData.size(); i++) {
        sensorData.emplace_back(
                fileData[i][1], // Date and Time
                stoi(fileData[i][0]), // Record ID
                stod(fileData[i][2]), // Ultrasonic Value
                stof(fileData[i][6]),
                (fileData[i][7] == "1" ? true : false),
                stod(fileData[i][3]), // Latitude
                stod(fileData[i][4]), // Longitude
                stoi(fileData[i][5]) // Satellite Count
                );
    }

    //loggData.readToConsole();

    fileData.clear();
}

void Controller::saveSubjects() {
    string v_firstName, v_lastName, v_username;

    string fileName = "subjects.txt";

    ofstream users(fileName);

    if (!users.is_open()) {
        cout << "Error: " + fileName + " File not found" << endl;
    }

    for (int i = 0; i < subjects.size(); i++) {
        v_firstName = data.encryptData(subjects[i].getFirstName());
        v_lastName = data.encryptData(subjects[i].getLastName());
        v_username = data.encryptData(subjects[i].getUsername());

        users << v_firstName << ":"
              << v_lastName << ":"
              << v_username << endl;
    }

    users.close();

    cout << "Subjects saved to file" << endl;
}

void Controller::saveRoles() {
    string v_username, v_role;

    string fileName = "roles.txt";

    ofstream roles(fileName);

    if (!roles.is_open()) {
        cout << "Error: " + fileName + " File not found" << endl;
    }

    for (int i = 0; i < subjects.size(); i++) {
        v_username = data.encryptData(subjects[i].getUsername());
        v_role = data.encryptData(subjects[i].getRole());
        roles << v_username << ":" << v_role << endl;
    }

    roles.close();

    cout << "Roles saved to file" << endl;
}

void Controller::saveSensorData() {
    vector<SensorData> tempSensorData;

    header.emplace_back("Record ID");
    header.emplace_back("Date and Time");
    header.emplace_back("Ultrasonic Value");
    header.emplace_back("Latitude");
    header.emplace_back("Longitude");
    header.emplace_back("Satellite Count");
    header.emplace_back("Speed (km/h)");
    header.emplace_back("Break Status");

    for (int i = 0; i < sensorData.size(); ++i) {
        tempSensorData.push_back(sensorData[i]);
    }

    loggData.clear("sensorDataLogger.html");
    loggData.writeData("sensorDataLogger.html", header, tempSensorData);

    cout << "Sensor data saved to file" << endl;
}

void Controller::logLiveData() {
    string fileName = "liveLogger.txt";
    fstream file(fileName, ios::app);

    if (!file.is_open()) {
        cout << "Error: " + fileName + " File not found" << endl;
    }

    for (int i = 0; i < userLog.size(); ++i) {
        file << userLog[i] << endl;
    }

    file.close();

    cout << "Data logged Successfully" << endl;
}

Controller::~Controller() {
    saveSubjects();
    saveRoles();
    saveSensorData();
    logLiveData();
}
