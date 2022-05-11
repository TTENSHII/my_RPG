/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_pause
*/

#include "rpg.h"

static int init_student_card(global_t *global)
{
    sfTexture *student_texture = sfTexture_createFromFile(
        STUDENT_CARD, NULL);
    if (!student_texture)
        return 84;
    global->sprite->student_card = sfSprite_create();
    sfSprite_setTexture(global->sprite->student_card, student_texture, sfTrue);
    sfSprite_setPosition(global->sprite->student_card,
        (sfVector2f) {0, 0});
    return 0;
}

static int init_inventory(global_t *global)
{
    sfTexture *texture_inventory = sfTexture_createFromFile(
        INVENTORY, NULL);
    if (!texture_inventory)
        return 84;
    global->sprite->inventory = sfSprite_create();
    sfSprite_setTexture(global->sprite->inventory, texture_inventory, sfTrue);
    sfSprite_setPosition(global->sprite->inventory,
        (sfVector2f) {1300, 50});
    return 0;
}

static int init_button_pause(global_t *global)
{
    sfTexture *texture_button_pause =
    sfTexture_createFromFile("assets/new_game/back_to_menu.png", NULL);
    sfTexture *texture_button_pause_home =
    sfTexture_createFromFile("assets/interface/exit_game.png", NULL);
    if (!texture_button_pause || !texture_button_pause_home)
        return 84;
    global->sprite->button_pause[0] = sfSprite_create();
    global->sprite->button_pause[1] = sfSprite_create();
    sfSprite_setTexture(global->sprite->button_pause[0],
        texture_button_pause, sfTrue);
    sfSprite_setTexture(global->sprite->button_pause[1],
        texture_button_pause_home, sfTrue);
    sfSprite_setPosition(global->sprite->button_pause[0],
        (sfVector2f) {100, 500});
    sfSprite_setPosition(global->sprite->button_pause[1],
        (sfVector2f) {100, 700});
}

int init_info(global_t *global)
{
    if (init_student_card(global) == 84 || init_inventory(global) == 84 ||
        init_button_pause(global) == 84)
        return 84;
    return 0;
}