/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_text_skills
*/

#include "rpg.h"

static void set_position_text(global_t *global)
{
    sfText_setPosition(global->texts->sfText_skills_info[MAT],
    (sfVector2f){1200, 810});
    sfText_setPosition(global->texts->sfText_skills_info[MUL],
    (sfVector2f){1200, 745});
    sfText_setPosition(global->texts->sfText_skills_info[PSU],
    (sfVector2f){1200, 678});
    sfText_setPosition(global->texts->sfText_skills_info[HUB],
    (sfVector2f){1200, 870});
}

static int init_text_name(global_t *global)
{
    global->texts->text_name = sfText_create();
    sfText_setString(global->texts->text_name, "playername");
    sfText_setFont(global->texts->text_name, global->texts->font);
    sfText_setColor(global->texts->text_name, sfBlack);
    sfText_setCharacterSize(global->texts->text_name, 50);
    sfText_setPosition(global->texts->text_name, (sfVector2f){1200, 615});
}

int init_all_text(global_t *global)
{
    int x = 150;
    int y = 75;
    for (int i = 0; i <= 4; i++) {
        global->texts->sfText_skills_info[i] = 0;
        global->texts->sfText_skills_info[i] = sfText_create();
        sfText_setString(global->texts->sfText_skills_info[i],
        "0");
        sfText_setFont(global->texts->sfText_skills_info[i],
        global->texts->font);
        sfText_setCharacterSize(global->texts->sfText_skills_info[i], 50);
    }
    set_position_text(global);
    init_text_name(global);
}