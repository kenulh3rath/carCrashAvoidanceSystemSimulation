//
// Created by kenul on 27/Feb/2024.
//

#ifndef DRAFTTWO_SECUREDATA_H
#define DRAFTTWO_SECUREDATA_H

#include <iostream>
#include <cstdint>

using namespace std;

class secureData {
private:
    uint32_t key;  // Key to encrypt and decrypt
    char encryptChar;
    char decryptChar;

public:
    secureData();
    string encryptData(string);
    string decryptData(string);
};


#endif //DRAFTTWO_SECUREDATA_H
