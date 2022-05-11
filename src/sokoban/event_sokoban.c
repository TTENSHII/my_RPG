/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event_sokoban
*/

#include "rpg.h"

static void plauer_soko(sokoban_t *sokoban)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        sokoban->player.velocity = (sfVector2f) {0, 130};
        sokoban->player.direction = DOWN;
        sokoban->player.is_walking = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        sokoban->player.velocity = (sfVector2f) {130, 0};
        sokoban->player.direction = RIGHT;
        sokoban->player.is_walking = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        sokoban->player.velocity.x *= 2;
        sokoban->player.velocity.y *= 2;
    }
}

static void player_soko_event(sokoban_t *sokoban)
{
    sokoban->player.is_walking = sfFalse;
    sokoban->player.velocity = (sfVector2f) {0, 0};
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        sokoban->player.velocity = (sfVector2f) {0, -130};
        sokoban->player.direction = UP;
        sokoban->player.is_walking = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        sokoban->player.velocity = (sfVector2f) {-130, 0};
        sokoban->player.direction = LEFT;
        sokoban->player.is_walking = sfTrue;
    }
    plauer_soko(sokoban);
}

void manage_sokoban_event(global_t *global)
{
    player_soko_event(global->sokoban);
}
