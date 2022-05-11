/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** player
*/

#include "rpg.h"

static int calcul_dammage(int stat)
{
    int dammage = 0;

    if (stat <= 0)
        dammage = rand() % (13 - 5) + 5;
    if (stat == 1)
        dammage = rand() % (27 - 13) + 13;
    if (stat > 1)
        dammage = rand() % (33 - 16) + 16;
    return (dammage);
}

static void check_button1(global_t *global, sfVector2i mouse, sfVector2f pos)
{
    if (mouse.x >= pos.x && mouse.x <= pos.x + 700
    && mouse.y >= pos.y && mouse.y <= pos.y + 150) {
        global->fight->player_turn = 0;
        global->fight->is_animation = 1;
        global->fight->player_attack = 1;
        sfClock_restart(global->fight->clock.clock);
        global->fight->clock.second = 0;
        char *str = malloc(sizeof(char) * 400);
        free(global->fight->player->jutsuname);
        global->fight->player->jutsuname = my_strdup("PSU");
        global->fight->player->jutsudammage =
        calcul_dammage(global->player->skills.units[PSU]);
        global->fight->npc->life -= global->fight->player->jutsudammage;
        str = my_strcpy(str, global->fight->player->name);
        str = my_strcat(str, " : ");
        str = my_strcat(str, global->fight->player->jutsuname);
        str = my_strcat(str, " no jutsu");
        sfText_setString(global->fight->texts->jutsu, str);
    }
}

static void check_button2(global_t *global, sfVector2i mouse, sfVector2f pos)
{
    if (mouse.x >= pos.x && mouse.x <= pos.x + 700
    && mouse.y >= pos.y && mouse.y <= pos.y + 150) {
        global->fight->player_turn = 0;
        global->fight->is_animation = 1;
        global->fight->player_attack = 1;
        sfClock_restart(global->fight->clock.clock);
        global->fight->clock.second = 0;
        char *str = malloc(sizeof(char) * 400);
        free(global->fight->player->jutsuname);
        global->fight->player->jutsuname = my_strdup("MUL");
        global->fight->player->jutsudammage =
        calcul_dammage(global->player->skills.units[MUL]);
        global->fight->npc->life -= global->fight->player->jutsudammage;
        str = my_strcpy(str, global->fight->player->name);
        str = my_strcat(str, " : ");
        str = my_strcat(str, global->fight->player->jutsuname);
        str = my_strcat(str, " no jutsu");
        sfText_setString(global->fight->texts->jutsu, str);
    }
}

static void check_button3(global_t *global, sfVector2i mouse, sfVector2f pos)
{
    if (mouse.x >= pos.x && mouse.x <= pos.x + 700
    && mouse.y >= pos.y && mouse.y <= pos.y + 150) {
        global->fight->player_turn = 0;
        global->fight->is_animation = 1;
        global->fight->player_attack = 1;
        sfClock_restart(global->fight->clock.clock);
        global->fight->clock.second = 0;
        char *str = malloc(sizeof(char) * 400);
        free(global->fight->player->jutsuname);
        global->fight->player->jutsuname = my_strdup("MAT");
        global->fight->player->jutsudammage =
        calcul_dammage(global->player->skills.units[MAT]);
        global->fight->npc->life -= global->fight->player->jutsudammage;
        str = my_strcpy(str, global->fight->player->name);
        str = my_strcat(str, " : ");
        str = my_strcat(str, global->fight->player->jutsuname);
        str = my_strcat(str, " no jutsu");
        sfText_setString(global->fight->texts->jutsu, str);
    }
}

static void check_button4(global_t *global, sfVector2i mouse, sfVector2f pos)
{
    if (mouse.x >= pos.x && mouse.x <= pos.x + 700
    && mouse.y >= pos.y && mouse.y <= pos.y + 150) {
        global->fight->player_turn = 0;
        global->fight->is_animation = 1;
        global->fight->player_attack = 1;
        sfClock_restart(global->fight->clock.clock);
        global->fight->clock.second = 0;
        char *str = malloc(sizeof(char) * 400);
        free(global->fight->player->jutsuname);
        global->fight->player->jutsuname = my_strdup("HUB");
        global->fight->player->jutsudammage =
        calcul_dammage(global->player->skills.units[HUB]);
        global->fight->npc->life -= global->fight->player->jutsudammage;
        str = my_strcpy(str, global->fight->player->name);
        str = my_strcat(str, " : ");
        str = my_strcat(str, global->fight->player->jutsuname);
        str = my_strcat(str, " no jutsu");
        sfText_setString(global->fight->texts->jutsu, str);
    }
}

void player_fight_update(global_t *global)
{
    global->fight->player->jutsudammage = 0;
    free(global->fight->player->jutsuname);
    global->fight->player->jutsuname = my_strdup("jutsu");

    sfVector2i mousepos = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f pos_0 = sfSprite_getPosition(global->fight->rect_jutsu[0]);
    sfVector2f pos_1 = sfSprite_getPosition(global->fight->rect_jutsu[1]);
    sfVector2f pos_2 = sfSprite_getPosition(global->fight->rect_jutsu[2]);
    sfVector2f pos_3 = sfSprite_getPosition(global->fight->rect_jutsu[3]);

    if (global->main->event.type != sfEvtMouseButtonPressed)
        return;
    check_button1(global, mousepos, pos_0);
    check_button2(global, mousepos, pos_1);
    check_button3(global, mousepos, pos_2);
    check_button4(global, mousepos, pos_3);
}
