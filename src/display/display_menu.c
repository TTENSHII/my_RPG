/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** display_menu
*/

#include "rpg.h"

void display_sprite_menu(global_t *global)
{
    sfMusic_setVolume(global->music->music,
    global->global_value->volume);
    sfRenderWindow_clear(global->main->window, sfBlack);
    sfRenderWindow_drawSprite(global->main->window,
    global->sprite->menu_back, NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->sprite->button[NEW], NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->sprite->button[LOAD], NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->sprite->button[EXIT], NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->sprite->button[SETTING], NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->sprite->button[HELP], NULL);
    if (global->bubbule_text->value != OFF)
        display_bubble_text(global, global->bubbule_text->text,
        (sfVector2f) {1920 / 2, 1080 / 2}, global->bubbule_text->sftext);
}
