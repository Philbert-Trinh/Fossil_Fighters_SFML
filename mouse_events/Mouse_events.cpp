//
// Created by ptrinh8 on 4/26/2022.
//

#include "Mouse_events.h"

bool Mouse_events::is_hovered(sf::Sprite &sprite, sf::RenderWindow &window)
{
    sf::Vector2f mouse_position = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(sprite.getGlobalBounds().contains(mouse_position))
    {
        return true;
    }
    return false;
}

bool Mouse_events::is_clicked(sf::Sprite &sprite, sf::RenderWindow &window)
{
    if (is_hovered(sprite, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }
    return false;
}

