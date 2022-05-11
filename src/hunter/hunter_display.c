
/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** hunter_display
*/

#include "rpg.h"

void display_sprite_hunter(global_t *global)
{
    sfRenderWindow_clear(global->main->window, sfBlack);
    sfRenderWindow_setView(global->main->window, global->main->interface);
    sfRenderWindow_drawSprite(global->main->window,
    global->hunter->sprite[0], NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->hunter->sprite[1], NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->hunter->sprite[2], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->hunter->sfText_score, NULL);
    return;
}