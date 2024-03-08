//
// Created by kenul on 26/Feb/2024.
//

#include "Resource.h"


bool Resource::accessGranted(Subject& subject, uint32_t _id, PermissionType _accessType) {
    if(permission.checkPermission(subject.getRole(), _id) & (_accessType | FULLACCESS)) {
        accessType = _accessType;
        return true;
    }
    else
        return false;
}