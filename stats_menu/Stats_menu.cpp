//
// Created by ptrinh8 on 4/26/2022.
//

#include "Stats_menu.h"
Stats_menu::Stats_menu() = default;

Stats_menu::Stats_menu(Complete_vivosaur &vivosaur, sf::RenderWindow& window)
{
    set_strings(vivosaur);
    position(window);
    enableState(HIDDEN);
    disableState(DORMANT);
}

void Stats_menu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if (!getState(HIDDEN) && !getState(DORMANT))
    {
        window.draw(shape);
        window.draw(name);
        window.draw(hp);
        window.draw(atk);
        window.draw(def);
        window.draw(acc);
        window.draw(spd);
    }
}

void Stats_menu::set_strings(Complete_vivosaur vivosaur)
{
    std::string temp;
    temp += "HP: ";
    temp += std::to_string(vivosaur.get_current_hp());
    temp += "/";
    temp += std::to_string(vivosaur.get_total_hp());
    hp.set_string(temp);
    name.set_string(vivosaur.get_name());

    temp = "ATK: ";
    temp += std::to_string(vivosaur.get_attack());
    atk.set_string(temp);

    temp = "DEF: ";
    temp += std::to_string(vivosaur.get_defense());
    def.set_string(temp);

    temp = "ACC: ";
    temp += std::to_string(vivosaur.get_accuracy());
    acc.set_string(temp);

    temp = "SPD: ";
    temp += std::to_string(vivosaur.get_speed());
    spd.set_string(temp);
}

void Stats_menu::position(sf::RenderWindow& window)
{
    shape.set_position(window);
    name.position_name(shape);
    hp.position_HP(shape);
    atk.position_attack(shape);
    def.position_defense(shape);
    acc.position_accuracy(shape);
    spd.position_speed(shape);
}

void Stats_menu::update_health(Complete_vivosaur& vivosaur)
{
    std::string temp;
    temp += "HP: ";
    temp += std::to_string(vivosaur.get_current_hp());
    temp += "/";
    temp += std::to_string(vivosaur.get_total_hp());
    hp.set_string(temp);
}

