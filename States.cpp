//
// Created by ptrinh8 on 4/26/2022.
//

#include "States.h"

States::States()
{
    for(int i=0; i<LAST_STATE; i++)
        states[states_enum(i)] = false;
}

bool States::getState(states_enum state) const
{
    return states.at(state);
}

void States::disableState(states_enum state)
{
    states[state] = false;
}

void States::enableState(states_enum state)
{
    states[state] = true;
}

void States::toggleState(states_enum state)
{
    states[state] = !states[state];
}
