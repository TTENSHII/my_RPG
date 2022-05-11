/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_circle_shape
*/

#include "rpg.h"

static void set_position_circle_shape(global_t *global)
{
    sfCircleShape_setPosition(global->shape->circle_item_hub[0],
    (sfVector2f) {1200, 100});
    sfCircleShape_setPosition(global->shape->circle_item_hub[1],
    (sfVector2f) {4700,1340});
    sfCircleShape_setPosition(global->shape->circle_item_hub[2],
    (sfVector2f) {820, 4255});
    sfCircleShape_setPosition(global->shape->circle_item_hub[3],
    (sfVector2f) {180, 3455});
}

int init_shape_circle(global_t *global)
{
    sfColor color = sfColor_fromRGBA(191, 191, 191, 150.5);

    for (int i = 0; i < 4; i++) {
        global->shape->circle_item_hub[i] = sfCircleShape_create();
        sfCircleShape_setFillColor(global->shape->circle_item_hub[i], color);
        sfCircleShape_setRadius(global->shape->circle_item_hub[i], 5);
        sfCircleShape_scale(global->shape->circle_item_hub[i], (sfVector2f){5, 5});
        sfCircleShape_setPosition(global->shape->circle_item_hub[i], (sfVector2f){0, 0});
    }
    set_position_circle_shape(global);
    return 0;
}