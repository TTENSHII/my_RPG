/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_settings_value
*/

#include "rpg.h"

int init_pos_settings(global_t *global)
{
    return 0;
}

static int init_fps(global_t *global)
{
    global->sprite->fps = sfSprite_create();
    global->texture->fps =
    sfTexture_createFromFile("assets/settings_menu/FPS.png", NULL);
    if (!global->sprite->fps || !global->texture->fps)
        return 84;
    sfSprite_setTexture(global->sprite->fps, global->texture->fps, sfTrue);
    sfSprite_setPosition(global->sprite->fps, (sfVector2f) {350, 320});
}

int init_all_settings(global_t *global)
{
    global->global_value->fps = 60;
    if (init_back_exit(global) == 84)
        return 84;
    if (init_button_volume(global) == 84)
        return 84;
    if (init_buttons_30_on_off(global) == 84 ||
        init_buttons_144_on_off(global) == 84 ||
        init_buttons_60_on_off(global) == 84 || init_fps(global) == 84 ||
        init_volume_string(global) == 84)
        return 84;
}