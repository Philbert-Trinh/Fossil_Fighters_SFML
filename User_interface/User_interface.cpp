//
// Created by ptrinh8 on 4/26/2022.
//

#include "User_interface.h"

User_interface::User_interface() = default;

User_interface::User_interface(Complete_vivosaur& v1, Complete_vivosaur& v2, Complete_vivosaur& v3, sf::RenderWindow &window):
attack(ATTACK), swap(SWAP), stats_menu_1(v1, window), stats_menu_2(v2, window), stats_menu_3(v3, window)
{
    enableState(HIDDEN);
    attack.position_right(window);
    swap.position_left(window);
    swap.enableState(TOGGLE_SWAP);
    turns.push(2);
    turns.push(1);
    enableState(SHOW_ON_HOVER);
    enableState(PLAYER_TURN);
}

void User_interface::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(!getState(HIDDEN))
    {
        window.draw(stats_menu_1);
        window.draw(stats_menu_2);
        window.draw(stats_menu_3);
        window.draw(attack);
        window.draw(swap);
    }
}

void User_interface::event_handler(Complete_vivosaur& v1, Complete_vivosaur& v2, Complete_vivosaur& v3, Complete_vivosaur& e1, Complete_vivosaur& e2, Complete_vivosaur& e3, sf::Event event, sf::RenderWindow &window, Battlefield& background)
{
    swap.event_handler(event, window);
    attack.event_handler(event, window);

    if (getState(PLAYER_TURN))
    {
        all_player_position_reset(v1,v2,v3);
        show_both_buttons();
        enableState(SHOW_ON_HOVER);
        e1.enableState(DORMANT);
        e2.enableState(DORMANT);
        e3.enableState(DORMANT);
        stats_menu_1.disableState(DORMANT);
        stats_menu_2.disableState(DORMANT);
        stats_menu_3.disableState(DORMANT);
        disableState(PLAYER_TURN);
    }

    else if (getState(AI_TURN))
    {
        if(v1.getState(IN_EZ) || v2.getState(IN_EZ) || v3.getState(IN_EZ)&&
          !v1.getState(DEAD) || !v2.getState(DEAD) || !v3.getState(DEAD))
            counter++;

        disableState(AI_TURN);
        if (v1.getState(IN_AZ) && !v1.getState(DEAD))
        {
            target_az(e1,v1);
            e1.enableState(TURN_OVER);
            target_az(e2, v1);
            e2.enableState(TURN_OVER);
            target_az(e3,v1);
            e3.enableState(TURN_OVER);
            stats_menu_1.update_health(v1);
        }
        else if (v2.getState(IN_AZ)&&!v2.getState(DEAD))
        {
            target_az(e1,v2);
            e1.enableState(TURN_OVER);
            target_az(e2, v2);
            e2.enableState(TURN_OVER);
            target_az(e3,v2);
            e3.enableState(TURN_OVER);
            stats_menu_2.update_health(v2);
        }
        else if(v3.getState(IN_AZ)&& !v3.getState(DEAD))
        {
            target_az(e1,v3);
            e1.enableState(TURN_OVER);
            target_az(e2, v3);
            e2.enableState(TURN_OVER);
            target_az(e3,v3);
            e3.enableState(TURN_OVER);
            stats_menu_3.update_health(v3);
        }
    }

    if (swap.getState(CLICKED) && swap.getState(TOGGLE_SWAP))
    {
        hide_both_buttons();
        swap.enableState(ENGAGED);
        if(v1.getState(IN_AZ))
            dormant_menu(stats_menu_1);
        else if (v2.getState(IN_AZ))
            dormant_menu(stats_menu_2);
        else if (v3.getState(IN_AZ))
            dormant_menu(stats_menu_3);
        enableState(SWAP_ENGAGED);
    }

    else if (attack.getState(CLICKED))
    {
        hide_both_buttons();
        attack.enableState(ENGAGED);
        enableState(ATTACK_ENGAGED);
    }
    else
    {
        swap.disableState(TOGGLE_SWAP);
        attack.disableState(HIDDEN);
    }

    if(getState(SHOW_ON_HOVER) && (attack.getState(ENGAGED)||swap.getState(ENGAGED)))
    {
        if (Mouse_events::is_hovered(v1.get_sprite(), window))
        {
            stats_menu_1.disableState(HIDDEN);
            stats_menu_2.enableState(HIDDEN);
            stats_menu_3.enableState(HIDDEN);
        }

        else if (Mouse_events::is_hovered(v2.get_sprite(), window))
        {
            stats_menu_1.enableState(HIDDEN);
            stats_menu_2.disableState(HIDDEN);
            stats_menu_3.enableState(HIDDEN);
        }

        else if (Mouse_events::is_hovered(v3.get_sprite(), window))
        {
            stats_menu_1.enableState(HIDDEN);
            stats_menu_2.enableState(HIDDEN);
            stats_menu_3.disableState(HIDDEN);
        }
    }

    if (Mouse_events::is_clicked(v1.get_sprite(), window) && swap.getState(ENGAGED) && (v1.getState(IN_SZ)))
    {
        v1.enableState(BEING_SWAPPED);
        if (v2.getState(IN_AZ))
            swap_function(v2, v1, background);
        else if (v3.getState(IN_AZ))
            swap_function(v3, v1, background);

        all_player_position_reset(v1,v2,v3);
        all_enemy_position_reset(e1,e2,e3);
    }

    else if (Mouse_events::is_clicked(v2.get_sprite(), window) && swap.getState(ENGAGED) && (v2.getState(IN_SZ)))
    {
        v2.enableState(BEING_SWAPPED);
        if (v1.getState(IN_AZ))
            swap_function(v1, v2, background);
        else if (v3.getState(IN_AZ))
            swap_function(v3, v2, background);

        all_player_position_reset(v1,v2,v3);
        all_enemy_position_reset(e1,e2,e3);
    }

    else if (Mouse_events::is_clicked(v3.get_sprite(), window) && swap.getState(ENGAGED) && (v3.getState(IN_SZ)))
    {
        v3.enableState(BEING_SWAPPED);
        if (v2.getState(IN_AZ))
            swap_function(v2, v3, background);
        else if (v1.getState(IN_AZ))
            swap_function(v1, v3, background);

        all_player_position_reset(v1,v2,v3);
        all_enemy_position_reset(e1,e2,e3);
    }

    else if (Mouse_events::is_clicked(v1.get_sprite(), window) && attack.getState(ENGAGED) && !v2.getState(ATTACKING) && !v3.getState(ATTACKING) && !v1.getState(TURN_OVER))
    {
        disableState(SHOW_ON_HOVER);
        v1.enableState(CLICKED);
        v1.enableState(ATTACKING);
        v1.reset_player_position();
    }

    else if (Mouse_events::is_clicked(v2.get_sprite(), window) && attack.getState(ENGAGED)  && !v1.getState(ATTACKING) && !v3.getState(ATTACKING) && !v2.getState(TURN_OVER) )
    {
        disableState(SHOW_ON_HOVER);
        v2.enableState(CLICKED);
        v2.enableState(ATTACKING);
        v2.reset_player_position();
    }

    else if (Mouse_events::is_clicked(v3.get_sprite(), window) && attack.getState(ENGAGED) && !v2.getState(ATTACKING) && !v1.getState(ATTACKING) && !v3.getState(TURN_OVER))
    {
        disableState(SHOW_ON_HOVER);
        v3.enableState(CLICKED);
        v3.enableState(ATTACKING);
        v3.reset_player_position();
    }

    if (v1.getState(IN_AZ) && v1.getState(ATTACKING))
    {
        select_target(v1,e1,e2,e3,window);
    }

    else if (v2.getState(IN_AZ) && v2.getState(ATTACKING))
    {
        select_target(v2, e1, e2, e3, window);
    }

    else if (v3.getState(IN_AZ) && v3.getState(ATTACKING))
    {
        select_target(v3, e1, e2, e3, window);
    }

    else if (v1.getState(IN_SZ) && v1.getState(ATTACKING))
    {
        if (e1.getState(IN_AZ))
            SZ_attack(v1, e1, stats_menu_1);
        else if (e2.getState(IN_AZ))
            SZ_attack(v1,e2,stats_menu_1);
        else if (e3.getState(IN_AZ))
            SZ_attack(v1,e3,stats_menu_1);
    }

    else if (v2.getState(IN_SZ) && v2.getState(ATTACKING))
    {
        if (e1.getState(IN_AZ))
            SZ_attack(v2, e1, stats_menu_2);
        else if (e2.getState(IN_AZ))
            SZ_attack(v2,e2,stats_menu_2);
        else if (e3.getState(IN_AZ))
            SZ_attack(v2,e3,stats_menu_2);
    }

    else if (v3.getState(IN_SZ) && v3.getState(ATTACKING))
    {
        if (e1.getState(IN_AZ))
            SZ_attack(v3, e1, stats_menu_3);
        else if (e2.getState(IN_AZ))
            SZ_attack(v3,e2,stats_menu_3);
        else if (e3.getState(IN_AZ))
            SZ_attack(v3,e3,stats_menu_3);
    }

    if (v1.getState(ENGAGED))
    {
        target_any(v1, e1, e2, e3, window);
        dormant_menu(stats_menu_1);
    }

    else if (v2.getState(ENGAGED))
    {
        target_any(v2, e1, e2, e3, window);
        dormant_menu(stats_menu_2);
    }

    else if (v3.getState(ENGAGED))
    {
        target_any(v3, e1, e2, e3, window);
        dormant_menu(stats_menu_3);
    }

    if(v1.getState(IN_EZ) || v2.getState(IN_EZ) || v3.getState(IN_EZ))
    {
        if (v1.getState(IN_EZ))
        {
            v1.enableState(DORMANT);
            v1.enableState(TURN_OVER);
            dormant_menu(stats_menu_1);
            if (!background.get_player_SZ_top_hex().get_global_bounds().contains(v2.get_position()) &&
                !background.get_player_SZ_top_hex().get_global_bounds().contains(v3.get_position()) &&
                counter==2)
            {
                v1.center_platform(background.get_player_SZ_top_hex());
                v1.disableState(DORMANT);
                v1.disableState(TURN_OVER);
                v1.disableState(IN_EZ);
                v1.enableState(IN_SZ);
                stats_menu_1.disableState(DORMANT);
                counter=0;
            }
            else if (!background.get_player_SZ_bottom_hex().get_global_bounds().contains(v2.get_position())&&
                    !background.get_player_SZ_bottom_hex().get_global_bounds().contains(v3.get_position())&&
                    counter==2)
            {
                v1.center_platform(background.get_player_SZ_bottom_hex());
                v1.disableState(DORMANT);
                v1.disableState(TURN_OVER);
                v1.disableState(IN_EZ);
                v1.enableState(IN_SZ);
                stats_menu_1.disableState(DORMANT);
                counter=0;
            }

        }

        else if (v2.getState(IN_EZ))
        {
            v2.enableState(DORMANT);
            v2.enableState(TURN_OVER);
            dormant_menu(stats_menu_2);
            if (!background.get_player_SZ_top_hex().get_global_bounds().contains(v1.get_position()) &&
                !background.get_player_SZ_top_hex().get_global_bounds().contains(v3.get_position()) &&
                counter==2)
            {
                v2.center_platform(background.get_player_SZ_top_hex());
                v2.disableState(DORMANT);
                v2.disableState(TURN_OVER);
                v2.disableState(IN_EZ);
                v2.enableState(IN_SZ);
                stats_menu_2.disableState(DORMANT);
                counter=0;
            }
            else if (!background.get_player_SZ_bottom_hex().get_global_bounds().contains(v1.get_position())&&
                     !background.get_player_SZ_bottom_hex().get_global_bounds().contains(v3.get_position())&&
                     counter==2)
            {
                v2.center_platform(background.get_player_SZ_bottom_hex());
                v2.disableState(DORMANT);
                v2.disableState(TURN_OVER);
                v2.disableState(IN_EZ);
                v2.enableState(IN_SZ);
                stats_menu_2.disableState(DORMANT);
                counter=0;
            }
        }

        else if (v3.getState(IN_EZ))
        {
            v3.enableState(TURN_OVER);
            v3.enableState(DORMANT);
            dormant_menu(stats_menu_3);
            if (!background.get_player_SZ_top_hex().getGlobalBounds().contains(v2.get_position()) &&
                !background.get_player_SZ_top_hex().getGlobalBounds().contains(v1.get_position()) &&
                counter==2)
            {
                v3.center_platform(background.get_player_SZ_top_hex());
                v3.disableState(DORMANT);
                v3.disableState(TURN_OVER);
                v3.disableState(IN_EZ);
                v3.enableState(IN_SZ);
                stats_menu_3.disableState(DORMANT);
                counter=0;
            }
            else if (!background.get_player_SZ_bottom_hex().getGlobalBounds().contains(v2.get_position())&&
                     !background.get_player_SZ_bottom_hex().getGlobalBounds().contains(v1.get_position())&&
                     counter==2)
            {
                v3.center_platform(background.get_player_SZ_bottom_hex());
                v3.disableState(DORMANT);
                v3.disableState(TURN_OVER);
                v3.disableState(IN_EZ);
                v3.enableState(IN_SZ);
                stats_menu_3.disableState(DORMANT);
                counter=0;
            }
        }
    }

    if (v1.getState(TURN_OVER) && v2.getState(TURN_OVER) && v3.getState(TURN_OVER))
    {
        hide_both_buttons();
        e1.disableState(DORMANT);
        e2.disableState(DORMANT);
        e3.disableState(DORMANT);
        v1.disableState(TURN_OVER);
        v2.disableState(TURN_OVER);
        v3.disableState(TURN_OVER);
        turn_system();
    }

    else if(e1.getState(TURN_OVER) && e2.getState(TURN_OVER) && e3.getState(TURN_OVER))
    {
        v1.disableState(DORMANT);
        v2.disableState(DORMANT);
        v3.disableState(DORMANT);
        e1.disableState(TURN_OVER);
        e2.disableState(TURN_OVER);
        e3.disableState(TURN_OVER);
        turn_system();
    }

    if(v1.getState(IN_AZ) && v1.getState(DEAD))
    {
        v1.enableState(TURN_OVER);
        if(v2.getState(IN_SZ) && !v2.getState(DEAD))
        {
            v2.enableState(BEING_SWAPPED);
            swap_function(v1,v2,background);
        }
        else if (v3.getState(IN_SZ) && !v3.getState(DEAD))
        {
            v3.enableState(BEING_SWAPPED);
            swap_function(v1,v3,background);
        }
    }

    else if (v2.getState(IN_AZ) && v2.getState(DEAD))
    {
        v2.enableState(TURN_OVER);
        if(v1.getState(IN_SZ) && !v1.getState(DEAD))
        {
            v1.enableState(BEING_SWAPPED);
            swap_function(v2,v1,background);
        }
        else if (v3.getState(IN_SZ) && !v3.getState(DEAD))
        {
            v3.enableState(BEING_SWAPPED);
            swap_function(v2,v3,background);
        }
    }

    else if (v3.getState(IN_AZ) && v3.getState(DEAD))
    {
        v3.enableState(TURN_OVER);
        if(v2.getState(IN_SZ) && !v2.getState(DEAD))
        {
            v2.enableState(BEING_SWAPPED);
            swap_function(v3,v2,background);
        }
        else if (v1.getState(IN_SZ) && !v1.getState(DEAD))
        {
            v1.enableState(BEING_SWAPPED);
            swap_function(v3,v1,background);
        }
    }

    else if (e1.getState(IN_AZ) && e1.getState(DEAD))
    {
        if(e2.getState(IN_SZ) && !e2.getState(DEAD))
        {
            e2.enableState(BEING_SWAPPED);
            swap_function(e1,e2,background);
        }
        else if (e3.getState(IN_SZ) && !e3.getState(DEAD))
        {
            e3.enableState(BEING_SWAPPED);
            swap_function(e1,e3,background);
        }
    }

    else if (e2.getState(IN_AZ) && e2.getState(DEAD))
    {
        if(e1.getState(IN_SZ) && !e1.getState(DEAD))
        {
            e1.enableState(BEING_SWAPPED);
            swap_function(e2,e1,background);
        }
        else if (e3.getState(IN_SZ) && !e3.getState(DEAD))
        {
            e3.enableState(BEING_SWAPPED);
            swap_function(e2,e3,background);
        }
    }

    else if (e3.getState(IN_AZ) && e3.getState(DEAD))
    {
        if(e1.getState(IN_SZ) && !e1.getState(DEAD))
        {
            e2.enableState(BEING_SWAPPED);
            swap_function(e3,e1,background);
        }
        else if (e2.getState(IN_SZ) && !e2.getState(DEAD))
        {
            e2.enableState(BEING_SWAPPED);
            swap_function(e3,e2,background);
        }
    }

    if(e1.getState(DEAD) && e2.getState(DEAD) && e3.getState(DEAD) || v1.getState(DEAD) && v2.getState(DEAD) && v3.getState(DEAD))
    {
        hide_all_menus();
        hide_both_buttons();
        attack.enableState(DORMANT);
        swap.enableState(DORMANT);
    }

}

