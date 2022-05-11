/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** dispay_entity
*/

#include "rpg.h"

void display_npc(npc_t *npc, sfRenderWindow *window)
{
    for (npc_t *tmp = npc; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(window, tmp->sp, NULL);
        sfRenderWindow_drawText(window, tmp->txt_name, NULL);
    }
}

void display_objects(objects_t *objects, sfRenderWindow *window)
{
    for (objects_t *tmp = objects; tmp != NULL; tmp = tmp->next) {
        if (tmp->is_on != true)
            sfRenderWindow_drawSprite(window, tmp->sp, NULL);
    }
}
