//
// Created by kenul on 16/Feb/2024.
//

#ifndef AUTHENTICATOR_PROOFOFID_H
#define AUTHENTICATOR_PROOFOFID_H

#include <iostream>

using namespace std;

class ProofOfID {
private:
    string v_proofID;

public:
    void setProofID(string);
    string getProofID();
};

#endif //AUTHENTICATOR_PROOFOFID_H

