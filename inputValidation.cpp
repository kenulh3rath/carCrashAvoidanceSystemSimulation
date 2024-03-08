//
// Created by kenul on 29/Feb/2024.
//

#include "inputValidation.h"

bool InputValidation::nameValidation(string name) {
    return name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos;
}

bool InputValidation::numberValidation(string number) {
    return number.find_first_not_of("0123456789") == string::npos;
}

uint32_t InputValidation::numberRangeValidation(string number, uint32_t min, uint32_t max) {
    uint32_t num = stoi(number);
    if (num < min || num > max) {
        return -1;
    }
    return num;
}