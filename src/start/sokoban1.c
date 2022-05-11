/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** sokoban1
*/

#include "rpg.h"

void ini_map(sokoban_t *sokoban)
{
    for (int y = 0; sokoban->map_char[y] != NULL; y ++)
        for (int x = 0; sokoban->map_char[y][x] != '\0'; x ++) {
            if (sokoban->map_char[y][x] == 'P') {
                sokoban->player.pos.x = x * 48;
                sokoban->player.pos.y = y * 48;
            }
            if (sokoban->map_char[y][x] == ' ') {
                add_node_start(sokoban, y, x, sokoban->map_char[y][x]);
            } else if (sokoban->map_char[y][x] == 'O') {
                add_node_start(sokoban, y, x, 'O');
            } else {
                add_node_start(sokoban, y, x, ' ');
                add_node_end(sokoban, y, x, sokoban->map_char[y][x]);
            }
        }
}

static int init_texture(sokoban_t *sokoban)
{
    sokoban->tx[0] = sfTexture_createFromFile("assets/sokoban/1.png", NULL);
    sokoban->tx[1] = sfTexture_createFromFile("assets/sokoban/2.png", NULL);
    sokoban->tx[2] = sfTexture_createFromFile("assets/sokoban/3.png", NULL);
    sokoban->tx[3] = sfTexture_createFromFile("assets/sokoban/4.png", NULL);
    sokoban->tx[4] = sfTexture_createFromFile("assets/sokoban/ESC.png", NULL);
    if (sokoban->tx[0] == NULL || sokoban->tx[1] == NULL ||
        sokoban->tx[2] == NULL || sokoban->tx[3] == NULL ||
        sokoban->tx[4] == NULL) {
        write_error("Error: please verify the sokoban assets\n");
        return (84);
    }
    return (0);
}

static int get_conf(const char *path, player_t *player)
{
    get_string_from_file(path, "name", &player->name);
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

static int ini_player(player_t *player, char *path)
{
    player->rect = (sfIntRect) {0, 0, 48, 48};
    if (get_conf(path, player) == sfFalse)
        return (84);
    for (int i = 0; i <= 3; i += 1) {
        player->sp[i] = sfSprite_create();
        sfSprite_setTexture(player->sp[i], player->tx[i], sfTrue);
        sfSprite_setPosition(player->sp[i], player->pos);
        sfSprite_setTextureRect(player->sp[i], player->rect);
    }
    player->direction = 0;
    player->velocity = (sfVector2f) {0, 0};
    player->inventory = NULL;
    player->is_walking = 0;
    player->clock.clock = sfClock_create();
    player->clock.second = 0;
}

int start_sokoban(global_t *global)
{
    global->sokoban->win = 0;
    global->sokoban->clock.clock = sfClock_create();
    global->sokoban->clock.second = 0;
    if (init_texture(global->sokoban) == 84)
        return (84);
    global->sokoban->sp = sfSprite_create();
    sfSprite_setTexture(global->sokoban->sp, global->sokoban->tx[4], sfTrue);
    sfSprite_setPosition(global->sokoban->sp, (sfVector2f) {1610, 310});
    global->sokoban->map_char = create_map_char();
    global->sokoban->map = NULL;
    ini_map(global->sokoban);
    if (ini_player(&global->sokoban->player,
    global->load_save->save->path) == 84)
        return (84);
    global->scene = SOKOBAN;
    return (0);
}
