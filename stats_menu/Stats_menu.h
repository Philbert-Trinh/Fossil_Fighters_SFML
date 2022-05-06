//
// Created by ptrinh8 on 4/26/2022.
//

#ifndef FOSSIL_FIGHTERS_STATS_MENU_H
#define FOSSIL_FIGHTERS_STATS_MENU_H
#include <SFML/Graphics.hpp>
#include "Stats_menu_text.h"
#include "../States.h"
#include "../vivosaur/Complete_vivosaur.h"
#include <vector>


class Stats_menu: public sf::Drawable, public States
{
private:
    Stats_menu_shape shape;
    Stats_menu_text name;
    Stats_menu_text hp;
    Stats_menu_text atk;
    Stats_menu_text def;
    Stats_menu_text acc;
    Stats_menu_text spd;
    void set_strings(Complete_vivosaur vivosaur);
    void position(sf::RenderWindow& window);

public:
    Stats_menu();
    Stats_menu(Complete_vivosaur &vivosaur,sf::RenderWindow &window);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void update_health(Complete_vivosaur &vivosaur);
};


#endif //FOSSIL_FIGHTERS_STATS_MENU_H
