//
// Created by ptrinh8 on 4/26/2022.
//

#ifndef FOSSIL_FIGHTERS_BUTTON_IMAGES_H
#define FOSSIL_FIGHTERS_BUTTON_IMAGES_H
#include <map>
#include "button_names.h"
#include <SFML/Graphics.hpp>

class Button_images
{
private:
    static std::map<button_names, sf::Texture> image;
    static std::string get_image_path(button_names name);
    static void load_image(button_names name);

public:
    static sf::Texture& get_image(button_names name);
};


#endif //FOSSIL_FIGHTERS_BUTTON_IMAGES_H
