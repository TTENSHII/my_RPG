/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** colisions
*/

#include "rpg.h"

static int is_a_wall(sokoban_t *sokoban, float pos_x, float pos_y)
{
    for (int y = 0; sokoban->map_char[y]; y += 1) {
        for (int x = 0; sokoban->map_char[y][x]; x += 1) {
            if ((pos_x + 40 > (x * 48) &&
            pos_x <  ((x * 48) + 40) &&
            pos_y + 43 >  (y * 48) &&
            pos_y < ((y * 48) + 46))
            && (sokoban->map_char[y][x] == '#'))
                return (true);
        }
    }
    return (false);
}

static int can_box_moove(map_t *tmp, float second, sokoban_t *sokoban)
{
    float pos_x = tmp->pos.x + (second * sokoban->player.velocity.x);
    float pos_y = tmp->pos.y + (second * sokoban->player.velocity.y);

    for (int y = 0; sokoban->map_char[y]; y += 1) {
        for (int x = 0; sokoban->map_char[y][x]; x += 1) {
            if ((pos_x + 47 > (x * 48) &&
            pos_x <  ((x * 48) + 48) &&
            pos_y + 47 >  (y * 48) &&
            pos_y < ((y * 48) + 47))
            && (sokoban->map_char[y][x] == '#'))
                return (false);
        }
    }
    tmp->pos.x = pos_x;
    tmp->pos.y = pos_y;
    sfSprite_setPosition(tmp->sp, tmp->pos);
    return (true);
}

static int is_a_box(sokoban_t *sokoban, float pos_x,
float pos_y, float seconds)
{
    for (map_t *tmp = sokoban->map; tmp; tmp = tmp->next) {
        if ((pos_x + 40 > tmp->pos.x &&
        pos_x <  (tmp->pos.x + 40) &&
        pos_y + 43 >  tmp->pos.y &&
        pos_y < (tmp->pos.y + 46))
        && (tmp->num == 'X')
        && can_box_moove(tmp, seconds, sokoban) == false)
            return (true);
    }
    return (false);
}

static int can_player_move(sokoban_t *sokoban,
float pos_x, float pos_y, float seconds)
{
    if (is_a_wall(sokoban, pos_x, pos_y) == true)
        return (false);
    if (is_a_box(sokoban, pos_x, pos_y, seconds) == true)
        return (false);
    return (true);
}

void up_player(sokoban_t *sokoban, float seconds)
{
    float new_player_pos_x = (sokoban->player.pos.x +
    (sokoban->player.velocity.x * seconds));
    float new_player_pos_y = (sokoban->player.pos.y +
    (sokoban->player.velocity.y * seconds));
    if (can_player_move(sokoban, new_player_pos_x,
    new_player_pos_y, seconds) == true) {
        sokoban->player.pos.x +=\
        (sokoban->player.velocity.x * seconds);
        sokoban->player.pos.y +=\
        (sokoban->player.velocity.y * seconds);
    }
}
