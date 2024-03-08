//
// Created by kenul on 16/Feb/2024.
//

#include "Authenticator.h"

void Authenticator::getPassword(string password) {
    v_password = password;
}

bool Authenticator::authenticate(Subject &subject, ProofOfID &proof){
    Authentication auth;

    string user = subject.getUsername();
    string password;
    string cookie;

    if (auth.userValidation(user, v_password)) {
        cookie = user + " " + v_password;
        proof.setProofID(cookie);
        subject.setProofID(cookie);
        return true;
    }
    return false;
}
