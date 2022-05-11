/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** reset_sokoban
*/

#include "rpg.h"

static void free_my_map(sokoban_t *sokoban)
{
    map_t *tmp_next = NULL;
    map_t *tmp = sokoban->map;
    while (tmp_next != NULL) {
        tmp_next = tmp->next;
        sfSprite_destroy(tmp->sp);
        free(tmp);
        tmp = tmp_next;
    }
}

void reset_my_sokoban(sokoban_t *sokoban)
{
    if (sokoban->map != NULL)
        free_my_map(sokoban);
    sokoban->map = NULL;
    ini_map(sokoban);
}
