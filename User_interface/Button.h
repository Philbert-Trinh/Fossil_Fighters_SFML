//
// Created by ptrinh8 on 4/26/2022.
//

#ifndef FOSSIL_FIGHTERS_BUTTON_H
#define FOSSIL_FIGHTERS_BUTTON_H
#include <SFML/Graphics.hpp>
#include "Button_images.h"
#include "../States.h"
#include "../Mouse Events/Mouse_events.h"
#include <iostream>

class Button : public sf::Drawable, public States
{
private:
    button_names name;
    sf::Sprite sprite;

public:
    Button();
    explicit Button(button_names name_enum);
    void position_left(sf::RenderWindow& window);
    void position_right(sf::RenderWindow& window);
    void event_handler(sf::Event event, sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //FOSSIL_FIGHTERS_BUTTON_H
