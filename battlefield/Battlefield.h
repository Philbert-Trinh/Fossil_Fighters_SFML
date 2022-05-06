//
// Created by ptrinh8 on 4/21/2022.
//

#ifndef FOSSIL_FIGHTERS_BATTLEFIELD_H
#define FOSSIL_FIGHTERS_BATTLEFIELD_H
#include <SFML/Graphics.hpp>
#include "Zone.h"
#include <queue>
#include "../States.h"

class Battlefield : public sf::CircleShape, public States
{
private:
    Zone player_AZ;
    Zone player_EZ;
    Zone player_SZ_top;
    Zone player_SZ_bottom;
    Zone enemy_AZ;
    Zone enemy_EZ;
    Zone enemy_SZ_top;
    Zone enemy_SZ_bottom;

public:
    Battlefield();
    explicit Battlefield(sf::RenderWindow& window);
    Zone get_player_AZ_hex();
    Zone get_player_SZ_top_hex();
    Zone get_player_SZ_bottom_hex();
    Zone get_player_EZ_hex();
    Zone get_enemy_AZ_hex();
    Zone get_enemy_SZ_top_hex();
    Zone get_enemy_SZ_bottom_hex();
    Zone get_enemy_EZ_hex();
    static sf::Vector2f get_hex_origin(Zone hex);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //FOSSIL_FIGHTERS_BATTLEFIELD_H
