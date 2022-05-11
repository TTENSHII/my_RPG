/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** display_help
*/

#include "rpg.h"

void display_help(global_t *global)
{
    sfRenderWindow_clear(global->main->window, sfBlack);
    sfRenderWindow_drawSprite
    (global->main->window, global->sprite->menu_back, NULL);
    sfRenderWindow_drawSprite
    (global->main->window, global->sprite->help_back, NULL);
    sfRenderWindow_drawSprite
    (global->main->window, global->sprite->settings_back[EXIT_SETTINGS], NULL);
}
