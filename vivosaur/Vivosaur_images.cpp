//
// Created by ptrinh8 on 4/14/2022.
//

#include "Vivosaur_images.h"
std::map<vivosaur_names, sf::Texture> Vivosaur_images::image;

std::string Vivosaur_images::get_image_path(vivosaur_names name)
{
    switch (name)
    {
        case DUNA:
            return "Fossil Fighters Battle Sprites/Duna.png";
        case TYRANNO:
            return "Fossil Fighters Battle Sprites/T-Rex.png";
        case BRACHIO:
            return "Fossil Fighters Battle Sprites/Brachio.png";
        case AOPTERYX:
            return "Fossil Fighters Battle Sprites/Aopteryx.png";
        case TRICERA:
            return "Fossil Fighters Battle Sprites/Tricera.png";
        case STEGO:
            return "Fossil Fighters Battle Sprites/Stego.png";
    }
}

void Vivosaur_images::load_image(vivosaur_names name)
{
    image[name].loadFromFile(get_image_path(name));
}

sf::Texture &Vivosaur_images::get_image(vivosaur_names name)
{
    load_image(name);
    return image[name];
}
