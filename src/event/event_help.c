/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event_help
*/

#include "rpg.h"

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

void event_help(global_t *global)
{
    manage_exit_click(global);
}
