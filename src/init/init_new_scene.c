/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_new_scene
*/

#include "rpg.h"

static int init_texture_new_scene(global_t *global)
{
    global->texture->new_game[0] = sfTexture_createFromFile(
        "assets/new_game/background.png", NULL);
    global->texture->new_game[1] = sfTexture_createFromFile(
        "assets/new_game/start_game.png", NULL);
    global->texture->new_game[2] = sfTexture_createFromFile(
        "assets/new_game/insertion.png", NULL);
    global->texture->new_game[4] = sfTexture_createFromFile(
        "assets/new_game/enter_name.png", NULL);
    global->texture->new_game[3] = sfTexture_createFromFile(
        "assets/new_game/back_to_menu.png", NULL);
    if (!global->texture->new_game[0] || !global->texture->new_game[1] || 
        !global->texture->new_game[2] || !global->texture->new_game[3] ||
        !global->texture->new_game[4])
        return (84);
    return 0;
}

static void init_text_player(global_t *global)
{
    global->texts->text_new = sfText_create();
    global->texts->str = malloc(sizeof(char) * 15 + 1);
    global->texts->str[0] = 'a';
    global->texts->str[1] = '\0';
    global->global_value->index_new = 0;
    sfText_setPosition(global->texts->text_new, (sfVector2f) {720, 420});
}

int init_new_scene(global_t *global)
{
    global->global_value->index_new = 0;
    init_text_player(global);
    if (init_texture_new_scene(global) == 84)
        return (84);
    for (int i = 0; i < 5; i++) {
        global->sprite->new_game[i] = sfSprite_create();
        sfSprite_setTexture(global->sprite->new_game[i],
            global->texture->new_game[i], sfTrue);
    }
    sfSprite_setPosition(global->sprite->new_game[1], (sfVector2f) {1250, 900});
    sfSprite_setPosition(global->sprite->new_game[2], (sfVector2f) {550, 385});
    sfSprite_setPosition(global->sprite->new_game[4], (sfVector2f) {720, 420});
    sfSprite_setPosition(global->sprite->new_game[3], (sfVector2f) {20, 900});
    return 0;
}