/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** collision_object
*/

#include "rpg.h"

static void add_node_inventory(global_t *global, objects_t *my_object)
{
    inventory_t *new = malloc(sizeof(inventory_t));
    new->next = NULL;
    new->id = my_object->id;
    new->name = my_strdup(my_object->name);
    new->pos = (sfVector2f) {1300, 50};
    new->sp = sfSprite_copy(my_object->sp);
    sfSprite_setPosition(new->sp, new->pos);
    if (global->inventory == NULL) {
        global->inventory = new;
        return;
    }
    inventory_t *tmp = global->inventory;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

static void is_object(global_t *global, objects_t *tmp)
{
    global->global_value->is_on = 0;
    if (global->player->pos.x + 80 > tmp->pos.x &&
        global->player->pos.x < tmp->pos.x + 80 &&
        global->player->pos.y + 80 > tmp->pos.y &&
        global->player->pos.y < tmp->pos.y + 200 &&
        tmp->is_on != true) {
        global->global_value->is_on = 1;
        if (sfKeyboard_isKeyPressed(sfKeyI)) {
            add_node_inventory(global, tmp);
            global->global_value->start_game++;
            global->player->take_pc++;
            tmp->is_on = true;
            global->global_value->is_on = 1;
        }
    }
}

int is_object_colision(global_t *global)
{
    int i = 0;
    for (int i = 0; i <= 4; i++)
        global->global_value->object_id[i] = 0;
    for (objects_t *tmp = global->objects; tmp != NULL; tmp = tmp->next) {
        is_object(global, tmp);
    }
}