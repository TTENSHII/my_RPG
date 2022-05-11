/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_skills
*/

#include "rpg.h"

static int init_mat_skill(global_t *global)
{
    global->texts->sfText_skills[MAT] = sfText_create();
    sfText_setString(global->texts->sfText_skills[MAT], "0");
    sfText_setFont(global->texts->sfText_skills[MAT], global->texts->font);
    sfText_setCharacterSize(global->texts->sfText_skills[MAT], 50);
    sfText_setPosition(global->texts->sfText_skills[MAT],
    (sfVector2f) {27, 465});
    return (0);
}

static int nit_hub_skill(global_t *global)
{
    global->texts->sfText_skills[HUB] = sfText_create();
    sfText_setString(global->texts->sfText_skills[HUB], "0");
    sfText_setFont(global->texts->sfText_skills[HUB], global->texts->font);
    sfText_setCharacterSize(global->texts->sfText_skills[HUB], 50);
    sfText_setPosition(global->texts->sfText_skills[HUB],
    (sfVector2f) {27, 570});
    return (0);
}

static int init_all(global_t *global)
{
    for (int i = 0; i < 4; i++) {
        global->texts->sfText_skills[i] = sfText_create();
        sfText_setString(global->texts->sfText_skills[PSU], "0");
        sfText_setFont(global->texts->sfText_skills[i], global->texts->font);
        sfText_setPosition(global->texts->sfText_skills[PSU],
        (sfVector2f){1920 / 2, 1080 / 2});
    }
    return 0;
}

int init_all_skills(global_t *global)
{
    for (int i = 0; i < 4; i++)
        global->global_value->units[i] = 0;
    if (init_psu_skill(global) == 84) return (84);
    if (init_mul_skill(global) == 84) return (84);
    if (init_cpe_skill(global) == 84) return (84);
    if (init_mat_skill(global) == 84) return (84);
    if (nit_hub_skill(global) == 84) return (84);
    return (0);
}