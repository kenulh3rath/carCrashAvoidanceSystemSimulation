//
// Created by kenul on 29/Feb/2024.
//

#ifndef DRAFTTWO_INPUTVALIDATION_H
#define DRAFTTWO_INPUTVALIDATION_H

#include <iostream>
#include <cctype>
#include <cstdint>
#include <string>

using namespace std;

class InputValidation {
public:
    bool nameValidation(string);
    bool numberValidation(string);
    uint32_t numberRangeValidation(string, uint32_t, uint32_t);
};

#endif //DRAFTTWO_INPUTVALIDATION_H
