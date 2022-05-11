/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** update
*/

#include "rpg.h"

void update_clock(global_t *global)
{
    global->clock.time = sfClock_getElapsedTime(global->clock.clock);
    global->clock.second = global->clock.time.microseconds / 1000000.0;
    sfClock_restart(global->clock.clock);
    char *nbfps = NULL;
    nbfps = my_int_to_str((1 / global->clock.second));
    sfText_setString(global->texts->txt_nb_fps, nbfps);
    global->player->clock.time =\
    sfClock_getElapsedTime(global->player->clock.clock);
    global->player->clock.second = \
    global->player->clock.time.microseconds / 1000000.0;
}

static void update_view(global_t *global)
{
    sfView_setCenter(global->main->view, global->player->pos);
    sfView_setCenter(global->main->wiew_mmap, global->player->pos);
    sfView_setSize(global->main->wiew_mmap, (sfVector2f) {640, 360});
    sfFloatRect rect;
    rect.height = 0.13;
    rect.width = 0.15;
    rect.left = 0.82;
    rect.top = 0.01;
    sfView_setViewport(global->main->wiew_mmap, rect);
    sfView_setSize(global->main->view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(global->main->window, global->main->view);
}

void update_game(global_t *global)
{
    if (global->player->is_farting == true)
        update_fart(global);
    update_pixel(global);
    update_clock(global);
    update_player(global);
    update_view(global);
    if (global->global_value->opti_flag == 0)
        update_rain(global);
}
