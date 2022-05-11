/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_math_game
*/

#include "rpg.h"

static int init_text_quest1(global_t *global)
{
    global->texts->sfText_math_game[MATH_TEXT1] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_TEXT1],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_TEXT1], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_TEXT1],
    "Question : Quelle est la valeur de 5 + 5 * 10 ?");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_TEXT1], 20);
    sfText_setPosition(global->texts->sfText_math_game[MATH_TEXT1],
    (sfVector2f){750, 230});
    return 0;
}

static int init_text_quest2(global_t *global)
{
    global->texts->sfText_math_game[MATH_TEXT2] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_TEXT2],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_TEXT2], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_TEXT2],
    "Question : Quelle est la valeur 24 / 2 + 4 * 2 ?");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_TEXT2], 20);
    sfText_setPosition(global->texts->sfText_math_game[MATH_TEXT2],
    (sfVector2f){720, 400});
    return 0;
}

static int init_text_quest3(global_t *global)
{
    global->texts->sfText_math_game[MATH_TEXT3] = sfText_create();
    sfText_setFont(global->texts->sfText_math_game[MATH_TEXT3],
    global->texts->font);
    sfText_setColor(global->texts->sfText_math_game[MATH_TEXT3], sfBlack);
    sfText_setString(global->texts->sfText_math_game[MATH_TEXT3],
    "Question : Quelle est la valeur de 7894 / 87 * 4 - 338 ?");
    sfText_setCharacterSize(global->texts->sfText_math_game[MATH_TEXT3], 20);
    sfText_setPosition(global->texts->sfText_math_game[MATH_TEXT3],
    (sfVector2f){700, 600});
    return 0;
}

static int init_background_paper(global_t *global)
{
    global->texture->math_game[MATH_BACKGROUND] = sfTexture_createFromFile(
        MATH_BACK, NULL);
    if (!global->texture->math_game[MATH_BACKGROUND])
        return (84);
    global->sprite->math_game[MATH_BACKGROUND] = sfSprite_create();
    sfSprite_setTexture(global->sprite->math_game[MATH_BACKGROUND], \
        global->texture->math_game[MATH_BACKGROUND], sfTrue);
    return (0);
}

int check_math_texture(global_t *global)
{
    if (init_background_paper(global) == 84)
        return (84);
    if (init_buttons_math(global) == 84)
        return (84);
    init_header_text(global);
    init_text_quest1(global);
    init_text_quest2(global);
    init_text_quest3(global);
    init_all_math_answer1(global);
    init_all_math_answer2(global);
    init_all_math_answer3(global);
    return (0);
}