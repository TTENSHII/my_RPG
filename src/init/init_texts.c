/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** ini_texts
*/

#include "rpg.h"

char *my_int_to_str(int nb)
{
    int nb_size = 1, nb_div = 1;

    for (int temp = nb; temp >= 10; temp = temp / 10)
        nb_size += 1;
    char *str = malloc(sizeof(char) * nb_size + 1);
    str[nb_size] = '\0';
    nb_size -= 1;
    while (nb_size >= 0) {
        str[nb_size] = nb % 10 + 48;
        nb = nb / 10;
        nb_size -= 1;
    }
    return (str);
}

int ini_texts(global_t *global)
{
    global->texts->font = sfFont_createFromFile("assets/texts/test.ttf");
    global->texts->font2 = sfFont_createFromFile("assets/texts/light.ttf");
    global->bubbule_text->sftext = sfText_create();
    global->bubbule_text->sftext2 = sfText_create();
    if (!global->texts->font || !global->texts->font2) return (84);
    global->bubbule_text->clock = sfClock_create();
    global->texts->txt_fps = sfText_create();
    global->texts->txt_nb_fps = sfText_create();
    sfText_setFont(global->texts->txt_fps, global->texts->font2);
    sfText_setFont(global->texts->txt_nb_fps, global->texts->font2);
    sfText_setString(global->texts->txt_fps, "FPS: ");
    sfText_setString(global->texts->txt_nb_fps, "0");
    sfText_setPosition(global->texts->txt_nb_fps, (sfVector2f){100, 0});
    return (0);
}

int init_text_volume(global_t *global)
{
    global->texts->sfText_volume = sfText_create();
    global->global_value->volume = 50;
    if (!global->texts->sfText_volume) return (84);
    sfText_setFont(global->texts->sfText_volume, global->texts->font);
    sfText_setCharacterSize(global->texts->sfText_volume, 50);
    sfText_setPosition(global->texts->sfText_volume, (sfVector2f) {1300, 450});
    return 0;
}
