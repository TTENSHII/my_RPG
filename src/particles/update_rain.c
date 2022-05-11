/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update_rain
*/

#include "rpg.h"

void draw_all_pixel(framebuffer_t *buffer, raindrop_t *tmp)
{
    for (int i = 0; i < 200; i++) {
        my_put_pixel(buffer, tmp->pixel[i].x, tmp->pixel[i].y,
        tmp->pixel[i].color);
    }
}

void put_rain(framebuffer_t *buffer, raindrop_t *raindrop)
{
    raindrop_t *tmp = raindrop;

    while (tmp != NULL) {
        draw_all_pixel(buffer, tmp);
        tmp = tmp->next;
    }
}

void moove_rain(raindrop_t **raindrop, float second)
{
    raindrop_t *tmp = *raindrop;

    while (tmp != NULL) {
        for (int i = 0; i < 200; i++) {
            tmp->pixel[i].y += (tmp->speed * second);
            if (tmp->pixel[i].y > 1080) {
                tmp->pixel[i].y = 0;
            }
        }
        tmp = tmp->next;
    }
}

void update_rain(global_t *global)
{
    clear_buffer(global->particles->framebuffer);
    global->particles->clock.time =
    sfClock_restart(global->particles->clock.clock);
    global->particles->clock.second =
    global->particles->clock.time.microseconds / 1000000.0;
    moove_rain(&global->particles->raindrop, global->particles->clock.second);
    put_rain(global->particles->framebuffer, global->particles->raindrop);
    sfTexture_updateFromPixels(global->particles->tx,
    global->particles->framebuffer->pixels,
    1920, 1080, 0, 0);
    sfSprite_setTexture(global->particles->sp, global->particles->tx, sfTrue);
}