/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** event_math
*/

#include "rpg.h"

static void manage_button_math(global_t *global)
{
    sfVector2f vect_button1a =
    sfSprite_getPosition(global->sprite->math_button[MATH_BUTTON1A_OFF]);

    if (global->main->event.mouseButton.x >= vect_button1a.x &&
        global->main->event.mouseButton.x <= vect_button1a.x + 70 &&
        global->main->event.mouseButton.y >= vect_button1a.y &&
        global->main->event.mouseButton.y <= vect_button1a.y + 55) {
        global->global_value->math_answer[0] = 1;
        }
}

static void manage_button_math_2(global_t *global)
{
    sfVector2f vect_button1b =
    sfSprite_getPosition(global->sprite->math_button[MATH_BUTTON1B_OFF]);

    if (global->main->event.mouseButton.x >= vect_button1b.x &&
        global->main->event.mouseButton.x <= vect_button1b.x + 70 &&
        global->main->event.mouseButton.y >= vect_button1b.y &&
        global->main->event.mouseButton.y <= vect_button1b.y + 55) {
        global->global_value->math_answer[0] = 2;
        }
}

static void manage_button_math_3(global_t *global)
{
    sfVector2f vect_button1c =
    sfSprite_getPosition(global->sprite->math_button[MATH_BUTTON1C_OFF]);

    if (global->main->event.mouseButton.x >= vect_button1c.x &&
        global->main->event.mouseButton.x <= vect_button1c.x + 70 &&
        global->main->event.mouseButton.y >= vect_button1c.y &&
        global->main->event.mouseButton.y <= vect_button1c.y + 55) {
        global->global_value->math_answer[0] = 3;
        }
}

static void manage_things(global_t *global)
{
    if ((global->global_value->math_answer[0] == 2) &&
        global->global_value->math_answer[1] == 3
        && global->global_value->math_answer[2] == 1) {
        global->global_value->math_answer[3] = 1;
        }
    if ((global->global_value->math_answer[0] == 2) &&
        global->global_value->math_answer[1] == 3
        && global->global_value->math_answer[2] == 1
        && sfKeyboard_isKeyPressed(sfKeyEnter)) {
        if (global->player->skills.units[MAT] != 1)
            global->player->skills.units[MAT] += 1;
        global->scene = GAME;
        }
}

void manage_math_event(global_t *global)
{
    manage_things(global);
    if (global->main->event.type != sfEvtMouseButtonPressed)
        return;
    manage_button_math(global);
    manage_button_math_2(global);
    manage_button_math_3(global);
    manage_math_event2(global);
    manage_math_event3(global);
    return;
}