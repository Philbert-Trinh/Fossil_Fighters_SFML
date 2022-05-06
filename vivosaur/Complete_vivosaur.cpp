//
// Created by ptrinh8 on 4/29/2022.
//

#include "Complete_vivosaur.h"

Complete_vivosaur::Complete_vivosaur() = default;

Complete_vivosaur::Complete_vivosaur(vivosaur_names name_enum):Vivosaur_sprite(name_enum), Vivosaur_stats(name_enum)
{
    disableState(DEAD);
    disableState(CLICKED);
    disableState(DORMANT);
    disableState(ATTACKING);
    disableState(ENGAGED);
    disableState(IN_AZ);
    disableState(IN_SZ);
    disableState(IN_EZ);
    disableState(BEING_SWAPPED);
    enableState(HIDDEN);
}

void Complete_vivosaur::player_idle_check()
{
    if (!getState(CLICKED) && !getState(DORMANT) && !getState(TARGET) && !getState(BEING_SWAPPED) && !getState(TURN_OVER))
    {
       player_idle();
    }
}

void Complete_vivosaur::enemy_idle_check()
{
    if (!getState(CLICKED) && !getState(DORMANT) && !getState(TARGET))
    {
        enemy_idle();
    }
}