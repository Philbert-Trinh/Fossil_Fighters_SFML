//
// Created by ptrinh8 on 4/14/2022.
//

#ifndef CARD_VIVOSAUR_IMAGES_H
#define CARD_VIVOSAUR_IMAGES_H
#include <map>
#include "vivosaur_names.h"
#include <SFML/Graphics.hpp>

class Vivosaur_images
{
private:
    static std::map<vivosaur_names, sf::Texture> image;
    static std::string get_image_path(vivosaur_names name);
    static void load_image(vivosaur_names name);

public:
    static sf::Texture& get_image(vivosaur_names name);
};



#endif //CARD_VIVOSAUR_IMAGES_H
