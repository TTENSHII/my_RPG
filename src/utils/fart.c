/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** fart
*/

#include "rpg.h"

void draw_square(framebuffer_t *framebuffer, sfVector2f pos, int size)
{
    int i = 0;
    int j = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            my_put_pixel(framebuffer, pos.x + i, pos.y + j, sfGreen);
        }
    }
}

void init_fart(global_t *global)
{
    global->fart->clock.clock = sfClock_create();
    global->fart->clock.second = 0;
    global->fart->buff_fart = create_framebuffer(50, 50);
    global->fart->sp_fart = sfSprite_create();
    global->fart->tx_fart = sfTexture_create(50, 50);
    global->fart->fart_time.second = 0;
    global->fart->fart_time.clock = sfClock_create();
}

void update_fart(global_t *global)
{
    if (global->fart->fart_time.second >= 1)
        global->player->is_farting = 0;
    global->fart->fart_time.time =
    sfClock_restart(global->fart->fart_time.clock);
    global->fart->fart_time.second +=
    global->fart->fart_time.time.microseconds / 1000000.0;
    int pos_x = rand() % 50;
    int pos_y = rand() % 50;
    int size = rand() % (5 - 2) + 2;
    global->fart->clock.time =
    sfClock_restart(global->fart->clock.clock);
    global->fart->clock.second +=
    global->fart->clock.time.microseconds / 1000000.0;
    if (global->fart->clock.second < 0.1) return;
    global->fart->clock.second = 0;
    clear_buffer(global->fart->buff_fart);
    for (int i = 0; i < 25; i++) {
        draw_square(global->fart->buff_fart,
        (sfVector2f){pos_x, pos_y}, size);
        pos_x = rand() % 50;
        pos_y = rand() % 50;
        size = rand() % (5 - 2) + 2;
    }
    sfTexture_updateFromPixels(global->fart->tx_fart,
    global->fart->buff_fart->pixels, 50, 50, 0, 0);
    sfSprite_setTexture(global->fart->sp_fart, global->fart->tx_fart,
    sfTrue);
}

void display_fart(global_t *global)
{
    float player_pos_x = global->player->pos.x;
    float player_pos_y = global->player->pos.y;
    sfVector2f pos = {player_pos_x, player_pos_y};
    sfSprite_setPosition(global->fart->sp_fart, pos);
    sfRenderWindow_drawSprite(global->main->window,
    global->fart->sp_fart, NULL);
}
