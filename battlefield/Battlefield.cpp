//
// Created by ptrinh8 on 4/21/2022.
//

#include "Battlefield.h"

Battlefield::Battlefield()= default;

Battlefield::Battlefield(sf::RenderWindow &window)
{
    enableState(HIDDEN);
    player_AZ.position_left(window);
    player_AZ.color_red();
    player_SZ_top.player_hex_position_top(player_AZ);
    player_SZ_top.color_blue();
    player_SZ_bottom.player_hex_position_bottom(player_AZ);
    player_SZ_bottom.color_blue();
    player_EZ.player_hex_position_behind(player_AZ);
    player_EZ.color_green();
    enemy_AZ.position_right(window);
    enemy_AZ.color_red();
    enemy_SZ_top.enemy_hex_position_top(enemy_AZ);
    enemy_SZ_top.color_blue();
    enemy_SZ_bottom.enemy_hex_position_bottom(enemy_AZ);
    enemy_SZ_bottom.color_blue();
    enemy_EZ.enemy_hex_position_behind(enemy_AZ);
    enemy_EZ.color_green();
}



void Battlefield::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if (!getState(HIDDEN))
    {
        states.transform = player_AZ.getTransform();
        window.draw(player_AZ);
        window.draw(player_EZ, states);
        window.draw(player_SZ_top, states);
        window.draw(player_SZ_bottom, states);
        window.draw(enemy_AZ);
        window.draw(enemy_SZ_top, states);
        window.draw(enemy_SZ_bottom, states);
        window.draw(enemy_EZ, states);
    }

}

Zone Battlefield::get_player_AZ_hex()
{
    return player_AZ;
}

Zone Battlefield::get_player_SZ_top_hex()
{
    return player_SZ_top;
}

Zone Battlefield::get_player_SZ_bottom_hex()
{
    return player_SZ_bottom;
}

Zone Battlefield::get_player_EZ_hex()
{
    return player_EZ;
}

Zone Battlefield::get_enemy_AZ_hex()
{
    return enemy_AZ;
}

Zone Battlefield::get_enemy_SZ_top_hex()
{
    return enemy_SZ_top;
}

Zone Battlefield::get_enemy_SZ_bottom_hex()
{
    return enemy_SZ_bottom;
}

Zone Battlefield::get_enemy_EZ_hex()
{
    return enemy_EZ;
}

sf::Vector2f Battlefield::get_hex_origin(Zone hex)
{
    return hex.get_origin();
}




