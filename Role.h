//
// Created by kenul on 26/Feb/2024.
//

#ifndef DRAFTTWO_ROLE_H
#define DRAFTTWO_ROLE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include "secureData.h"

using namespace std;

class Role {
private:
    secureData data;
    map<string, string> userRoleAccessMap;  // username, role

public:
    Role();
    void setRole(string, string);
    void readRoles();
    void dropRole(string);
    string getRoleName(string);

};

#endif //DRAFTTWO_ROLE_H
