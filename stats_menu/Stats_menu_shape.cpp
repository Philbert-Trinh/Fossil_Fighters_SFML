//
// Created by ptrinh8 on 4/28/2022.
//

#include "Stats_menu_shape.h"

Stats_menu_shape::Stats_menu_shape()
{
    menu_shape.setSize(sf::Vector2f(250, 200));
    menu_shape.setOutlineColor(sf::Color::Black);
    menu_shape.setFillColor(sf::Color::White);
    menu_shape.setOutlineThickness(5);
    menu_shape.setOrigin(menu_shape.getGlobalBounds().width / 2, menu_shape.getGlobalBounds().height / 2);
}

void Stats_menu_shape::set_position(sf::RenderWindow &window)
{
    menu_shape.setPosition((window.getSize().x / 2.0) + 2,
    window.getSize().y - menu_shape.getGlobalBounds().height -(menu_shape.getOutlineThickness() * 2));
}

sf::FloatRect Stats_menu_shape::getGlobalBounds()
{
    return menu_shape.getGlobalBounds();
}

void Stats_menu_shape::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(menu_shape);
}

int Stats_menu_shape::getOutlineThickness()
{
    return menu_shape.getOutlineThickness();
}