void User_interface::swap_function(Complete_vivosaur &AZ_V, Complete_vivosaur &SZ_V, Battlefield& background)
{
    if (SZ_V.getState(BEING_SWAPPED))
    {
        if (SZ_V.getState(ENEMY))
            SZ_V.center_platform(background.get_enemy_AZ_hex());

        else if (!SZ_V.getState(ENEMY))
            SZ_V.center_platform(background.get_player_AZ_hex());


        SZ_V.disableState(IN_SZ);
        SZ_V.enableState(IN_AZ);
        SZ_V.disableState(BEING_SWAPPED);
    }
    if (AZ_V.getState(ENEMY))
        AZ_V.center_platform(background.get_enemy_EZ_hex());

    else if (!AZ_V.getState(ENEMY))
        AZ_V.center_platform(background.get_player_EZ_hex());

    AZ_V.enableState(IN_EZ);
    AZ_V.disableState(IN_AZ);

    if(getState(SWAP_ENGAGED))
    {
        disableState(SWAP_ENGAGED);
        swap.disableState(TOGGLE_SWAP);
        swap.disableState(ENGAGED);
        swap.disableState(CLICKED);
        enableState(SHOW_ON_HOVER);
        hide_all_menus();
        show_both_buttons();
        swap.enableState(HIDDEN);
    }
}

