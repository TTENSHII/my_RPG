/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** hunter
*/

#include "rpg.h"

static int init_background_hunter(global_t *global)
{
    global->hunter->texture[0] =
    sfTexture_createFromFile("assets/hunter/images/background_1.png",
    NULL);
    if (!global->hunter->texture[0])
        return 84;
    global->hunter->sprite[0] = sfSprite_create();
    sfSprite_setTexture(global->hunter->sprite[0],
    global->hunter->texture[0], sfTrue);
    sfSprite_setPosition(global->hunter->sprite[0],
    (sfVector2f){0, 0});
    global->hunter->clock.clock = sfClock_create();
    global->hunter->clock.second = 0;
    return 0;
}

static int init_drone(global_t *global)
{
    global->hunter->sprite[1] = sfSprite_create();
    global->hunter->texture[1] =
    sfTexture_createFromFile("assets/hunter/spritesheets/SS_Dragonfire.png",
    NULL);
    if (!global->hunter->texture[1])
        return 84;
    sfSprite_setTexture(global->hunter->sprite[1],
    global->hunter->texture[1], sfTrue);
    sfSprite_setPosition(global->hunter->sprite[1],
    (sfVector2f) {-50, rand() % 900});
    sfSprite_setScale(global->hunter->sprite[1],
    (sfVector2f) {0.5, 0.5});
    return 0;
}

static int init_snip(global_t *global)
{
    sfIntRect rect = {0, 0, 601, 635};
    global->hunter->sprite[2] = sfSprite_create();
    global->hunter->texture[2] =
    sfTexture_createFromFile("assets/hunter/spritesheets/dsr_ss.png",
    NULL);
    if (!global->hunter->texture[2])
        return 84;
    sfSprite_setTexture(global->hunter->sprite[2],
    global->hunter->texture[2], sfTrue);
    sfSprite_setPosition(global->hunter->sprite[2],
    (sfVector2f) {700, 600});
    sfSprite_setScale(global->hunter->sprite[2],
    (sfVector2f) {1, 1});
    sfSprite_setTextureRect(global->hunter->sprite[2], rect);
    return 0;
}

static int init_score_hunter(global_t *global)
{
    global->hunter->sfText_score = sfText_create();
    if (!global->hunter->sfText_score) return 84;
    sfText_setFont(global->hunter->sfText_score, global->texts->font);
    sfText_setCharacterSize(global->hunter->sfText_score, 35);
    sfText_setColor(global->hunter->sfText_score, sfWhite);
    sfText_setString(global->hunter->sfText_score, "0");
    sfText_setPosition(global->hunter->sfText_score, (sfVector2f) {1580, 645});
}

int init_hunter(global_t *global)
{
    global->hunter->loose = 0;
    global->hunter->value[0] = 0;
    if (init_background_hunter(global) == 84 || init_drone(global) == 84
    || init_score_hunter(global) == 84 || init_snip(global) == 84)
        return 84;
    return 0;
}