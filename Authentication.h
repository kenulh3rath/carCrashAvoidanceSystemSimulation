//
// Created by kenul on 16/Feb/2024.
//

#ifndef AUTHENTICATOR_AUTHENTICATION_H
#define AUTHENTICATOR_AUTHENTICATION_H

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>

#include "secureData.h"

class Authentication {
private:
    secureData data;
    std::map<std::string, std::string> user;
    const std::string usersFilePath = "users.txt";

public:
    Authentication();
    void addUser(const std::string& username, const std::string& password);
    void dropUser(const std::string& username);
    void readUsers();
    void saveUsers();
    bool userValidation(const std::string& username, const std::string& password);
    ~Authentication();
};

#endif //AUTHENTICATOR_AUTHENTICATION_H

