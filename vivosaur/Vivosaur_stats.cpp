//
// Created by ptrinh8 on 4/29/2022.
//

#include "Vivosaur_stats.h"

Vivosaur_stats::Vivosaur_stats() = default;

Vivosaur_stats::Vivosaur_stats(vivosaur_names name_enum)
{
    srand (time(nullptr));
    name_string = set_name(name_enum);
}

std::string Vivosaur_stats::set_name(vivosaur_names name_enum)
{
    switch (name_enum)
    {
        case DUNA:
            return "Duna";

        case TYRANNO:
            return "Tyranno";

        case BRACHIO:
            return "Brachio";

        case AOPTERYX:
            return "Aopteryx";

        case TRICERA:
            return "Tricera";

        case STEGO:
            return "Stego";

        default :
            return "ERROR";
    }
}

std::string Vivosaur_stats::get_name()
{
    return name_string;
}


int Vivosaur_stats::get_current_hp() const
{
    return current_hp;
}

int Vivosaur_stats::get_total_hp() const
{
    return total_hp;
}

int Vivosaur_stats::get_attack() const
{
    return atk;
}

int Vivosaur_stats::get_defense() const
{
    return def;
}

int Vivosaur_stats::get_accuracy() const
{
    return acc;
}

int Vivosaur_stats::get_speed() const
{
    return spd;
}

void Vivosaur_stats::set_hp(int damage)
{
    current_hp = current_hp-damage;
}

void Vivosaur_stats::take_damage()
{
    set_hp(rand() % 10 + 1);
}

bool Vivosaur_stats::is_dead() const
{
    if (get_current_hp() < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


