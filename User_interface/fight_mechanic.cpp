//
// Created by ptrinh8 on 4/30/2022.
//

#include "fight_mechanic.h"

fight_mechanic::fight_mechanic() = default;

void fight_mechanic::hit_enemy(Complete_vivosaur& player, Complete_vivosaur& enemy)
{
    enemy.take_damage();
    std::cout << enemy.get_current_hp() << std::endl;
    if (enemy.is_dead())
    {
        enemy.enableState(DEAD);
    }
}


