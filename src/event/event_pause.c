/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** event_pause
*/

#include "rpg.h"

static void manage_framerate_30(global_t *global)
{
    sfVector2f vect_30 =
    sfSprite_getPosition(global->sprite->settings_back[FPS_30_ON]);

    if (global->main->event.mouseButton.x >= vect_30.x &&
        global->main->event.mouseButton.x <= vect_30.x + 251 &&
        global->main->event.mouseButton.y >= vect_30.y &&
        global->main->event.mouseButton.y <= vect_30.y + 67) {
        global->global_value->fps = 30;
        sfSound_play(global->music->sound_click);
        }
    return;
}

static void manage_framerate_60_144(global_t *global)
{
    sfVector2f vect_144 =
    sfSprite_getPosition(global->sprite->settings_back[FPS_144_ON]);
    sfVector2f vect_60 =
    sfSprite_getPosition(global->sprite->settings_back[FPS_60_ON]);

    if (global->main->event.mouseButton.x >= vect_144.x &&
        global->main->event.mouseButton.x <= vect_144.x + 251 &&
        global->main->event.mouseButton.y >= vect_144.y &&
        global->main->event.mouseButton.y <= vect_144.y + 67) {
        global->global_value->fps = 144;
        sfSound_play(global->music->sound_click);
        }
    if (global->main->event.mouseButton.x >= vect_60.x &&
        global->main->event.mouseButton.x <= vect_60.x + 251 &&
        global->main->event.mouseButton.y >= vect_60.y &&
        global->main->event.mouseButton.y <= vect_60.y + 67) {
        global->global_value->fps = 60;
        sfSound_play(global->music->sound_click);
        }
    return;
}

static void manage_framerate_click(global_t *global)
{
    sfVector2f vect_144 =
    sfSprite_getPosition(global->sprite->settings_back[FPS_144_ON]);

    if (global->main->event.type != sfEvtMouseButtonPressed) return;
    manage_framerate_30(global);
    manage_framerate_60_144(global);
    return;
}

static void manage_exit_click(global_t *global)
{
    sfVector2f vect_exit =
    sfSprite_getPosition(global->sprite->settings_back[EXIT_SETTINGS]);

    if (global->main->event.type != sfEvtMouseButtonPressed) return;
    if (global->main->event.mouseButton.x >= vect_exit.x &&
        global->main->event.mouseButton.x <= vect_exit.x + 178 &&
        global->main->event.mouseButton.y >= vect_exit.y &&
        global->main->event.mouseButton.y <= vect_exit.y + 48)
        global->scene = MENU;
    return;
}

void manage_pause_event(global_t *global)
{
    event_power(global);
    manage_framerate_click(global);
    manage_exit_click(global);
}
