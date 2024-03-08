//
// Created by kenul on 16/Feb/2024.
#include "Subject.h"

Subject::Subject() {
    v_firstName = "";
    v_lastName = "";
    v_username = "";
    v_role = "";
}

Subject::Subject(string fName, string lName, string userName, string role) {
    v_firstName = fName;
    v_lastName = lName;
    v_username = userName;
    v_role = role;
}

void Subject::setFirstName(string firstName) {
    v_firstName = firstName;
}

void Subject::setLastName(string lastName) {
    v_lastName = lastName;
}

void Subject::setUsername(string username) {
    v_username = username;
}

void Subject::setRole(string role) {
    v_role = role;
}

void Subject::setProofID(string proofID) {
    v_proofID = proofID;
}


string Subject::getFirstName() {
    return v_firstName;
}

string Subject::getLastName() {
    return v_lastName;
}

string Subject::getUsername() {
    return v_username;
}

string Subject::getRole() {
    return v_role;
}

string Subject::getProofID() {
    return v_proofID;
}

