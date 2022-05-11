/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_menu
*/

#include "rpg.h"

const char *tab[] = {".png", "_selected.png", "_clic.png"};

int init_button_n_menu(global_t *global)
{
    char path[] = "assets/menu/new/new";

    global->sprite->button[NEW] = sfSprite_create();
    for (int i = 0; i != 3; i++) {
        global->texture->button[NEW][i] =
        sfTexture_createFromFile(my_strfcat(path, tab[i]), NULL);
        if (!global->texture->button[NEW][i])
            return 84;
    }
    sfSprite_setTexture(global->sprite->button[NEW],
    global->texture->button[NEW][1], sfTrue);
    sfSprite_setPosition(global->sprite->button[NEW],
    (sfVector2f) {700, 320});
    return 0;
}

int init_button_l_menu(global_t *global)
{
    char path[] = "assets/menu/load/load";

    global->sprite->button[LOAD] = sfSprite_create();
    for (int i = 0; i != 3; i++) {
        global->texture->button[LOAD][i] =
        sfTexture_createFromFile(my_strfcat(path, tab[i]), NULL);
        if (!global->texture->button[LOAD][i])
            return 84;
    }
    sfSprite_setTexture(global->sprite->button[LOAD],
    global->texture->button[LOAD][0], sfTrue);
    sfSprite_setPosition(global->sprite->button[LOAD],
    (sfVector2f) {700, 420});
    return 0;
}

int init_button_e_menu(global_t *global)
{
    char path[] = "assets/menu/exit/exit";

    global->sprite->button[EXIT] = sfSprite_create();
    for (int i = 0; i != 3; i++) {
        global->texture->button[EXIT][i] =
        sfTexture_createFromFile(my_strfcat(path, tab[i]), NULL);
        if (!global->texture->button[EXIT][i])
            return 84;
    }
    sfSprite_setTexture(global->sprite->button[EXIT],
    global->texture->button[EXIT][0], sfTrue);
    sfSprite_setPosition(global->sprite->button[EXIT],
    (sfVector2f) {1250, 780});
    return 0;
}

int init_button_s_menu(global_t *global)
{
    char path[] = "assets/menu/settings/settings";

    global->sprite->button[SETTING] = sfSprite_create();
    for (int i = 0; i != 3; i++) {
        global->texture->button[SETTING][i] =
        sfTexture_createFromFile(my_strfcat(path, tab[i]), NULL);
        if (!global->texture->button[SETTING][i])
            return 84;
    }
    sfSprite_setTexture(global->sprite->button[SETTING],
    global->texture->button[SETTING][0], sfTrue);
    sfSprite_setPosition(global->sprite->button[SETTING],
    (sfVector2f) {700, 510});
    return 0;
}

int init_button_h_menu(global_t *global)
{
    char path[] = "assets/menu/help/help";

    global->sprite->button[HELP] = sfSprite_create();
    for (int i = 0; i != 3; i++) {
        global->texture->button[HELP][i] =
        sfTexture_createFromFile(my_strfcat(path, tab[i]), NULL);
        if (!global->texture->button[HELP][i])
            return 84;
    }
    sfSprite_setTexture(global->sprite->button[HELP],
    global->texture->button[HELP][0], sfTrue);
    sfSprite_setPosition(global->sprite->button[HELP],
    (sfVector2f) {700, 600});
    return 0;
}
