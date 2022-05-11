/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** npc
*/

#include "rpg.h"
#include <string.h>

static int count_jutsu(jutsu_t *list)
{
    int i = 0;
    jutsu_t *tmp = list;

    while (list != NULL) {
        i++;
        list = list->next;
    }
    return (i);
}

static void chose_jutsu(int nb, jutsu_t **this_jutsu, jutsu_t *list)
{
    int i = 0;
    jutsu_t *tmp = list;

    while (i < nb && tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    if (tmp == NULL) {
        tmp = list;
    }
    (*this_jutsu)->name = my_strdup(tmp->name);
    (*this_jutsu)->dammages = tmp->dammages;
    (*this_jutsu)->next = NULL;
}

static void npc_jutsu(global_t *global, jutsu_t *this_jutsu)
{
    global->fight->player->life -= this_jutsu->dammages;
    global->fight->npc_turn = false;
    global->fight->npc_attack = true;
    global->fight->is_animation = true;
    sfClock_restart(global->fight->clock_npc.clock);
    global->fight->clock_npc.second = 0;
    free(global->fight->npc->jutsuname);
    global->fight->npc->jutsuname = my_strdup(this_jutsu->name);
    global->fight->npc->jutsudammage = this_jutsu->dammages;
    char *str = malloc(sizeof(char) * 400);
    str = my_strcpy(str, global->fight->npc->name);
    str = my_strcat(str, " : ");
    str = my_strcat(str, this_jutsu->name);
    sfText_setString(global->fight->texts->jutsu, str);
}

void npc_fight_update(global_t *global)
{
    int nb_jutsu = 3;
    if (global->fight->clock_npc.second < 2) {
        char *str = malloc(sizeof(char) * 200);
        str = my_strcpy(str, global->fight->npc->name);
        str = my_strcat(str, " choose a jutsu...");
        sfText_setString(global->fight->texts->jutsu, str);
        return;
    }
    jutsu_t *this_jutsu = malloc(sizeof(jutsu_t));
    int attack = rand() % nb_jutsu;
    chose_jutsu(attack, &this_jutsu, global->fight->npc->jutsu);
    npc_jutsu(global, this_jutsu);
}
