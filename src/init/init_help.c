/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_help
*/

#include "rpg.h"

int init_help(global_t *global)
{
    global->sprite->help_back = sfSprite_create();
    global->texture->help_back =
    sfTexture_createFromFile("assets/menu/help/help_back.png", NULL);
    sfSprite_setTexture(global->sprite->help_back, global->texture->help_back,
    sfFalse);
    if (!global->texture->help_back)
        return 84;
    sfSprite_setPosition(global->sprite->help_back, (sfVector2f){520, 250});
}
