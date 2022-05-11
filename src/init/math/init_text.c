/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_text
*/

#include "rpg.h"

int init_header_text(global_t *global)
{
    global->texts->sfText_math_game[MATH_HEADER] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_HEADER],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_HEADER], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_HEADER],
    "MATH GAME");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_HEADER], 100);
    sfText_setPosition(global->texts->sfText_math_game[MATH_HEADER], \
        (sfVector2f) {1920 / 2 - 250, 100});
}

static int init_math_answer1a(global_t *global)
{
    global->texts->sfText_math_game[MATH_ANSWER1A] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_ANSWER1A],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_ANSWER1A], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_ANSWER1A],
    "Reponse A: 100");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_ANSWER1A], 15);
    sfText_setPosition(global->texts->sfText_math_game[MATH_ANSWER1A], \
        (sfVector2f) {1920 / 2 - 200, 300});
}

static int init_math_answer1b(global_t *global)
{
    global->texts->sfText_math_game[MATH_ANSWER1B] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_ANSWER1B],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_ANSWER1B], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_ANSWER1B],
    "Reponse B: 55");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_ANSWER1B], 15);
    sfText_setPosition(global->texts->sfText_math_game[MATH_ANSWER1B], \
        (sfVector2f) {1920 / 2, 300});
}

static int init_math_answer1c(global_t *global)
{
    global->texts->sfText_math_game[MATH_ANSWER1C] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_ANSWER1C],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_ANSWER1C], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_ANSWER1C],
    "Reponse C: 42");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_ANSWER1C], 15);
    sfText_setPosition(global->texts->sfText_math_game[MATH_ANSWER1C], \
        (sfVector2f) {1920 / 2 + 200, 300});
}

int init_all_math_answer1(global_t *global)
{
    init_math_answer1a(global);
    init_math_answer1b(global);
    init_math_answer1c(global);
}