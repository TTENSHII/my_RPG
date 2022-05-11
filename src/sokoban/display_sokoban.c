/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** display_sokoban
*/

#include "rpg.h"

static void disp_map(map_t *map, sfRenderWindow *window)
{
    for (map_t *tmp = map; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(window, tmp->sp, NULL);
    }
}

static void disp_player(player_t *player, sfRenderWindow *window)
{
    if (player->direction == LEFT)
        sfRenderWindow_drawSprite(window, player->sp[LEFT], NULL);
    if (player->direction == RIGHT)
        sfRenderWindow_drawSprite(window, player->sp[RIGHT], NULL);
    if (player->direction == UP)
        sfRenderWindow_drawSprite(window, player->sp[UP], NULL);
    if (player->direction == DOWN)
        sfRenderWindow_drawSprite(window, player->sp[DOWN], NULL);
}

void display_sprite_sokoban(global_t *global)
{
    sfView_setCenter(global->main->view, (sfVector2f) {1920 / 2 , 1080 / 2});
    sfRenderWindow_setView(global->main->window, global->main->view);
    sfRenderWindow_clear(global->main->window, sfBlack);
    disp_map(global->sokoban->map, global->main->window);
    disp_player(&global->sokoban->player, global->main->window);
    sfRenderWindow_drawSprite(global->main->window, global->sokoban->sp, NULL);
}
