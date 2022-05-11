/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** display_math_game
*/

#include "rpg.h"

static void answer_display(global_t *global)
{
    sfRenderWindow_drawText(global->main->window,
    global->texts->sfText_math_game[MATH_ANSWER1A], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->texts->sfText_math_game[MATH_ANSWER1B], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->texts->sfText_math_game[MATH_ANSWER1C], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->texts->sfText_math_game[MATH_ANSWER2A], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->texts->sfText_math_game[MATH_ANSWER2B], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->texts->sfText_math_game[MATH_ANSWER2C], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->texts->sfText_math_game[MATH_ANSWER3A], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->texts->sfText_math_game[MATH_ANSWER3B], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->texts->sfText_math_game[MATH_ANSWER3C], NULL);
}

static void display_buttons_math_1(global_t *global)
{
    if (global->global_value->math_answer[0] == 1) {
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON1A], NULL);
    } else
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON1A_OFF], NULL);
    if (global->global_value->math_answer[0] == 2) {
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON1B], NULL);
    } else
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON1B_OFF], NULL);
    if (global->global_value->math_answer[0] == 3) {
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON1C], NULL);
    } else
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON1C_OFF], NULL);
}

static void display_buttons_math_2(global_t *global)
{
    if (global->global_value->math_answer[1] == 1) {
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON2A], NULL);
    } else
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON2A_OFF], NULL);
    if (global->global_value->math_answer[1] == 2) {
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON2B], NULL);
    } else
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON2B_OFF], NULL);
    if (global->global_value->math_answer[1] == 3) {
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON2C], NULL);
    } else
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON2C_OFF], NULL);
}

static void display_buttons_math_3(global_t *global)
{
    if (global->global_value->math_answer[2] == 1) {
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON3A], NULL);
    } else
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON3A_OFF], NULL);
    if (global->global_value->math_answer[2] == 2) {
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON3B], NULL);
    } else
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON3B_OFF], NULL);
    if (global->global_value->math_answer[2] == 3) {
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON3C], NULL);
    } else
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->math_button[MATH_BUTTON3C_OFF], NULL);
}

void display_sprite_math(global_t *global)
{
    sfView_setCenter(global->main->view, (sfVector2f) {1920 / 2 , 1080 / 2});
    sfRenderWindow_setView(global->main->window, global->main->view);
    sfRenderWindow_clear(global->main->window, sfBlack);
    sfRenderWindow_drawSprite(global->main->window,\
        global->sprite->math_game[MATH_BACKGROUND], NULL);
    display_buttons_math_1(global);
    display_buttons_math_2(global);
    display_buttons_math_3(global);
    sfRenderWindow_drawText(global->main->window,\
        global->texts->sfText_math_game[0], NULL);
    sfRenderWindow_drawText(global->main->window,\
        global->texts->sfText_math_game[1], NULL);
    sfRenderWindow_drawText(global->main->window,\
        global->texts->sfText_math_game[2], NULL);
    sfRenderWindow_drawText(global->main->window,\
        global->texts->sfText_math_game[3], NULL);
    answer_display(global);
    if (global->global_value->math_answer[3] == 1) {
        sfRenderWindow_drawText(global->main->window, 
            global->texts->sfText_win_math, NULL);
    }
}