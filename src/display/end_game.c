/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** end_game
*/

#include "rpg.h"

void display_endgame(global_t *global)
{
    sfRenderWindow_setView(global->main->window,
    global->main->interface);
    sfRenderWindow_drawSprite(global->main->window,
    global->end_game->sp_bg, NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->end_game->sp_button_exit, NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->end_game->sp_button_menu, NULL);
}
