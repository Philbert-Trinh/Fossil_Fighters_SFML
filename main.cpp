#include <SFML/Graphics.hpp>
#include "vivosaur/Complete_vivosaur.h"
#include "drawing_the_battlefield/Battlefield.h"
#include "UI/User_interface.h"
#include "Splash_Screen.h"
#include "UI/Text_popups.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode{1600, 900, 64}, "DS_Screen");
    window.setFramerateLimit(30);
    window.setKeyRepeatEnabled(false);
    Splash_Screen splash(window);
    Text_popups popup;

    Complete_vivosaur Duna(DUNA);
    Complete_vivosaur Tyranno(TYRANNO);
    Complete_vivosaur Brachio(BRACHIO);

    Complete_vivosaur Stego(STEGO);
    Complete_vivosaur Tricera(TRICERA);
    Complete_vivosaur Aopteryx(AOPTERYX);
    User_interface UI(Duna, Tyranno, Brachio, window);

    Stego.flip();
    Tricera.flip();
    Aopteryx.flip();

    Battlefield background(window);

    Duna.center_platform(background.get_player_AZ_hex());
    Duna.enableState(IN_AZ);
    Tyranno.center_platform(background.get_player_SZ_bottom_hex());
    Tyranno.enableState(IN_SZ);
    Brachio.center_platform(background.get_player_SZ_top_hex());
    Brachio.enableState(IN_SZ);
    Stego.center_platform(background.get_enemy_AZ_hex());
    Stego.enableState(IN_AZ);
    Stego.enableState(ENEMY);
    Tricera.center_platform(background.get_enemy_SZ_top_hex());
    Tricera.enableState(IN_SZ);
    Tricera.enableState(ENEMY);
    Aopteryx.center_platform(background.get_enemy_SZ_bottom_hex());
    Aopteryx.enableState(IN_SZ);
    Aopteryx.enableState(ENEMY);
    User_interface::all_enemy_position_reset(Duna, Tyranno, Brachio);
    User_interface::all_player_position_reset(Stego, Tricera, Aopteryx);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            splash.event_handler(event,window);
        }
        popup.update(UI, window, Duna, Tyranno, Brachio, Stego, Tricera, Aopteryx);
        UI.event_handler(Duna, Tyranno, Brachio, Stego, Tricera, Aopteryx, event, window, background);

        if (splash.getState(CLICKED))
        {
            background.disableState(HIDDEN);
            UI.disableState(HIDDEN);
            Duna.disableState(HIDDEN);
            Tyranno.disableState(HIDDEN);
            Brachio.disableState(HIDDEN);
            Tricera.disableState(HIDDEN);
            Stego.disableState(HIDDEN);
            Aopteryx.disableState(HIDDEN);
            popup.disableState(HIDDEN);
            splash.enableState(HIDDEN);
        }

        Duna.player_idle_check();
        Tyranno.player_idle_check();
        Brachio.player_idle_check();
        Tricera.enemy_idle_check();
        Stego.enemy_idle_check();
        Aopteryx.enemy_idle_check();

        window.clear(sf::Color::White);
        window.draw(popup);
        window.draw(background);
        window.draw(Stego);
        window.draw(Tricera);
        window.draw(Aopteryx);
        window.draw(Tyranno);
        window.draw(Duna);
        window.draw(Brachio);
        window.draw(UI);
        window.draw(splash);
        window.display();
    }
}

