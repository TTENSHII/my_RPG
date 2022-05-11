/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_player
*/

#include "rpg.h"

static int get_conf(char *path, player_t *player)
{
    get_string_from_file(path, "name", &player->name);
    if (get_pos_from_file(path, "pos", &player->pos) == sfFalse)
        return (sfFalse);
    if (get_texture_from_file(path, "tx1", &player->tx[0]) == sfFalse)
        return (sfFalse);
    if (get_texture_from_file(path, "tx2", &player->tx[1]) == sfFalse)
        return (sfFalse);
    if (get_texture_from_file(path, "tx3", &player->tx[2]) == sfFalse)
        return (sfFalse);
    if (get_texture_from_file(path, "tx4", &player->tx[3]) == sfFalse)
        return (sfFalse);
    return (sfTrue);
}

static void get_player_skills(char *path, player_t *player)
{
    if (get_int_from_file(path, "PSU", &player->skills.units[PSU]) == sfFalse)
        player->skills.units[PSU] = 0;
    if (get_int_from_file(path, "CPE", &player->skills.units[CREDITS]) == sfFalse)
        player->skills.units[CREDITS] = 0;
    if (get_int_from_file(path, "MAT", &player->skills.units[MAT]) == sfFalse)
        player->skills.units[MAT] = 0;
    if (get_int_from_file(path, "MUL", &player->skills.units[MUL]) == sfFalse)
        player->skills.units[MUL] = 0;
    if (get_int_from_file(path, "HUB", &player->skills.units[HUB]) == sfFalse)
        player->skills.units[HUB] = 0;
    if (get_int_from_file(path, "PC", &player->take_pc) == sfFalse)
        player->take_pc = 0;
    for (int i = 0; i < 5; i ++) {
        if (player->skills.units[i] < 0)
            player->skills.units[i] = 0;
    }
}

int init_player(player_t *player, char *path)
{
    player->is_farting = 0;
    player->is_walking = sfFalse;
    player->direction = LEFT;
    player->velocity.x = 0;
    player->velocity.y = 0;
    player->clock.clock = sfClock_create();
    player->clock.second = 0;
    player->rect = (sfIntRect) {0, 0, 48, 48};
    if (get_conf(path, player) == sfFalse)
        return (84);
    get_player_skills(path, player);
    for (int i = 0; i <= 3; i += 1) {
        player->sp[i] = sfSprite_create();
        sfSprite_setTexture(player->sp[i], player->tx[i], sfTrue);
        sfSprite_setPosition(player->sp[i], player->pos);
        sfSprite_setTextureRect(player->sp[i], player->rect);
    }
    return (0);
}
