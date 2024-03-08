//
// Created by kenul on 25/Feb/2024.
//

#include "Permission.h"

Permission::Permission() {
                                    //      Driving | Add a passenger | View Passengers | Remove a passenger
                                    //         0            1                  2                  3
    roleResourceeAccessMap["driver"]    = {FULLACCESS, FULLACCESS,        FULLACCESS,         FULLACCESS};
    roleResourceeAccessMap["passenger"] = {NA,          NA,                  READ,                 NA};
}

uint16_t Permission::checkPermission(string role, uint32_t id) {
    map<string, resources>::iterator it;
    it = roleResourceeAccessMap.find(role);

    if (it != roleResourceeAccessMap.end()) {
        if (id <= it->second.size())
            return it->second[id];
        else
            cout << "Resource ID : " << id << "not found" << endl;
    }
    else
        cout << "Role : " << role << "not found" << endl;
    return NA;
}

