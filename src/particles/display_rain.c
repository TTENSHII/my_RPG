/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** display_rain
*/

#include "rpg.h"

void display_rain(global_t *global)
{
    sfRenderWindow_setView(global->main->window, global->main->interface);
    sfRenderWindow_drawSprite(global->main->window,
    global->particles->sp, NULL);
}