//
// Created by kenul on 28/Feb/2024.
//


#include "displayMenu.h"

// Lgin Menu
uint32_t DisplayMenu::loginMenu() {
    string choice;
    cout << "-----Mitsubishi Outlander SE 2022-----" << endl;

    while (true){
        cout << "1. Login" << endl;
        cout << "2. Car Module Description" << endl;
        cout << "3. Available Sensor Description" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        if (!inputValidation.numberValidation(choice)){
            cout << "Invalid choice. Please enter a number." << endl;
            continue;
        }

        if (inputValidation.numberRangeValidation(choice, 1, 4) == -1){
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            continue;
        }
        else{
            return stoi(choice);
        }
    }
}

// Main Menu
uint32_t DisplayMenu::addUserMenu() {
    string choice;

    cout << "----- Car Space -----" << endl;

    while(true){
        cout << "1. Start Drive" << endl;
        cout << "2. Add Passenger" << endl;
        cout << "3. View Passenger List" << endl;
        cout << "4. Logout" << endl;
        cin >> choice;

        if (!inputValidation.numberValidation(choice)){
            cout << "Invalid choice. Please enter a number." << endl;
            continue;
        }
        if (inputValidation.numberRangeValidation(choice, 1, 4) == -1){
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            continue;
        }
        else{
            return stoi(choice);
        }
    }
}

// Passenger Menu
uint32_t DisplayMenu::dropUserMenu() {
    string choice;

    cout << "----- Passengers -----" << endl;

    while(true){
        cout << "1. Drop Passenger" << endl;
        cout << "2. back" << endl;
        cin >> choice;

        if (!inputValidation.numberValidation(choice)){
            cout << "Invalid choice. Please enter a number." << endl;
            continue;
        }
        if (inputValidation.numberRangeValidation(choice, 1, 2) == -1){
            cout << "Invalid choice. Please enter a number between 1 and 2." << endl;
            continue;
        }
        else{
            return stoi(choice);
        }
    }
}