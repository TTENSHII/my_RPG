/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** sokoban
*/

#include "rpg.h"

static void destroy_map(sokoban_t *sokoban)
{
    if (sokoban->map == NULL)
        return;
    map_t *prev = sokoban->map;
    map_t *tmp = sokoban->map;
    while (tmp != NULL) {
        prev = tmp;
        tmp = tmp->next;
        sfSprite_destroy(prev->sp);
        free(prev);
    }
}

static void destroy_sokoban(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map_char[i] != NULL; i ++)
        free(sokoban->map_char[i]);
    free(sokoban->map_char);
    sfClock_destroy(sokoban->clock.clock);
    sfSprite_destroy(sokoban->sp);
    for (int i = 0; i < 5; i ++)
        sfTexture_destroy(sokoban->tx[i]);
    sfClock_destroy(sokoban->player.clock.clock);
    for (int i = 0; i < 4; i ++) {
        sfSprite_destroy(sokoban->player.sp[i]);
        sfTexture_destroy(sokoban->player.tx[i]);
    }
    free(sokoban->player.name);
    destroy_map(sokoban);
}

void exit_sokoban(global_t *global)
{
    if (global->player->skills.units[PSU] != 1 && global->sokoban->win == 1)
        global->player->skills.units[PSU] += 1;
    destroy_sokoban(global->sokoban);
    global->scene = GAME;
}
