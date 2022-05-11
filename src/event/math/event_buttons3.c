/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** event_buttons3
*/

#include "rpg.h"

static void manage_button_math(global_t *global)
{
    sfVector2f vect_button1a =
    sfSprite_getPosition(global->sprite->math_button[MATH_BUTTON3A_OFF]);

    if (global->main->event.mouseButton.x >= vect_button1a.x &&
        global->main->event.mouseButton.x <= vect_button1a.x + 70 &&
        global->main->event.mouseButton.y >= vect_button1a.y &&
        global->main->event.mouseButton.y <= vect_button1a.y + 55) {
        global->global_value->math_answer[2] = 1;
        }
}

static void manage_buttons_math_2(global_t *global)
{
    sfVector2f vect_button1b =
    sfSprite_getPosition(global->sprite->math_button[MATH_BUTTON3B_OFF]);

    if (global->main->event.mouseButton.x >= vect_button1b.x &&
        global->main->event.mouseButton.x <= vect_button1b.x + 70 &&
        global->main->event.mouseButton.y >= vect_button1b.y &&
        global->main->event.mouseButton.y <= vect_button1b.y + 55) {
        global->global_value->math_answer[2] = 2;
        }
}

static void manage_buttons_math_3(global_t *global)
{
    sfVector2f vect_button1c =
    sfSprite_getPosition(global->sprite->math_button[MATH_BUTTON3C_OFF]);

    if (global->main->event.mouseButton.x >= vect_button1c.x &&
        global->main->event.mouseButton.x <= vect_button1c.x + 70 &&
        global->main->event.mouseButton.y >= vect_button1c.y &&
        global->main->event.mouseButton.y <= vect_button1c.y + 55) {
        global->global_value->math_answer[2] = 3;
        }
}

void manage_math_event3(global_t *global)
{
    manage_button_math(global);
    manage_buttons_math_2(global);
    manage_buttons_math_3(global);
}