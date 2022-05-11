/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** collision_hub
*/

#include "rpg.h"

static int add_hub_inventory(global_t *global, hub_t *hub)
{
    inventory_hub_t *new = malloc(sizeof(inventory_hub_t));
    new->next = NULL;
    new->id = hub->id;
    new->name = my_strdup(hub->name);
    new->pos = (sfVector2f) {1300, 80};
    new->sp = sfSprite_copy(hub->sp);
    sfSprite_setPosition(new->sp, new->pos);
    if (global->inventory_hub == NULL) {
        global->inventory_hub = new;
        return (0);
    }
    inventory_hub_t *tmp = global->inventory_hub;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    tmp->pos.x += 50;
}

static void is_hub_object(global_t *global, hub_t *tmp)
{
    if (global->player->pos.x + 80 > tmp->pos.x &&
        global->player->pos.x < tmp->pos.x + 80 &&
        global->player->pos.y + 80 > tmp->pos.y &&
        global->player->pos.y < tmp->pos.y + 200 &&
        tmp->is_on != true &&
        global->global_value->hub_index[1] == 1) {
            global->global_value->is_on = 1;
            if (sfKeyboard_isKeyPressed(sfKeyI)) {
            add_hub_inventory(global, tmp);
            tmp->is_on = true;
            global->global_value->hub_index[0]++;
            }
    }
}

int is_hub_colision_hub(global_t *global)
{
    for (hub_t *tmp = global->hub; tmp != NULL; tmp = tmp->next) {
        is_hub_object(global, tmp);
    }
    return (0);
}