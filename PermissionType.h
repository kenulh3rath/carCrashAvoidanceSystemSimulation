//
// Created by kenul on 26/Feb/2024.
//

#ifndef DRAFTTWO_PERMISSIONTYPE_H
#define DRAFTTWO_PERMISSIONTYPE_H

#include <cstdint>

using namespace std;

enum PermissionType: uint16_t {
    NA = 0x00,  // 0
    READ = 0x01,  // 1
    WRITE = 0x02,  // 2
    EDIT = 0x03,  // 3
    EXECUTE = 0x04,  // 4
    FULLACCESS = 0x05,  // 5
};

#endif //DRAFTTWO_PERMISSIONTYPE_H
