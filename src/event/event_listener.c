/*
** EPITECH PROJECT, 2022
**
** File description:
** event_listener
*/

#include "rpg.h"

static void listen_scene(global_t *global)
{
    if (global->scene >= 0 && global->scene <= 12)
        event_tab[global->scene].func(global);
}

void event_listner(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->main->window, &global->main->event)) {
        if (global->main->event.type == sfEvtClosed)
            sfRenderWindow_close(global->main->window);
        listen_scene(global);
    }
}
