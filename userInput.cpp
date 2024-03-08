//
// Created by kenul on 28/Feb/2024.
//

#include "userInput.h"

// input new user first name
string UserInput::getfirstName() {
    cout << "Enter First Name :";
    cin >> firstName;

    return firstName;
}

// input new user last name
string UserInput::getlastName() {
    cout << "Enter Last Name :";
    cin >> lastName;

    return lastName;
}

// input new user role
string UserInput::getRole() {
    cout << "Enter Role :";
    cin >> role;

    return role;
}

// input new user username
string UserInput::getUserUsername() {
    cout << "Enter Username :";
    cin >> username;

    return username;
}

// input new user password
string UserInput::getUserPassword() {
    cout << "Enter Password :";
    cin >> password;

    return password;
}