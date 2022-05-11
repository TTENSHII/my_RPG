/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** event_settings_click
*/

#include "rpg.h"

static void event_powerup(global_t *global)
{
    sfVector2f pos =
    sfSprite_getPosition(global->sprite->settings_back[VOLUME_UP]);

    if (global->main->event.type != sfEvtMouseButtonPressed) return;
    if (global->main->event.mouseButton.x >= pos.x &&
        global->main->event.mouseButton.x <= pos.x + 64 &&
        global->main->event.mouseButton.y >= pos.y &&
        global->main->event.mouseButton.y <= pos.y + 64 &&
        global->global_value->volume < 100) {
            global->global_value->volume_id[0] = 1;
            global->global_value->volume++;
    }
    return;
}

static void event_powerlow(global_t *global)
{
    sfVector2f pos =
    sfSprite_getPosition(global->sprite->settings_back[VOLUME_LOW]);

    if (global->main->event.type != sfEvtMouseButtonPressed) return;
    if (global->main->event.mouseButton.x >= pos.x &&
        global->main->event.mouseButton.x <= pos.x + 64 &&
        global->main->event.mouseButton.y >= pos.y &&
        global->main->event.mouseButton.y <= pos.y + 64 &&
        global->global_value->volume > 0) {
            global->global_value->volume_id[1] = 1;
            global->global_value->volume--;
    }
    return;
}

void event_power(global_t *global)
{
    global->global_value->volume_id[0] = 0;
    global->global_value->volume_id[1] = 0;
    event_powerup(global);
    event_powerlow(global);
}
