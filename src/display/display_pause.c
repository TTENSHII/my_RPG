/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** display_pause
*/

#include "rpg.h"

static void display_framerate(global_t *global)
{
    if (global->global_value->fps == 144)
        sfRenderWindow_drawSprite
        (global->main->window, global->sprite->settings_back[FPS_144_ON], NULL);
    else
        sfRenderWindow_drawSprite
        (global->main->window,
        global->sprite->settings_back[FPS_144_OFF], NULL);
    if (global->global_value->fps == 30)
        sfRenderWindow_drawSprite
        (global->main->window, global->sprite->settings_back[FPS_30_ON], NULL);
    else
        sfRenderWindow_drawSprite
        (global->main->window, global->sprite->settings_back[FPS_30_OFF], NULL);
    if (global->global_value->fps == 60)
        sfRenderWindow_drawSprite
        (global->main->window, global->sprite->settings_back[FPS_60_ON], NULL);
    else
        sfRenderWindow_drawSprite
        (global->main->window, global->sprite->settings_back[FPS_60_OFF], NULL);
}

static void display_volume(global_t *global)
{
    if (global->global_value->volume_id[0] == 1)
        sfRenderWindow_drawSprite
        (global->main->window, global->sprite->settings_back[VOLUME_UP_S], NULL);
    else
        sfRenderWindow_drawSprite
        (global->main->window, global->sprite->settings_back[VOLUME_UP], NULL);
    if (global->global_value->volume_id[1] == 1)
        sfRenderWindow_drawSprite
        (global->main->window, global->sprite->settings_back[VOLUME_LOW_S], NULL);
    else
        sfRenderWindow_drawSprite
        (global->main->window, global->sprite->settings_back[VOLUME_LOW], NULL);
}

void display_sprite_pause(global_t *global)
{
    sfRenderWindow_clear(global->main->window, sfBlack);
    sfRenderWindow_drawSprite
    (global->main->window, global->sprite->menu_back, NULL);
    sfRenderWindow_drawSprite
    (global->main->window, global->sprite->settings_back[EXIT_SETTINGS], NULL);
    display_framerate(global);
    display_volume(global);
    sfRenderWindow_drawSprite
    (global->main->window, global->sprite->settings_back[VOLUME_STRING], NULL);
    sfRenderWindow_drawSprite
    (global->main->window, global->sprite->fps, NULL);
    sfText_setString
    (global->texts->sfText_volume,
    my_int_to_str(global->global_value->volume));
    sfRenderWindow_drawText
    (global->main->window, global->texts->sfText_volume, NULL);
}
