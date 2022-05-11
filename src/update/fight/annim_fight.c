/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** annim_fight
*/

#include "rpg.h"

static void npc_fight_attack(global_t *global)
{
    if (global->fight->npc_attack == 1 && global->fight->clock.second > 2) {
        char *str = malloc(sizeof(char) * 400);
        str = my_strcpy(str, global->fight->npc->name);
        str = my_strcat(str, " has inflicted ");
        str = my_strcat(str, my_int_to_str(global->fight->npc->jutsudammage));
        str = my_strcat(str, " damage with ");
        str = my_strcat(str, global->fight->npc->jutsuname);
        sfText_setString(global->fight->texts->jutsu, str);
    }
}

void restart_clock_fight(global_t *global)
{
    npc_fight_attack(global);
    if (global->fight->clock.second > 4) {
        sfClock_restart(global->fight->clock.clock);
        sfClock_restart(global->fight->clock_npc.clock);
        sfClock_restart(global->fight->clock_anims.clock);
        global->fight->is_animation = false;
        if (global->fight->npc_attack == true) {
            global->fight->npc_turn = false;
            global->fight->player_turn = true;
            global->fight->player_attack = false;
            global->fight->npc_attack = false;
        } else {
            global->fight->npc_turn = true;
            global->fight->player_turn = false;
            global->fight->player_attack = false;
            global->fight->npc_attack = false;
        }
    }
}

void event_update_fight(global_t *global)
{
    if (global->fight->npc->life <= 0 || global->fight->player->life <= 0) {
        end_fight(global);
        return;
    }
    if (global->fight->is_animation == true) {
        anims_fight_update(global);
        return;
    }
    if (global->fight->npc_turn == true) {
        npc_fight_update(global);
        return;
    }
    if (global->fight->player_turn == true) {
        player_fight_update(global);
        return;
    }
}