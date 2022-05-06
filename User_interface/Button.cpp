//
// Created by ptrinh8 on 4/26/2022.
//

#include "Button.h"

Button::Button() : Button(SWAP)
{}

Button::Button(button_names name_enum) : name(name_enum)
{
    sprite.setTexture(Button_images::get_image(name));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    disableState(CLICKED);
    disableState(HIDDEN);
}

void Button::position_left(sf::RenderWindow& window)
{
    float x = static_cast<float>(window.getSize().x/2.0 - window.getSize().x/16.0);
    float y = static_cast<float>(window.getSize().y-(window.getSize().y/4.0));
    sprite.setPosition(x, y);
}

void Button::position_right(sf::RenderWindow& window)
{
    float x = static_cast<float>(window.getSize().x/2.0 + window.getSize().x/16.0);
    float y = static_cast<float>(window.getSize().y-(window.getSize().y/4.0));
    sprite.setPosition(x,y);
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if (!getState(HIDDEN))
    {
        window.draw(sprite);
    }

}

void Button::event_handler(sf::Event event, sf::RenderWindow& window)
{
    if(Mouse_events::is_clicked(sprite, window))
    {
        enableState(CLICKED);
        //while(Mouse_events::is_clicked(sprite, window));
    }
}
