//
// Created by ptrinh8 on 4/26/2022.
//

#ifndef FOSSIL_FIGHTERS_STATES_H
#define FOSSIL_FIGHTERS_STATES_H

#include "states_enum.h"
#include <map>

class States
{
private:
    std::map<states_enum, bool> states;

public:
    States();
    bool getState(states_enum state) const;
    void disableState(states_enum state);
    void enableState(states_enum state);
    void toggleState(states_enum state);
};


#endif //FOSSIL_FIGHTERS_STATES_H
