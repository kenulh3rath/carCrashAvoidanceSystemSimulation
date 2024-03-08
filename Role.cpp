//
// Created by kenul on 26/Feb/2024.
//


#include "Role.h"

Role::Role() {

    readRoles();

    if (userRoleAccessMap.empty()) {
        userRoleAccessMap.insert(pair<string, string>("admin", "driver"));  // add admin user if no data to read found

        // username, role
//        userRoleAccessMap["admin"] = "driver";
//        userRoleAccessMap["test"] = "passenger";
    }
}

void Role::setRole(string username, string role) {
    userRoleAccessMap[username] = role;
}

void Role::readRoles() {
    string v_username, v_role;

    string fileName = "roles.txt";

    ifstream roles(fileName);

    if (!roles.is_open()) {
        cout << "Error: " + fileName + " not found" << endl;
    }

    string line;
    while (getline(roles, line)) {
        stringstream ss(line);
        string token;

        if (getline(ss, token, ':')) {
            v_username = token;

            if (getline(ss, token)) {
                v_role = token;
            }

//            userRoleAccessMap.insert(pair<string, string>(v_username, v_role));
            userRoleAccessMap.insert(pair<string, string>(data.decryptData(v_username),
                                                             data.decryptData(v_role)));
        }
    }
}

void Role::dropRole(string username) {
    userRoleAccessMap.erase(username);

}

string Role::getRoleName(string username) {
    map<string, string>::iterator it;
    it = userRoleAccessMap.find(username);
    if (it != userRoleAccessMap.end())
        return it->second;
    else
        return "NA";
}