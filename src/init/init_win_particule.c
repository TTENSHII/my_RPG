/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_win_particule
*/

#include "rpg.h"

int init_floor_particule(global_t *global)
{
    sfColor *pixels = malloc(sizeof(sfColor) * 10*10);
    sfTexture *texture = sfTexture_create(5, 5);
    sfSprite *sprite = sfSprite_create();

    global->particule->dir = 0;
    if (pixels == NULL || texture == NULL || sprite == NULL)
        return 84;
    for (int i = 0; i < 5*5; i++)
        pixels[i] = sfBlack;
    pixels[5] = sfWhite;
    pixels[17] = sfWhite;
    pixels[22] = sfWhite;
    global->particule->clock.clock = sfClock_create();
    sfTexture_updateFromPixels(texture, (sfUint8*) pixels, 5, 5, 0, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){870, 2431});
    global->sprite->floor_particule = sprite;
    return (0);
}

int init_win_particule(global_t *global)
{
    if (init_floor_particule(global) == 84)
        return 84;
    return 0;
}