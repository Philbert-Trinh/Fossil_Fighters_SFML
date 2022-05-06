//
// Created by ptrinh8 on 4/24/2022.
//

#ifndef FOSSIL_FIGHTERS_ZONE_H
#define FOSSIL_FIGHTERS_ZONE_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Zone.h"

class Zone: public sf::CircleShape
{
private:
    sf::CircleShape hex;
    static double y_offset_calculation(float radius,float outline_thickness);
    void set_up_hex();
    static float to_float(double number);

public:
    Zone();
    static sf::CircleShape create_hex();
    void set_fill_color(sf::Color color);
    void position_left(sf::RenderWindow& window);
    void position_right(sf::RenderWindow& window);
    void player_hex_position_top(Zone hex_zone);
    void player_hex_position_bottom(Zone hex_zone);
    void player_hex_position_behind(Zone hex_zone);
    void enemy_hex_position_top(Zone hex_zone);
    void enemy_hex_position_bottom(Zone hex_zone);
    void enemy_hex_position_behind(Zone hex_zone);
    float get_x_position();
    float get_y_position();
    float get_x_scale();
    float get_y_scale();
    sf::Vector2f get_origin();
    void color_blue();
    void color_red();
    void color_green();
    sf::FloatRect get_global_bounds();

   virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //FOSSIL_FIGHTERS_ZONE_H
