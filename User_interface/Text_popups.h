//
// Created by ptrinh8 on 5/4/2022.
//

#ifndef FOSSIL_FIGHTERS_TEXT_POPUPS_H
#define FOSSIL_FIGHTERS_TEXT_POPUPS_H
#include <SFML\Graphics.hpp>
#include "../vivosaur/Complete_vivosaur.h"
#include "User_interface.h"
#include "../States.h"

class Text_popups: public sf::Drawable, public States
{
private:
    static sf::Font font;
    sf::Text turn_text;
    sf::Text battle_text;

public:
    Text_popups();
    void set_up_text();
    void set_battle_string(const std::string& string);
    void set_turn_string(const std::string& string);
    void position_text(sf::RenderWindow& window);
    void update(User_interface& UI, sf::RenderWindow& window, Complete_vivosaur &v1, Complete_vivosaur& v2, Complete_vivosaur&v3,  Complete_vivosaur &e1, Complete_vivosaur& e2, Complete_vivosaur&e3);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //FOSSIL_FIGHTERS_TEXT_POPUPS_H
