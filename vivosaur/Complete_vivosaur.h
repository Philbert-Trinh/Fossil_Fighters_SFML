//
// Created by ptrinh8 on 4/29/2022.
//

#ifndef FOSSIL_FIGHTERS_COMPLETE_VIVOSAUR_H
#define FOSSIL_FIGHTERS_COMPLETE_VIVOSAUR_H
#include "Vivosaur_sprite.h"
#include "Vivosaur_stats.h"

class Complete_vivosaur: public Vivosaur_sprite, public Vivosaur_stats
{
private:
    sf::Clock time;
public:
    Complete_vivosaur();
    explicit Complete_vivosaur(vivosaur_names name_enum);
    void player_idle_check();
    void enemy_idle_check();
};


#endif //FOSSIL_FIGHTERS_COMPLETE_VIVOSAUR_H
