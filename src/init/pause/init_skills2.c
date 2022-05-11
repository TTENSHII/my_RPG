/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_skills2
*/

#include "rpg.h"

int init_psu_skill(global_t *global)
{
    global->texts->sfText_skills[PSU] = sfText_create();
    sfText_setFont(global->texts->sfText_skills[PSU], global->texts->font);
    sfText_setString(global->texts->sfText_skills[PSU], "0");
    sfText_setCharacterSize(global->texts->sfText_skills[PSU], 50);
    sfText_setPosition(global->texts->sfText_skills[PSU],
    (sfVector2f) {27, 250});
    return (0);
}

int init_mul_skill(global_t *global)
{
    global->texts->sfText_skills[MUL] = sfText_create();
    sfText_setFont(global->texts->sfText_skills[MUL], global->texts->font);
    sfText_setString(global->texts->sfText_skills[MUL], "0");
    sfText_setCharacterSize(global->texts->sfText_skills[MUL], 50);
    sfText_setPosition(global->texts->sfText_skills[MUL],
    (sfVector2f) {27, 355});
    return (0);
}

int init_cpe_skill(global_t *global)
{
    global->texts->sfText_skills[CREDITS] = sfText_create();
    sfText_setString(global->texts->sfText_skills[CREDITS], "0");
    sfText_setFont(global->texts->sfText_skills[CREDITS], global->texts->font);
    sfText_setCharacterSize(global->texts->sfText_skills[CREDITS], 50);
    sfText_setPosition(global->texts->sfText_skills[CREDITS],
    (sfVector2f) {27, 670});
    return (0);
}