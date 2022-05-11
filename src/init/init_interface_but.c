/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_interface_but
*/

#include "rpg.h"

static int init_take_it(global_t *global)
{
    global->global_value->is_on = 0;
    global->texture->interface_game[2] =\
        sfTexture_createFromFile("assets/interface/take.png", NULL);
    global->sprite->interface_game[2] = sfSprite_create();
    if (!global->texture->interface_game[2])
        return 84;
    sfSprite_setTexture(global->sprite->interface_game[2],
    global->texture->interface_game[2], sfTrue);
    sfSprite_setPosition(global->sprite->interface_game[2],
    (sfVector2f) {1370,630});
    return 0;
}

static int init_save_button(global_t *global)
{
    global->texture->interface_game[1] =\
    sfTexture_createFromFile("assets/interface/savve_game.png", NULL);
    global->sprite->interface_game[1] = sfSprite_create();
    if (!global->texture->interface_game[1])
        return (84);
    sfSprite_setTexture(global->sprite->interface_game[1],
    global->texture->interface_game[1], sfTrue);
    sfSprite_setPosition(global->sprite->interface_game[1],
    (sfVector2f) {1370, 310});
    return 0;
}

int init_craft_robot(global_t *global)
{
    global->texture->interface_game[0] = sfTexture_createFromFile(
        "assets/interface/craft_robot.png", NULL);
    if (!global->texture->interface_game[0] || init_save_button(global) == 84
    || init_take_it(global) == 84) return 84;
    global->sprite->interface_game[0] = sfSprite_create();
    sfSprite_setTexture(global->sprite->interface_game[0],
        global->texture->interface_game[0], sfTrue);
    sfSprite_setPosition(global->sprite->interface_game[0],
        (sfVector2f) {1370, 520});
}