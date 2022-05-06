//
// Created by ptrinh8 on 4/24/2022.
//

#include "Zone.h"

Zone::Zone()
{
    hex = create_hex();
    set_up_hex();
}

sf::CircleShape Zone::create_hex()
{
    return sf::CircleShape(150, 6);
}

void Zone::set_up_hex()
{
    hex.setOutlineColor(sf::Color::Black);
    hex.setOutlineThickness(0);
    hex.setOrigin(hex.getRadius(), hex.getRadius());
    hex.setScale(0.7, -0.4);
}

void Zone::set_fill_color(sf::Color color)
{
    hex.setFillColor(color);
}

void Zone::position_left(sf::RenderWindow &window)
{
    hex.setPosition(to_float(window.getSize().x / 2.0 - window.getSize().x / 10.0),
                    to_float(window.getSize().y / 2.0));
}

void Zone::position_right(sf::RenderWindow &window)
{
    hex.setPosition(to_float(window.getSize().x / 2.0 + window.getSize().x / 10.0),
                    to_float(window.getSize().y / 2.0));
}

void Zone::player_hex_position_top(Zone hex_zone)
{
    double x_offset = (hex.getRadius() * cos(M_PI / 6));
    double y_offset = (y_offset_calculation(hex.getRadius(), hex.getOutlineThickness()));
    hex.setPosition(to_float(hex_zone.get_x_position() - (x_offset + hex_zone.getOutlineThickness()) * hex_zone.get_x_scale()),
                    to_float(hex_zone.get_y_position() + (y_offset) * (hex_zone.get_y_scale())));
}

void Zone::player_hex_position_bottom(Zone hex_zone)
{
    double x_offset = (hex.getRadius() * cos(M_PI / 6));
    double y_offset = y_offset_calculation(hex.getRadius(), hex.getOutlineThickness());
    hex.setPosition(to_float(hex_zone.get_x_position() - (x_offset + hex_zone.getOutlineThickness()) * hex_zone.get_x_scale()),
                    to_float(hex_zone.get_y_position() - (y_offset) * (hex_zone.get_y_scale())));

}

void Zone::player_hex_position_behind(Zone hex_zone)
{
    double x_offset = to_float((2.0) * (hex.getRadius() * cos(M_PI / 6)));
    hex.setPosition(to_float(hex_zone.get_x_position() - ((x_offset + hex_zone.getOutlineThickness()) * 0.7)),
                    to_float(hex_zone.get_y_position()));
}

void Zone::enemy_hex_position_top(Zone hex_zone)
{
    double x_offset = (hex.getRadius() * cos(M_PI / 6));
    double y_offset = y_offset_calculation(hex.getRadius(), hex.getOutlineThickness());
    hex.setPosition(to_float(hex_zone.get_x_position() + (x_offset + hex_zone.getOutlineThickness()) * hex_zone.get_x_scale()),
                    to_float(hex_zone.get_y_position() + (y_offset) * (hex_zone.get_y_scale())));
}

void Zone::enemy_hex_position_bottom(Zone hex_zone)
{
    double x_offset = (hex.getRadius() * cos(M_PI / 6));
    double y_offset = y_offset_calculation(hex.getRadius(), hex.getOutlineThickness());
    hex.setPosition(to_float(hex_zone.get_x_position() + (x_offset + hex_zone.getOutlineThickness()) * hex_zone.get_x_scale()),
                    to_float(hex_zone.get_y_position() - (y_offset) * (hex_zone.get_y_scale())));
}

void Zone::enemy_hex_position_behind(Zone hex_zone)
{
    double x_offset = (2.0) * (hex.getRadius() * cos(M_PI / 6));
    hex.setPosition(to_float(hex_zone.get_x_position() + ((x_offset + hex_zone.getOutlineThickness()) * 0.7)),
                    to_float(hex_zone.get_y_position()));
}

float Zone::get_x_position()
{
    return hex.getPosition().x;
}

float Zone::get_y_position()
{
    return hex.getPosition().y;
}

float Zone::get_x_scale()
{
    return hex.getScale().x;
}

float Zone::get_y_scale()
{
    return hex.getScale().y;
}

void Zone::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(hex, states);
}

double Zone::y_offset_calculation(float radius, float outline_thickness)
{
    double z = pow(outline_thickness + (2 * (radius * cos(M_PI / 6))), 2);
    double x = pow(radius * cos(M_PI / 6), 2);
    double y = sqrt(z - x);
    return y;
}

float Zone::to_float(double number)
{
    return static_cast<float> (number);
}

sf::Vector2f Zone::get_origin()
{
    return hex.getOrigin();
}

void Zone::color_blue()
{
    set_fill_color(sf::Color::Blue);
}

void Zone::color_red()
{
    set_fill_color(sf::Color::Red);
}

void Zone::color_green()
{
    set_fill_color(sf::Color::Green);
}

sf::FloatRect Zone::get_global_bounds()
{
    return hex.getGlobalBounds();
}

