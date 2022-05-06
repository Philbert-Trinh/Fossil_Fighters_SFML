//
// Created by ptrinh8 on 5/2/2022.
//

#include "Splash_Screen.h"

Splash_Screen::Splash_Screen()=default;

Splash_Screen::Splash_Screen(sf::RenderWindow &window)
{
    disableState(CLICKED);
    texture.loadFromFile("Fossil_Fighters_logo.png");
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    sprite.setScale(3,3);
    sprite.setPosition(window.getSize().x/2, window.getSize().y/2);
}

void Splash_Screen::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if (!getState(CLICKED) || !getState(HIDDEN))
    {
        window.draw(sprite);
    }
}

void Splash_Screen::event_handler(sf::Event event, sf::RenderWindow &window)
{
    if(Mouse_events::is_clicked(sprite, window))
    {
        enableState(CLICKED);
    }
}