void User_interface::target_az(Complete_vivosaur &v, Complete_vivosaur &e)
{
    if(!v.getState(DEAD))
    {
        e.enableState(TARGET);
        fight.hit_enemy(v, e);
        e.disableState(TARGET);
        disable_attack(v);
    }


}

void User_interface::target_any(Complete_vivosaur& v, Complete_vivosaur& e1, Complete_vivosaur& e2, Complete_vivosaur& e3, sf::RenderWindow& window)
{
    if(e1.getState(TARGET))
    {
        fight.hit_enemy(v,e1);
        e1.disableState(TARGET);
    }

    else if (e2.getState(TARGET))
    {
        fight.hit_enemy(v,e2);
        e2.disableState(TARGET);
    }

    else if (e3.getState(TARGET))
    {
        fight.hit_enemy(v, e3);
        e3.disableState(TARGET);
    }
    disable_attack(v);
}

void User_interface::select_target(Complete_vivosaur& attacker, Complete_vivosaur &enemy_1, Complete_vivosaur &enemy_2, Complete_vivosaur &enemy_3,sf::RenderWindow &window)
{
    if (Mouse_events::is_clicked(enemy_1.get_sprite(), window))
    {
        enemy_1.enableState(TARGET);
        attacker.enableState(ENGAGED);
    }

    else if (Mouse_events::is_clicked(enemy_2.get_sprite(), window))
    {
        enemy_2.enableState(TARGET);
        attacker.enableState(ENGAGED);
    }

    else if (Mouse_events::is_clicked(enemy_3.get_sprite(), window))
    {
        enemy_3.enableState(TARGET);
        attacker.enableState(ENGAGED);
    }
}

