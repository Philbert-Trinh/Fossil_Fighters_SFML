//
// Created by ptrinh8 on 4/26/2022.
//

#include "Button_images.h"
std::map<button_names, sf::Texture> Button_images::image;

std::string Button_images::get_image_path(button_names name)
{
    switch (name)
    {
        case ATTACK:
            return "Buttons/Attack Button.png";
        case SWAP:
            return "Buttons/Swap Button.png";
    }
}

void Button_images::load_image(button_names name)
{
    image[name].loadFromFile(get_image_path(name));
}

sf::Texture &Button_images::get_image(button_names name)
{
    load_image(name);
    return image[name];
}
