//
// Created by kenul on 26/Feb/2024.
//

#ifndef DRAFTTWO_RESOURCE_H
#define DRAFTTWO_RESOURCE_H

#include <iostream>
#include <cstdint>

#include "Subject.h"
#include "Permission.h"
#include "PermissionType.h"


using namespace std;

class Resource {
private:
    Permission permission;
    PermissionType accessType;
    string secret;
    uint32_t id;

public:
    bool accessGranted(Subject&, uint32_t, PermissionType);
};

#endif //DRAFTTWO_RESOURCE_H
