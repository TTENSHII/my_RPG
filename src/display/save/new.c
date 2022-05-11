/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** new
*/

#include "rpg.h"

void display_new_save_event(global_t *global)
{
    for (int i = 0; i < 4; i++) 
        sfRenderWindow_drawSprite(global->main->window,
            global->sprite->new_game[i], NULL);
    sfRenderWindow_drawText(global->main->window,
        global->texts->text_new, NULL);
    if (global->global_value->index_new == 0)
        sfRenderWindow_drawSprite(global->main->window,
            global->sprite->new_game[4], NULL);
}
