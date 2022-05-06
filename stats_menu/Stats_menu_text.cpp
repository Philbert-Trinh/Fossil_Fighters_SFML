//
// Created by ptrinh8 on 4/28/2022.
//

#include "Stats_menu_text.h"

sf::Font Stats_menu_text::font;

Stats_menu_text::Stats_menu_text()
{
    set_up_text();
}

void Stats_menu_text::set_up_text()
{
    if (!font.loadFromFile("Font/OpenSans-Bold.ttf"))
        exit(2);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
}

void Stats_menu_text::set_string(const std::string& string)
{
    text.setString(string);
}

void Stats_menu_text::position_name(Stats_menu_shape shape)
{
    float x = (shape.getGlobalBounds().left + shape.getGlobalBounds().width/2) - (text.getGlobalBounds().width/2);
    float y = (shape.getGlobalBounds().top + text.getCharacterSize()/2);
    text.setPosition(x,y);
}

void Stats_menu_text::position_HP(Stats_menu_shape shape)
{
    float x = (shape.getGlobalBounds().left + shape.getGlobalBounds().width/2) - (text.getGlobalBounds().width/2);
    float y = (shape.getGlobalBounds().top + shape.getGlobalBounds().height/7 + text.getCharacterSize());
    text.setPosition(x,y);
}

void Stats_menu_text::position_attack(Stats_menu_shape shape)
{
    float x = (shape.getGlobalBounds().left + (shape.getOutlineThickness()*2));
    float y = (shape.getGlobalBounds().top + shape.getGlobalBounds().height/3 + text.getCharacterSize());
    text.setPosition(x,y);
}

void Stats_menu_text::position_defense(Stats_menu_shape shape)
{
    float x = (shape.getGlobalBounds().left + shape.getGlobalBounds().width - (text.getGlobalBounds().width + (shape.getOutlineThickness()*2)));
    float y = (shape.getGlobalBounds().top + shape.getGlobalBounds().height/3 + text.getCharacterSize());
    text.setPosition(x,y);
}

void Stats_menu_text::position_accuracy(Stats_menu_shape shape)
{
    float x = (shape.getGlobalBounds().left + (shape.getOutlineThickness()*2));
    float y = ((shape.getGlobalBounds().top + shape.getGlobalBounds().height) - (text.getGlobalBounds().height + text.getCharacterSize()));
    text.setPosition(x,y);
}

void Stats_menu_text::position_speed(Stats_menu_shape shape)
{
    float x = (shape.getGlobalBounds().left + shape.getGlobalBounds().width - (text.getGlobalBounds().width + (shape.getOutlineThickness()*2)));
    float y = ((shape.getGlobalBounds().top + shape.getGlobalBounds().height) - (text.getGlobalBounds().height + text.getCharacterSize()));
    text.setPosition(x,y);
}

sf::FloatRect Stats_menu_text::getGlobalBounds()
{
    return text.getGlobalBounds();
}

void Stats_menu_text::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(text);
}


