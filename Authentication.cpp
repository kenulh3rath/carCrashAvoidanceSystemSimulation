//
// Created by kenul on 16/Feb/2024.
//

#include "Authentication.h"


Authentication::Authentication() {
    readUsers();

    if (user.empty()) {
        user.insert({"admin", "1234"});  // add admin user if no data to read found
        user.insert({"john", "1234"});  // add user user if no data to read found
    }
}

void Authentication::addUser(const std::string& username, const std::string& password) {
    user.insert({username, password});
}

void Authentication::dropUser(const std::string& username) {
    user.erase(username);
}

void Authentication::readUsers() {
    std::ifstream users(usersFilePath);

    if (!users.is_open()) {
        std::cerr << "Error: Failed to open " + usersFilePath + " users file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(users, line)) {
        std::stringstream ss(line);
        std::string username, password;

        if (std::getline(ss, username, ':') && std::getline(ss, password)) {
            // Decrypt data if necessary
            user.insert({data.decryptData(username), data.decryptData(password)});
        }
    }

    users.close();
}

void Authentication::saveUsers() {
    std::ofstream users(usersFilePath);

    if (!users.is_open()) {
        std::cerr << "Error: Failed to open users file for writing" << std::endl;
        return;
    }

    for (const auto& entry : user) {
        // Encrypt data if necessary
        users << data.encryptData(entry.first) << ":" << data.encryptData(entry.second) << std::endl;
    }

    users.close();
}

bool Authentication::userValidation(const std::string& username, const std::string& password) {
    auto it_user = user.find(username);

    if (it_user != user.end()) {
        if (it_user->second == password) {
            return true;
        }
    }

    return false;
}

Authentication::~Authentication() {
    saveUsers();
}