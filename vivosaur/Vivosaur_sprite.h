//
// Created by ptrinh8 on 4/14/2022.
//

#ifndef CARD_VIVOSAUR_SPRITE_H
#define CARD_VIVOSAUR_SPRITE_H
#include <SFML/Graphics.hpp>
#include "Vivosaur_images.h"
#include "vivosaur_names.h"
#include "Position.h"
#include "../States.h"
#include "../drawing_the_battlefield/Zone.h"


class Vivosaur_sprite: public sf::Drawable, public States
{
private:
    sf::Clock counter;
    positions player_position = LEFT;
    positions enemy_position = RIGHT;
    sf::Sprite sprite;
    vivosaur_names name;
    float original_x = 0;
    float original_y = 0;
    void player_idle_shift();
    void enemy_idle_shift();
    void player_idle_move();
    void enemy_idle_move();

public:
    Vivosaur_sprite();
    explicit Vivosaur_sprite(vivosaur_names name_enum);
    void center_platform(Zone hex);
    void player_idle();
    void enemy_idle();
    void flip();
    sf::Sprite &get_sprite();
    sf::Vector2f get_position();
    sf::FloatRect getGlobalBounds();
    void reset_player_position();
    void reset_enemy_position();
//    void player_push_back();
//    void enemy_push_back();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

};


#endif //CARD_VIVOSAUR_SPRITE_H
