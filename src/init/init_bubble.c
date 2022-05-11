/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_bubble
*/

#include "rpg.h"

int init_bubbule(global_t *global)
{
    global->texture->bubbule = sfTexture_createFromFile(bubbule_path, NULL);
    if (!global->texture->bubbule)
        return 84;
    global->sprite->bubbule = sfSprite_create();
    sfSprite_setTexture(global->sprite->bubbule,
    global->texture->bubbule, sfTrue);
    sfSprite_setScale(global->sprite->bubbule, (sfVector2f) {0.5, 0.5});
    return 0;
}