void User_interface::SZ_attack(Complete_vivosaur &SZ_attacker, Complete_vivosaur& AZ_enemy, Stats_menu& attacker_menu)
{
    AZ_enemy.enableState(TARGET);
    target_az(SZ_attacker, AZ_enemy);
    SZ_attacker.reset_player_position();
    dormant_menu(attacker_menu);
}

void User_interface::hide_both_buttons()
{
    swap.enableState(HIDDEN);
    attack.enableState(HIDDEN);
}

void User_interface::show_both_buttons()
{
    swap.disableState(HIDDEN);
    attack.disableState(HIDDEN);
}

void User_interface::dormant_menu(Stats_menu& menu)
{
    menu.enableState(DORMANT);
    menu.enableState(HIDDEN);
}

void User_interface::all_player_position_reset(Complete_vivosaur &v1, Complete_vivosaur &v2, Complete_vivosaur &v3)
{
    v1.reset_player_position();
    v2.reset_player_position();
    v3.reset_player_position();
}

void User_interface::all_enemy_position_reset(Complete_vivosaur &e1, Complete_vivosaur &e2, Complete_vivosaur &e3)
{
    e1.reset_enemy_position();
    e2.reset_enemy_position();
    e3.reset_enemy_position();
}

void User_interface::hide_all_menus()
{
    stats_menu_1.enableState(HIDDEN);
    stats_menu_2.enableState(HIDDEN);
    stats_menu_3.enableState(HIDDEN);
}

void User_interface::turn_system()
{
    if (turns.front() == 1)
    {
        enableState(PLAYER_TURN);
        disableState(AI_TURN);
        turns.pop();
        turns.push(1);
    }
    else if (turns.front() == 2)
    {
        enableState(AI_TURN);
        disableState(PLAYER_TURN);
        turns.pop();
        turns.push(2);
    }
}

void User_interface::disable_attack(Complete_vivosaur &v)
{
    disableState(ATTACK_ENGAGED);
    enableState(SHOW_ON_HOVER);
    attack.disableState(ENGAGED);
    attack.disableState(CLICKED);
    v.disableState(ATTACKING);
    v.disableState(CLICKED);
    v.disableState(ENGAGED);
    v.enableState(TURN_OVER);
}




