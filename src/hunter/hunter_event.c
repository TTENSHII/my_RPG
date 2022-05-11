/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** hunter_event
*/

#include "rpg.h"

static int event_mouse_handler(global_t *global)
{
    sfVector2f pos_s = sfSprite_getPosition(global->hunter->sprite[1]);
    sfVector2i pos_m = sfMouse_getPositionRenderWindow(global->main->window);

    if (global->main->event.type != sfEvtMouseButtonPressed) return 0;
    if (pos_m.x >= pos_s.x && pos_m.x <= pos_s.x + 300 && pos_m.y >= pos_s.y
        && pos_m.y <= pos_s.y + 150) {
        global->hunter->value[0]++;
        sfSprite_setPosition(global->hunter->sprite[1],
        (sfVector2f) {-50, rand() % 900});
        sfText_setString(global->hunter->sfText_score,
        my_int_to_str(global->hunter->value[0]));
    }
    return 0;
}

void manage_hunter_event(global_t *global)
{
    event_mouse_handler(global);
    return;
}