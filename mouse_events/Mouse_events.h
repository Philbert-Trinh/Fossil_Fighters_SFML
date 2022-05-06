//
// Created by ptrinh8 on 4/26/2022.
//

#ifndef FOSSIL_FIGHTERS_MOUSE_EVENTS_H
#define FOSSIL_FIGHTERS_MOUSE_EVENTS_H
#include <SFML/Graphics.hpp>

class Mouse_events
{
private:
public:
    static bool is_clicked(sf::Sprite &sprite, sf::RenderWindow &window);
    static bool is_hovered(sf::Sprite &sprite, sf::RenderWindow &window);
};


#endif //FOSSIL_FIGHTERS_MOUSE_EVENTS_H
