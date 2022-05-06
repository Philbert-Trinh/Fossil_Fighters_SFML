//
// Created by ptrinh8 on 4/14/2022.
//

#include "Vivosaur_sprite.h"

Vivosaur_sprite::Vivosaur_sprite() = default;

Vivosaur_sprite::Vivosaur_sprite(vivosaur_names name_enum): name(name_enum)
{
    sprite.setTexture(Vivosaur_images::get_image(name));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height);
    sprite.scale(2, 2);
}

void Vivosaur_sprite::center_platform(Zone hex)
{
    original_x = hex.get_x_position();
    original_y = hex.get_y_position();
    sprite.setPosition(original_x,original_y);

}

void Vivosaur_sprite::player_idle()
{
    if (counter.getElapsedTime().asMilliseconds() > 100)
    {
        player_idle_shift();
        player_idle_move();
        counter.restart();
    }
}

void Vivosaur_sprite::enemy_idle()
{
    if (counter.getElapsedTime().asMilliseconds() > 100)
    {
        enemy_idle_shift();
        enemy_idle_move();
        counter.restart();
    }
}

void Vivosaur_sprite::player_idle_shift()
{
    switch (player_position)
    {
        case LEFT:
            player_position = STAND_STILL;
            break;
        case TOP:
            player_position = RIGHT;
            break;
        case RIGHT:
            player_position = BOTTOM;
            break;
        case BOTTOM:
            player_position = LEFT;
            break;
        case STAND_STILL:
            player_position = TOP;
            break;
    }
}

void Vivosaur_sprite::player_idle_move()
{
    switch (player_position)
    {
        case TOP:
            sprite.move(0, -10.0f);
            break;
        case RIGHT:
            sprite.move(20.0f, 0);
            break;
        case BOTTOM:
            sprite.move(0, 10.0f);
            break;
        case LEFT:
            sprite.move(-20.0f, 0);
            break;
        case STAND_STILL:
            while (counter.getElapsedTime().asMilliseconds() < 1000)
            {};
            break;
    }
}

void Vivosaur_sprite::enemy_idle_shift()
{
    switch (enemy_position)
    {
        case RIGHT:
            enemy_position = STAND_STILL;
            break;
        case LEFT:
            enemy_position = BOTTOM;
            break;
        case TOP:
            enemy_position = LEFT;
            break;
        case BOTTOM:
            enemy_position = RIGHT;
            break;
        case STAND_STILL:
            enemy_position = TOP;
            break;
    }
}

void Vivosaur_sprite::enemy_idle_move()
{
    switch (enemy_position)
    {
        case TOP:
            sprite.move(0, -10.0f);
            break;
        case RIGHT:
            sprite.move(20.0f, 0);
            break;
        case BOTTOM:
            sprite.move(0, 10.0f);
            break;
        case LEFT:
            sprite.move(-20.0f, 0);
            break;
        case STAND_STILL:
            while (counter.getElapsedTime().asMilliseconds() < 1000)
            {};
            break;
    }
}

void Vivosaur_sprite::flip()
{
    sprite.scale(-1, 1);
}

void Vivosaur_sprite::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if (!getState(DEAD) && !getState(HIDDEN))
    {
        window.draw(sprite, states);
    }
}

sf::Sprite& Vivosaur_sprite::get_sprite()
{
    return sprite;
}

sf::Vector2f Vivosaur_sprite::get_position()
{
    return sprite.getPosition();
}

sf::FloatRect Vivosaur_sprite::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

void Vivosaur_sprite::reset_player_position()
{
    sprite.setPosition(original_x,original_y);
    player_position = LEFT;
}

void Vivosaur_sprite::reset_enemy_position()
{
    sprite.setPosition(original_x,original_y);
    enemy_position = RIGHT;
}
