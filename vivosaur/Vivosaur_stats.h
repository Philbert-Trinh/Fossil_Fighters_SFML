//
// Created by ptrinh8 on 4/29/2022.
//

#ifndef FOSSIL_FIGHTERS_VIVOSAUR_STATS_H
#define FOSSIL_FIGHTERS_VIVOSAUR_STATS_H
#include <string>
#include "vivosaur_names.h"
#include <ctime>


class Vivosaur_stats
{
private:
    std::string name_string;
    int total_hp = 30;
    int current_hp = 30;
    int atk = 99;
    int def = 99;
    int acc = 99;
    int spd = 99;

public:
    Vivosaur_stats();
    explicit Vivosaur_stats(vivosaur_names name_enum);
    static std::string set_name(vivosaur_names name_enum);
    void set_hp(int damage);
    void set_atk();
    void set_def();
    void set_acc();
    void set_spd();
    void take_damage();
    bool is_dead() const;
    std::string get_name();
    int get_total_hp() const;
    int get_current_hp() const;
    int get_attack() const;
    int get_defense() const;
    int get_accuracy() const;
    int get_speed() const;
};


#endif //FOSSIL_FIGHTERS_VIVOSAUR_STATS_H
