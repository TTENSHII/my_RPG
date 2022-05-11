/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update_sokoban
*/

#include "rpg.h"

static void update_sprite(sokoban_t *sokoban)
{
    for(int i = 0; i <= 3; i ++)
        sfSprite_setPosition(sokoban->player.sp[i], sokoban->player.pos);
    if (sokoban->clock.second > 0.2 && sokoban->player.is_walking == true) {
        sfClock_restart(sokoban->clock.clock);
        sokoban->player.rect.left += 48;
        if (sokoban->player.rect.left >= 48 * 4)
            sokoban->player.rect.left = 0;
    }
    if (sokoban->player.is_walking == false)
        sokoban->player.rect = (sfIntRect) {0, 0, 48, 48};
    for (int i = 0; i <= 3; i ++)
        sfSprite_setTextureRect(sokoban->player.sp[i], sokoban->player.rect);
}

static int check_if_storage_is_full(sokoban_t *sokoban, map_t *tmp)
{
    for (map_t *tmp_2 = sokoban->map; tmp_2; tmp_2 = tmp_2->next) {
        if (tmp_2->num != 'X')
            continue;
        if (tmp_2->pos.x >= tmp->pos.x - 10 &&
        tmp_2->pos.x < tmp->pos.x + 10 &&
        tmp_2->pos.y >= tmp->pos.y - 10 && tmp_2->pos.y < tmp->pos.y + 10)
            return (false);
    }
    return (true);
}

static int check_win(sokoban_t *sokoban)
{
    int end = 0;

    for (map_t *tmp = sokoban->map; tmp; tmp = tmp->next) {
        if (tmp->num == 'O')
            end += check_if_storage_is_full(sokoban, tmp);
    }
    if (end == 0) {
        sokoban->win = 1;
        return (true);
    }
    return (false);
}

void update_sokoban(global_t *global)
{
    global->sokoban->clock.time =
    sfClock_getElapsedTime(global->sokoban->clock.clock);
    global->sokoban->clock.second =
    (global->sokoban->clock.time.microseconds / 1000000.0);
    update_clock(global);
    up_player(global->sokoban, global->clock.second);
    update_sprite(global->sokoban);
    if (check_win(global->sokoban) == true)
        exit_sokoban(global);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
       reset_my_sokoban(global->sokoban);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        exit_sokoban(global);
}
