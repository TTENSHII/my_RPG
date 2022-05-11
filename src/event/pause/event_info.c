/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** event_info
*/

#include "rpg.h"

static void manage_click(global_t *global)
{
    sfVector2f vect_exit = sfSprite_getPosition(global->sprite->button_pause[1]);
    sfVector2f vect_back = sfSprite_getPosition(global->sprite->button_pause[0]);

    if (global->main->event.type != sfEvtMouseButtonPressed) return;
    if (vect_back.x <= global->main->event.mouseButton.x &&
        global->main->event.mouseButton.x <= vect_back.x + 840 &&
        vect_back.y <= global->main->event.mouseButton.y &&
        global->main->event.mouseButton.y <= vect_back.y + 147)
        global->scene = MENU;
    if (vect_exit.x <= global->main->event.mouseButton.x &&
        global->main->event.mouseButton.x <= vect_exit.x + 840 &&
        vect_exit.y <= global->main->event.mouseButton.y &&
        global->main->event.mouseButton.y <= vect_exit.y + 147)
        sfRenderWindow_close(global->main->window);
}

void manage_info_event(global_t *global)
{
    if ((global->main->event.type == sfEvtKeyPressed) &&
    (global->main->event.key.code == sfKeyEscape))   
        global->scene = GAME;
    manage_click(global);
    return;
}
