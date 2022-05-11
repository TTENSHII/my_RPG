/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_all_menu
*/

#include "rpg.h"

static int init_background_menu(global_t *global)
{
    global->sprite->menu_back = sfSprite_create();
    global->texture->texture_back_menu =
    sfTexture_createFromFile(MENU_BACK, NULL);
    if (!global->texture->texture_back_menu)
        return 84;
    sfSprite_setTexture(global->sprite->menu_back,
    global->texture->texture_back_menu, sfFalse);
    return (0);
}

int init_all_menu(global_t *global)
{
    if (init_background_menu(global) == 84)
        return 84;
    if (init_button_n_menu(global) == 84)
        return 84;
    if (init_button_l_menu(global) == 84)
        return 84;
    if (init_button_e_menu(global) == 84)
        return 84;
    if (init_button_h_menu(global) == 84)
        return 84;
    if (init_button_s_menu(global) == 84)
        return 84;
    if (init_help(global) == 84)
        return 84;
}