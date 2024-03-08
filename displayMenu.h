//
// Created by kenul on 28/Feb/2024.
//

#ifndef DRAFTTWO_DISPLAYMENU_H
#define DRAFTTWO_DISPLAYMENU_H

#include <iostream>
#include <cstdint>

#include "inputValidation.h"

using namespace std;

class DisplayMenu {
private:
    InputValidation inputValidation;
public:
    uint32_t loginMenu();
    uint32_t addUserMenu();
    uint32_t dropUserMenu();
};

#endif //DRAFTTWO_DISPLAYMENU_H
