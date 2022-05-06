//
// Created by ptrinh8 on 4/28/2022.
//

#ifndef FOSSIL_FIGHTERS_STATS_MENU_TEXT_H
#define FOSSIL_FIGHTERS_STATS_MENU_TEXT_H

#include <SFML/Graphics.hpp>
#include "Stats_menu_shape.h"


class Stats_menu_text : public sf::Drawable
{
private:
    static sf::Font font;
    sf::Text text;

public:
    Stats_menu_text();

    void set_up_text();

    void set_string(const std::string& string);

    void position_name(Stats_menu_shape shape);

    void position_HP(Stats_menu_shape shape);

    void position_attack(Stats_menu_shape shape);

    void position_defense(Stats_menu_shape shape);

    void position_accuracy(Stats_menu_shape shape);

    void position_speed(Stats_menu_shape shape);

    sf::FloatRect getGlobalBounds();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

};


#endif //FOSSIL_FIGHTERS_STATS_MENU_TEXT_H
