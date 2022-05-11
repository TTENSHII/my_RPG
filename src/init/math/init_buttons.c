/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_buttons
*/

#include "rpg.h"

static void copy_validate_sprite(global_t *global)
{
    for (int i = 0; i <= 8; i++) {
        global->sprite->math_button[i] = sfSprite_create();
        sfSprite_setTexture(global->sprite->math_button[i], \
            global->texture->math_button[0], sfTrue);
    }
    for (int i = 9; i <= 20; i++) {
        global->sprite->math_button[i] = sfSprite_create();
        sfSprite_setTexture(global->sprite->math_button[i], \
            global->texture->math_button[1], sfTrue);
    }
}

static void set_pos_button(global_t *global)
{
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON1A_OFF],
    (sfVector2f) {1920 / 2 - 200, 320});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON1B_OFF],
    (sfVector2f) {1920 / 2, 320});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON1C_OFF],
    (sfVector2f) {1920 / 2 + 200, 320});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON2A_OFF],
    (sfVector2f) {1920 / 2 - 200, 500});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON2B_OFF],
    (sfVector2f) {1920 / 2, 500});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON2C_OFF],
    (sfVector2f) {1920 / 2 + 200, 500});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON3A_OFF],
    (sfVector2f) {1920 / 2 - 200, 700});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON3B_OFF],
    (sfVector2f) {1920 / 2, 700});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON3C_OFF],
    (sfVector2f) {1920 / 2 + 200, 700});
}

static void set_pos_button_on(global_t *global)
{
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON1A],
    (sfVector2f) {1920 / 2 - 200, 320});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON1B],
    (sfVector2f) {1920 / 2, 320});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON1C],
    (sfVector2f) {1920 / 2 + 200, 320});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON2A],
    (sfVector2f) {1920 / 2 - 200, 500});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON2B],
    (sfVector2f) {1920 / 2, 500});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON2C],
    (sfVector2f) {1920 / 2 + 200, 500});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON3A],
    (sfVector2f) {1920 / 2 - 200, 700});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON3B],
    (sfVector2f) {1920 / 2, 700});
    sfSprite_setPosition(global->sprite->math_button[MATH_BUTTON3C],
    (sfVector2f) {1920 / 2 + 200, 700});
}

int init_buttons_math(global_t *global)
{
    global->texture->math_button[1] = \
        sfTexture_createFromFile(BUTTON_VALIDATE, NULL);
    global->texture->math_button[0] = \
        sfTexture_createFromFile(BUTTON_UNVALIDATE, NULL);
    if (!global->texture->math_button[1] || \
        !global->texture->math_button[0])
        return (84);
    global->sprite->math_button[1] = sfSprite_create();
    global->sprite->math_button[0] = sfSprite_create();
    sfSprite_setTexture(global->sprite->math_button[1], \
        global->texture->math_button[1], sfTrue);
    sfSprite_setTexture(global->sprite->math_button[0], \
        global->texture->math_button[0], sfTrue);
    copy_validate_sprite(global);
    set_pos_button(global);
    set_pos_button_on(global);
}
