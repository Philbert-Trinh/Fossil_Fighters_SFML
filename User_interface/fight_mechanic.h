//
// Created by ptrinh8 on 4/30/2022.
//

#ifndef FOSSIL_FIGHTERS_FIGHT_MECHANIC_H
#define FOSSIL_FIGHTERS_FIGHT_MECHANIC_H
#include "../vivosaur/Complete_vivosaur.h"
#include <iostream>

class fight_mechanic
{
private:

public:
    fight_mechanic();
    void hit_enemy(Complete_vivosaur& player, Complete_vivosaur& enemy);
};


#endif //FOSSIL_FIGHTERS_FIGHT_MECHANIC_H
