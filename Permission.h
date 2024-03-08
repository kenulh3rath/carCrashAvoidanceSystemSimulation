//
// Created by kenul on 25/Feb/2024.
//

#ifndef DRAFTTWO_PERMISSION_H
#define DRAFTTWO_PERMISSION_H

#include <iostream>
#include <cstdint>
#include <vector>
#include <map>

#include "PermissionType.h"



using namespace std;


class Permission {
private:
    typedef vector<uint16_t> resources;
    map<string, resources> roleResourceeAccessMap;
public:
    Permission();
    uint16_t checkPermission(string, uint32_t);
};

#endif //DRAFTTWO_PERMISSION_H
