/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** hunter_update
*/

#include "rpg.h"

static int move_drone(global_t *global)
{
    int random = rand() % 900;
    sfVector2f pos = sfSprite_getPosition(global->hunter->sprite[1]);

    global->hunter->clock.time =
    sfClock_getElapsedTime(global->hunter->clock.clock);
    global->hunter->clock.second =
    global->hunter->clock.time.microseconds / 1000000.0;
    sfClock_restart(global->hunter->clock.clock);
    pos.x = pos.x + (global->hunter->clock.second * 800);
    if (sfSprite_getPosition(global->hunter->sprite[1]).x < 1915) {
        sfSprite_setPosition(global->hunter->sprite[1], pos);
    } else {
        sfSprite_setPosition(global->hunter->sprite[1],
        (sfVector2f){-50, random});
        global->hunter->loose++;
    }
}

static int move_snip(global_t *global)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f pos_s = sfSprite_getPosition(global->hunter->sprite[2]);

    sfSprite_setPosition(global->hunter->sprite[2],
    (sfVector2f) {pos.x, pos_s.y});
}

void update_hunter(global_t *global)
{
    move_snip(global);
    move_drone(global);
    if (global->hunter->value[0] == 20) {
        global->scene = GAME;
        global->player->skills.units[MUL] = 1;
    }
    if (global->hunter->loose == 3)
        global->scene = GAME;
    return;
}