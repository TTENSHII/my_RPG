/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** config_game
*/

#include "rpg.h"

int init_endgame(global_t *global)
{
    global->end_game->sp_bg = sfSprite_create();
    global->end_game->sp_button_exit = sfSprite_create();
    global->end_game->sp_button_menu = sfSprite_create();
    global->end_game->tx_bg =
    sfTexture_createFromFile("assets/end_game/end.png", NULL);
    global->end_game->tx_button_exit =
    sfTexture_createFromFile("assets/end_game/exit.png", NULL);
    global->end_game->tx_button_menu =
    sfTexture_createFromFile("assets/end_game/btm.png", NULL);
    if (!global->end_game->tx_bg || !global->end_game->tx_button_exit ||
    !global->end_game->tx_button_menu)
        return (84);
    sfSprite_setTexture(global->end_game->sp_bg,\
    global->end_game->tx_bg, sfTrue);
    sfSprite_setTexture(global->end_game->sp_button_exit,\
    global->end_game->tx_button_exit, sfTrue);
    sfSprite_setTexture(global->end_game->sp_button_menu,\
    global->end_game->tx_button_menu, sfTrue);
    sfSprite_setPosition(global->end_game->sp_button_exit, (sfVector2f) {1330, 690});
    sfSprite_setPosition(global->end_game->sp_button_menu, (sfVector2f) {1330, 880});
    sfSprite_setScale(global->end_game->sp_button_exit, (sfVector2f) {0.8, 0.8});
    sfSprite_setScale(global->end_game->sp_button_menu, (sfVector2f) {0.8, 0.8});
    return (0);
}

int init_value_two(global_t *global)
{
    global->player->take_pc = 0;
    global->global_value->display_notice = 0;
    global->texture->notice = sfTexture_createFromFile("assets/notice.png", NULL);
    if (!global->texture->notice)
        return (84);
    global->sprite->notice = sfSprite_create();
    sfSprite_setTexture(global->sprite->notice, global->texture->notice,
    sfTrue);
    sfSprite_setPosition(global->sprite->notice, (sfVector2f) {0, -35});
    if (init_sound(global) == 84)
        return (84);
    if (ini_texts(global) == 84)
        return (84);
    if (init_text_volume(global) == 84)
        return (84);
    if (init_music_background(global) == 84)
        return (84);
    if (init_all_settings(global) == 84)
        return (84);
    return (0);
}
