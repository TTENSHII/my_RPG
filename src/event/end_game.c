/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** end_game
*/

#include "rpg.h"

static void check_mouse_endgame(global_t *global)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f possp = sfSprite_getPosition(global->end_game->sp_button_exit);
    sfVector2f possp2 = sfSprite_getPosition(global->end_game->sp_button_menu);

    if (mouse.x >= possp.x && mouse.x <= 1920 &&
    mouse.y >= possp.y && mouse.y <= possp.y + 100)
        sfSprite_setPosition(global->end_game->sp_button_exit, (sfVector2f) {1320, 690});
    else
        sfSprite_setPosition(global->end_game->sp_button_exit, (sfVector2f) {1330, 690});
    if (mouse.x >= possp2.x && mouse.x <= 1920 &&
    mouse.y >= possp2.y && mouse.y <= possp2.y + 100)
        sfSprite_setPosition(global->end_game->sp_button_menu, (sfVector2f) {1320, 880});
    else
        sfSprite_setPosition(global->end_game->sp_button_menu, (sfVector2f) {1330, 880});
}

static void check_return_menu(global_t *global)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f possp2 = sfSprite_getPosition(global->end_game->sp_button_menu);

    if (mouse.x >= possp2.x && mouse.x <= 1920 &&
    mouse.y >= possp2.y && mouse.y <= possp2.y + 100)
        global->scene = MENU;
}

static void check_exit_game(global_t *global)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f possp = sfSprite_getPosition(global->end_game->sp_button_exit);

    if (mouse.x >= possp.x && mouse.x <= 1920 &&
    mouse.y >= possp.y && mouse.y <= possp.y + 100)
        sfRenderWindow_close(global->main->window);
}


void event_endgame(global_t *global)
{
    check_mouse_endgame(global);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        check_return_menu(global);
        check_exit_game(global);
    }
}
