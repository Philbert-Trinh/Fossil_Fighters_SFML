//
// Created by ptrinh8 on 4/26/2022.
//

#ifndef FOSSIL_FIGHTERS_USER_INTERFACE_H
#define FOSSIL_FIGHTERS_USER_INTERFACE_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "../Stats Menu/Stats_menu.h"
#include "../vivosaur/Complete_vivosaur.h"
#include "fight_mechanic.h"
#include <queue>
#include "../drawing_the_battlefield/Battlefield.h"


class User_interface : public sf::Drawable, public States
{
private:
    fight_mechanic fight;
    sf::Clock time;
    Button swap;
    Button attack;
    Stats_menu stats_menu_1;
    Stats_menu stats_menu_2;
    Stats_menu stats_menu_3;
    std::queue<int> turns;
    int counter= 0;


public:
    User_interface();
    User_interface(Complete_vivosaur &v1, Complete_vivosaur &v2, Complete_vivosaur &v3, sf::RenderWindow &window);
    void event_handler(Complete_vivosaur &v1, Complete_vivosaur &v2, Complete_vivosaur &v3,
                       Complete_vivosaur &e1, Complete_vivosaur &e2, Complete_vivosaur &e3,
                       sf::Event event, sf::RenderWindow &window, Battlefield& background);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void turn_system();
    void target_any(Complete_vivosaur& v, Complete_vivosaur& e1,Complete_vivosaur& e2,Complete_vivosaur& e3, sf::RenderWindow& window);
    void target_az(Complete_vivosaur &v, Complete_vivosaur &e);
    void hide_both_buttons();
    void show_both_buttons();
    static void select_target(Complete_vivosaur& attacker, Complete_vivosaur &enemy_1, Complete_vivosaur &enemy_2, Complete_vivosaur &enemy_3,sf::RenderWindow &window);
    static void dormant_menu(Stats_menu& menu);
    void hide_all_menus();
    void disable_attack(Complete_vivosaur &v);
    void SZ_attack(Complete_vivosaur &SZ_attacker, Complete_vivosaur& AZ_enemy, Stats_menu& attacker_menu);
    void swap_function(Complete_vivosaur & AZ_V, Complete_vivosaur & SZ_V,  Battlefield& background);
    static void all_player_position_reset(Complete_vivosaur &v1, Complete_vivosaur &v2, Complete_vivosaur &v3);
    static void all_enemy_position_reset(Complete_vivosaur &e1, Complete_vivosaur &e2, Complete_vivosaur &e3);



};


#endif //FOSSIL_FIGHTERS_USER_INTERFACE_H
