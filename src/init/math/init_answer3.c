/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_answer3
*/

#include "rpg.h"

static int init_math_answer3a(global_t *global)
{
    global->texts->sfText_math_game[MATH_ANSWER3A] = sfText_create();
    sfText_setString(global->texts->sfText_math_game[MATH_ANSWER3A], \
        "Reponse A: 42");
    sfText_setFont(global->texts->sfText_math_game[MATH_ANSWER3A], \
        global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_ANSWER3A], sfBlack);
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_ANSWER3A],
    15);
    sfText_setPosition(global->texts->sfText_math_game[MATH_ANSWER3A], \
        (sfVector2f) {1920 / 2 - 250, 670});
    return (0);
}

static int init_math_answer3b(global_t *global)
{
    global->texts->sfText_math_game[MATH_ANSWER3B] = sfText_create();
    sfText_setString(global->texts->sfText_math_game[MATH_ANSWER3B], \
        "Reponse B: 21");
    sfText_setFont(global->texts->sfText_math_game[MATH_ANSWER3B], \
        global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_ANSWER3B], sfBlack);
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_ANSWER3B],
    15);
    sfText_setPosition(global->texts->sfText_math_game[MATH_ANSWER3B], \
        (sfVector2f) {1920 / 2, 670});
    return (0);
}

static int init_math_answer3c(global_t *global)
{
    global->texts->sfText_math_game[MATH_ANSWER3C] = sfText_create();
    sfText_setString(global->texts->sfText_math_game[MATH_ANSWER3C], \
        "Reponse C: 78");
    sfText_setFont(global->texts->sfText_math_game[MATH_ANSWER3C], \
        global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_ANSWER3C], sfBlack);
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_ANSWER3C],
    15);
    sfText_setPosition(global->texts->sfText_math_game[MATH_ANSWER3C], \
        (sfVector2f) {1920 / 2 + 200, 670});
    return (0);
}

static void init_answer_value(global_t *global)
{
    global->global_value->math_answer[0] = 0;
    global->global_value->math_answer[1] = 0;
    global->global_value->math_answer[2] = 0;
    global->global_value->math_answer[3] = 0;
}

int init_all_math_answer3(global_t *global)
{
    init_answer_value(global);
    init_math_answer3a(global);
    init_math_answer3b(global);
    init_math_answer3c(global);
}