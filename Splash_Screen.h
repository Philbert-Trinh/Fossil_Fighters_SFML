//
// Created by ptrinh8 on 5/2/2022.
//

#ifndef FOSSIL_FIGHTERS_SPLASH_SCREEN_H
#define FOSSIL_FIGHTERS_SPLASH_SCREEN_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include "Mouse Events/Mouse_events.h"



class Splash_Screen: public sf::Sprite, public States
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Splash_Screen();
    Splash_Screen(sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void check_clicked();
    void event_handler(sf::Event event, sf::RenderWindow& window);

};


#endif //FOSSIL_FIGHTERS_SPLASH_SCREEN_H
