//
// Created by kenul on 16/Feb/2024.
//

#ifndef AUTHENTICATOR_AUTHENTICATOR_H
#define AUTHENTICATOR_AUTHENTICATOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Authentication.h"
#include "Subject.h"
#include "ProofOfID.h"

class Authenticator {
private:
    std::string v_password;

public:
    void getPassword(std::string password);
    bool authenticate(Subject &subject, ProofOfID &proof);
};


#endif //AUTHENTICATOR_AUTHENTICATOR_H