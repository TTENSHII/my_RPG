/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** update_pixels
*/

#include "rpg.h"

static sfVector2f moove_fly(global_t *global, float intervale, sfVector2f pos)
{
    if (global->particule->dir == 0) {
        pos.x += intervale;
        if (pos.x >= 900) {
            global->particule->dir = 1;
        }
    } else {
        pos.x -= intervale;
        if (pos.x <= 870) {
            global->particule->dir = 0;
        }
    }
    return pos;
}

int update_pixel(global_t *global)
{
    sfVector2f pos = sfSprite_getPosition(global->sprite->floor_particule);
    float intervale = 0.0;

    global->particule->clock.time =
    sfClock_getElapsedTime(global->particule->clock.clock);
    global->particule->clock.second =
    global->particule->clock.time.microseconds / 1000000.0;
    sfClock_restart(global->particule->clock.clock);
    intervale = global->particule->clock.second * 50;
    pos = moove_fly(global, intervale, pos);
    sfSprite_setPosition(global->sprite->floor_particule, pos);
    return (0);
}