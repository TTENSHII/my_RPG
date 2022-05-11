/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_answer2
*/

#include "rpg.h"

static int init_math_answer2a(global_t *global)
{
    global->texts->sfText_math_game[MATH_ANSWER2A] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_ANSWER2A],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_ANSWER2A], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_ANSWER2A],
    "Reponse A: 24");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_ANSWER2A],
    15);
    sfText_setPosition(global->texts->sfText_math_game[MATH_ANSWER2A], \
        (sfVector2f) {1920 / 2 - 200, 480});
}

static int init_math_answer2b(global_t *global)
{
    global->texts->sfText_math_game[MATH_ANSWER2B] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_ANSWER2B],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_ANSWER2B], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_ANSWER2B],
    "Reponse B: 28");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_ANSWER2B],
    15);
    sfText_setPosition(global->texts->sfText_math_game[MATH_ANSWER2B], \
        (sfVector2f) {1920 / 2, 480});
}

static int init_math_answer2c(global_t *global)
{
    global->texts->sfText_math_game[MATH_ANSWER2C] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_ANSWER2C],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_ANSWER2C], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_ANSWER2C],
    "Reponse C: 20");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_ANSWER2C],
    15);
    sfText_setPosition(global->texts->sfText_math_game[MATH_ANSWER2C], \
        (sfVector2f) {1920 / 2 + 200, 480});
}

static int init_win_text(global_t *global)
{
    global->texts->sfText_win_math = sfText_create();
    sfText_setFont(global->texts->sfText_win_math, global->texts->font);
    sfText_setColor(global->texts->sfText_win_math, sfBlack);
    sfText_setString(global->texts->sfText_win_math,
    "Appuie sur entrer pour valider tes skills.");
    sfText_setCharacterSize(global->texts->sfText_win_math, 20);
    sfText_setPosition(global->texts->sfText_win_math, \
        (sfVector2f) {1920 / 2 - 250, 840});
}

int init_all_math_answer2(global_t *global)
{
    init_win_text(global);
    init_math_answer2a(global);
    init_math_answer2b(global);
    init_math_answer2c(global);
    return (0);
}