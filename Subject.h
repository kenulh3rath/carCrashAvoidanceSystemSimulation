//
// Created by kenul on 16/Feb/2024.
//

#ifndef AUTHENTICATOR_SUBJECT_H
#define AUTHENTICATOR_SUBJECT_H

#include <iostream>

#include "Role.h"

using namespace std;

class Subject {
private:
    string v_firstName;
    string v_lastName;
    string v_username;
    string v_role;
    string v_proofID;

public:
    Subject();
    Subject(string, string, string, string);
    void setFirstName(string);
    void setLastName(string);
    void setUsername(string);
    void setRole(string);
    void setProofID(string);

    string getFirstName();
    string getLastName();
    string getUsername();
    string getRole();
    string getProofID();

};

#endif //AUTHENTICATOR_SUBJECT_H

