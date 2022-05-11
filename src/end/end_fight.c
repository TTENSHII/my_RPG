/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** end_fight
*/

#include "rpg.h"

static void free_list(jutsu_t *list)
{
    jutsu_t *tmp = list;

    while (list != NULL) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}

void end_fight(global_t *global)
{
    if (my_strcmp(global->fight->npc->name, "jerome") == 0
    && global->fight->npc->life <= 0 &&
    global->player->skills.units[CREDITS] >= 60) {
        global->scene = ENDGAME;
    } else {
        global->scene = GAME;
    }
    if (global->fight->npc->life <= 0) {
        global->player->skills.units[CREDITS] += 15;
    }
    sfTexture_destroy(global->fight->tx_bg[0]);
    sfTexture_destroy(global->fight->tx_bg[1]);
    sfText_destroy(global->fight->texts->jutsu);
    sfText_destroy(global->fight->texts->npc_life);
    sfText_destroy(global->fight->texts->npc_name);
    sfText_destroy(global->fight->texts->player_life);
    sfText_destroy(global->fight->texts->player_name);
    sfRectangleShape_destroy(global->fight->life_bg[0]);
    sfRectangleShape_destroy(global->fight->life_bg[1]);
    sfRectangleShape_destroy(global->fight->life_bar[0]);
    sfRectangleShape_destroy(global->fight->life_bar[1]);
    sfTexture_destroy(global->fight->template_button[0]);
    sfTexture_destroy(global->fight->template_button[1]);
    sfTexture_destroy(global->fight->template_button[2]);
    sfTexture_destroy(global->fight->template_button[3]);
    sfSprite_destroy(global->fight->rect_jutsu[0]);
    sfSprite_destroy(global->fight->rect_jutsu[1]);
    sfSprite_destroy(global->fight->rect_jutsu[2]);
    sfSprite_destroy(global->fight->rect_jutsu[3]);
    sfSprite_destroy(global->fight->sp_bg[0]);
    sfSprite_destroy(global->fight->sp_bg[1]);
    sfClock_destroy(global->fight->clock_anims.clock);
    sfClock_destroy(global->fight->clock_npc.clock);
    sfClock_destroy(global->fight->clock.clock);
    sfTexture_destroy(global->fight->player->tx[0]);
    sfTexture_destroy(global->fight->player->tx[1]);
    sfTexture_destroy(global->fight->player->tx[2]);
    sfTexture_destroy(global->fight->player->tx[3]);
    sfSprite_destroy(global->fight->player->sp[0]);
    sfSprite_destroy(global->fight->player->sp[1]);
    sfSprite_destroy(global->fight->player->sp[2]);
    sfSprite_destroy(global->fight->player->sp[3]);
    free(global->fight->player);
    sfTexture_destroy(global->fight->npc->tx[0]);
    sfTexture_destroy(global->fight->npc->tx[1]);
    sfTexture_destroy(global->fight->npc->tx[2]);
    sfTexture_destroy(global->fight->npc->tx[3]);
    sfSprite_destroy(global->fight->npc->sp[0]);
    sfSprite_destroy(global->fight->npc->sp[1]);
    sfSprite_destroy(global->fight->npc->sp[2]);
    sfSprite_destroy(global->fight->npc->sp[3]);
    free_list(global->fight->npc->jutsu);
    free(global->fight->npc->name);
    free(global->fight->npc);
    sfClock_restart(global->clock.clock);
}
