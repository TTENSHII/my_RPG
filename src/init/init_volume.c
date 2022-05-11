/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_volume
*/

#include "rpg.h"

static int init_volume_selected(global_t *global)
{
    global->sprite->settings_back[VOLUME_LOW_S] = sfSprite_create();
    global->texture->texture_back_settings[VOLUME_LOW_S] =
    sfTexture_createFromFile(SETTINGS_VOLUME_LOW_S, NULL);
    global->sprite->settings_back[VOLUME_UP_S] = sfSprite_create();
    global->texture->texture_back_settings[VOLUME_UP_S] =
    sfTexture_createFromFile(SETTINGS_VOLUME_UP_S, NULL);
    if (!global->texture->texture_back_settings[VOLUME_LOW_S] ||
    !global->texture->texture_back_settings[VOLUME_UP_S])
        return 84;
    sfSprite_setTexture(global->sprite->settings_back[VOLUME_LOW_S],
    global->texture->texture_back_settings[VOLUME_LOW_S], sfFalse);
    sfSprite_setTexture(global->sprite->settings_back[VOLUME_UP_S],
    global->texture->texture_back_settings[VOLUME_UP_S], sfFalse);
    sfSprite_setPosition(global->sprite->settings_back[VOLUME_LOW_S],
    (sfVector2f) {1200, 450});
    sfSprite_setPosition(global->sprite->settings_back[VOLUME_UP_S],
    (sfVector2f) {1400, 450});
    return 0;
}

int init_volume_string(global_t *global)
{
    global->global_value->volume_id[0] = 0;
    global->global_value->volume_id[1] = 0;
    global->sprite->settings_back[VOLUME_STRING] = sfSprite_create();
    global->texture->texture_back_settings[VOLUME_STRING] =
    sfTexture_createFromFile("assets/settings_menu/volume.png", NULL);
    if (!global->sprite->settings_back[VOLUME_STRING] ||
    !global->texture->texture_back_settings[VOLUME_STRING])
        return 84;
    sfSprite_setTexture(global->sprite->settings_back[VOLUME_STRING],
    global->texture->texture_back_settings[VOLUME_STRING], sfTrue);
    sfSprite_setPosition(global->sprite->settings_back[VOLUME_STRING],
    (sfVector2f) {850, 450});
    if (init_volume_selected(global) == 84)
        return 84;
    return 0;
}