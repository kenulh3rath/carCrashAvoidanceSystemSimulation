//
// Created by kenul on 27/Feb/2024.
//

#include "secureData.h"

secureData::secureData() {
    key = 7;
}

string secureData::encryptData(string data) {
    string encryptedData = data;
    uint32_t length = encryptedData.length();
    for (uint32_t i = 0; i < length; i++) {
        encryptedData[i] = encryptedData[i] ^ key;
    }
    return encryptedData;

}

string secureData::decryptData(string data) {
    string decryptedData = data;
    uint32_t length = decryptedData.length();
    for (uint32_t i = 0; i < length; i++) {
        decryptedData[i] = decryptedData[i] ^ key;
    }
    return decryptedData;
}
