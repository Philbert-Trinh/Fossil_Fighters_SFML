//
// Created by ptrinh8 on 5/4/2022.
//

#include "Text_popups.h"
sf::Font Text_popups::font;

Text_popups::Text_popups()
{
    enableState(HIDDEN);
    set_up_text();
}


void Text_popups::set_up_text()
{
    if (!font.loadFromFile("Font/OpenSans-Bold.ttf"))
        exit(2);
    turn_text.setFont(font);
    turn_text.setCharacterSize(30);
    turn_text.setFillColor(sf::Color::Black);
    battle_text.setFont(font);
    battle_text.setCharacterSize(30);
    battle_text.setFillColor(sf::Color::Black);
}

void Text_popups::set_battle_string(const std::string &string)
{
    battle_text.setString(string);
}

void Text_popups::set_turn_string(const std::string &string)
{
    turn_text.setString(string);
}

void Text_popups::position_text(sf::RenderWindow &window)
{
    float x = (window.getSize().x/2-turn_text.getGlobalBounds().width/2);
    turn_text.setPosition(x,0);

    float z = (window.getSize().x/2-battle_text.getGlobalBounds().width/2);
    float y = (battle_text.getGlobalBounds().height);
    battle_text.setPosition(z,y);
}

void Text_popups::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!getState(HIDDEN))
    {
        window.draw(turn_text);
        window.draw(battle_text);
    }
}

void Text_popups::update(User_interface& UI,sf::RenderWindow& window, Complete_vivosaur &v1, Complete_vivosaur& v2, Complete_vivosaur&v3, Complete_vivosaur &e1, Complete_vivosaur& e2, Complete_vivosaur&e3)
{
    std::string temp;
    if(UI.getState(PLAYER_TURN))
    {
        set_turn_string("Player Turn");
    }

    if(UI.getState(ATTACK_ENGAGED))
    {
        set_battle_string("Attack Engaged: Select Attacker");
        if (v1.getState(ATTACKING))
        {
            temp += v1.get_name();
            temp += " is attacking";
            set_battle_string(temp);
        }
        else if(v2.getState(ATTACKING))
        {
            temp += v2.get_name();
            temp += " is attacking";
            set_battle_string(temp);
        }
        else if(v3.getState(ATTACKING))
        {
            temp += v3.get_name();
            temp += " is attacking";
            set_battle_string(temp);
        }

    }
    else if(UI.getState(SWAP_ENGAGED))
    {
        if (v1.getState(BEING_SWAPPED))
        {
            temp = v1.get_name();
            temp += "is moving to AZ";
            set_battle_string(temp);
        }
        else if (v2.getState(BEING_SWAPPED))
        {
            temp = v2.get_name();
            temp += "is moving to AZ";
            set_battle_string(temp);
        }
        else if (v3.getState(BEING_SWAPPED))
        {
            temp = v3.get_name();
            temp += "is moving to AZ";
            set_battle_string(temp);
        }
        else
        {
            set_battle_string("Swap Engaged, pick support zone Vivosaur");
        }

    }

    if(v1.getState(DORMANT) && v2.getState(DORMANT) && v3.getState(DORMANT))
    {
        set_turn_string("Enemy Turn: Vivosaur In Attack Zone Hit Three Times");
    }

    if(v1.getState(DEAD) && v2.getState(DEAD) && v3.getState(DEAD))
    {
        set_turn_string("Opponent Wins");
        set_battle_string("Game Over");
    }

    else if (e1.getState(DEAD) && e2.getState(DEAD) && e3.getState(DEAD))
    {
        set_turn_string("Player Wins");
        set_battle_string("Congratulations");
    }
    position_text(window);
}

