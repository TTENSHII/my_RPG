/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** event_menu
*/

#include "rpg.h"

static void manage_click_button(global_t *global)
{
    sfVector2f vect_n = sfSprite_getPosition(global->sprite->button[NEW]);
    sfVector2f vect_l = sfSprite_getPosition(global->sprite->button[LOAD]);
    sfVector2f vect_s = sfSprite_getPosition(global->sprite->button[SETTING]);
    sfVector2f vect_e = sfSprite_getPosition(global->sprite->button[EXIT]);
    sfVector2f vect_h = sfSprite_getPosition(global->sprite->button[HELP]);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f tab[4] = {vect_n, vect_l, vect_s, vect_h};
    int scenes[4] = {NEW_SAVE, LOAD_SAVE, 2, DISPLAY_HELP};

    if (global->main->event.type != sfEvtMouseButtonReleased) return;
    for (int i = 0; i < 4; i++) {
        if (mouse.x > tab[i].x && mouse.x < tab[i].x + 251 &&
        mouse.y > tab[i].y && mouse.y < tab[i].y + 67) {
            sfSound_play(global->music->sound_click);
            global->scene = scenes[i];
        }
    }
    if (mouse.x > vect_e.x && mouse.x < vect_e.x + 251 &&
        mouse.y > vect_e.y && mouse.y < vect_e.y + 67)
        sfRenderWindow_close(global->main->window);
}

void manage_menu_event(global_t *global)
{
    manage_click_button(global);
    if (sfKeyboard_isKeyPressed(sfKeyP))
        global->global_value->volume = 0;
    return;
}
