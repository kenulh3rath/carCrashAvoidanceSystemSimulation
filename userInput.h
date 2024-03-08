//
// Created by kenul on 28/Feb/2024.
//

#ifndef DRAFTTWO_USERINPUT_H
#define DRAFTTWO_USERINPUT_H

#include <iostream>

using namespace std;

class UserInput {
    string firstName;
    string lastName;
    string username;
    string password;
    string role;
public:
    string getfirstName();
    string getlastName();
    string getRole();
    string getUserUsername();
    string getUserPassword();
};

#endif //DRAFTTWO_USERINPUT_H
