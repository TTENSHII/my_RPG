/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** player
*/

#include "rpg.h"

int is_npc(global_t *global, int id, npc_t *tmp)
{
    if (global->player->pos.x + 100 > tmp->pos.x &&
        global->player->pos.x < tmp->pos.x + 100 &&
        global->player->pos.y + 100 > tmp->pos.y &&
        global->player->pos.y < tmp->pos.y + 100 && tmp->id == id) {
        global->global_value->npc_id = id;
    }
}

int is_colision(global_t *global)
{
    global->global_value->npc_id = 0;
    int i = 0;
    is_object_colision(global);
    is_hub_colision_hub(global);
    for (npc_t *tmp = global->npc; tmp != NULL; tmp = tmp->next)
        for (int i = 0; i <= 17; i += 1)
            is_npc(global, i, tmp);
    for (map_t *tmp = global->map; tmp != NULL; tmp = tmp->next) {
        if (tmp->num == 29 || tmp->num == 37 || tmp->num == 5
        || tmp->num == 61 ||
        tmp->num == 68 || tmp->num == 36 || tmp->num == 9 || tmp->num == 48)
            continue;
        if (global->player->pos.x + 40 > tmp->pos.x &&
        global->player->pos.x < tmp->pos.x + 40 &&
        global->player->pos.y + 43 > tmp->pos.y &&
        global->player->pos.y < tmp->pos.y + 43)
            return (1);
    }
    return (0);
}

static void set_and_reset(global_t *global)
{
    for(int i = 0; i <= 3; i++)
        sfSprite_setPosition(global->player->sp[i], global->player->pos);
    if (global->player->clock.second > 0.2 &&
        global->player->is_walking == sfTrue) {
        sfClock_restart(global->player->clock.clock);
        global->player->rect.left += 48;
        if (global->player->rect.left >= 48 * 4)
            global->player->rect.left = 0;
    }
    for (int i = 0; i <= 3; i++)
        sfSprite_setTextureRect(global->player->sp[i], global->player->rect);
}

void update_player(global_t *global)
{
    global->player->pos.x +=\
    (global->player->velocity.x * global->clock.second);
    global->player->pos.y +=\
    (global->player->velocity.y * global->clock.second);
    if (is_colision(global) == true) {
        global->player->pos.x -=\
        (global->player->velocity.x * global->clock.second);
        global->player->pos.y -=\
        (global->player->velocity.y * global->clock.second);
        global->player->is_walking = sfFalse;
    }
    set_and_reset(global);
}
