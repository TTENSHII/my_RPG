/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** end_fight_intro
*/

#include "rpg.h"

static npc_t *find_npc(global_t *global, int id)
{
    npc_t *tmp = global->npc;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->id == id)
            return (tmp);
    }
    tmp = global->npc;
    return (tmp);
}

void exit_fight_intro(global_t *global)
{
    for (int i = 0; i < 4; i ++) {
        sfTexture_destroy(global->fight_intro->tx[i]);
        sfSprite_destroy(global->fight_intro->sp[i]);
    }
    sfClock_destroy(global->fight_intro->clock.clock);
    if (start_fight(global, find_npc(global,
    global->global_value->npc_id)) == 84)
        global->scene = GAME;
}
