//
// Created by ptrinh8 on 4/28/2022.
//

#ifndef FOSSIL_FIGHTERS_STATS_MENU_SHAPE_H
#define FOSSIL_FIGHTERS_STATS_MENU_SHAPE_H
#include <SFML/Graphics.hpp>

class Stats_menu_shape: public sf::Drawable
{
private:
    sf::RectangleShape menu_shape;
public:
    Stats_menu_shape();
    void set_position(sf::RenderWindow& window);
    int getOutlineThickness();
    sf::FloatRect getGlobalBounds();
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //FOSSIL_FIGHTERS_STATS_MENU_SHAPE_H
