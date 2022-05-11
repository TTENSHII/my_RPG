/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** display_game
*/

#include "rpg.h"
#include <string.h>

static void display_hub(hub_t *hub, sfRenderWindow *window, global_t *global)
{
    for (hub_t *tmp = hub; tmp != NULL; tmp = tmp->next) {
        if (tmp->is_on == false) {
            sfRenderWindow_drawSprite(window, tmp->sp, NULL);
            sfRenderWindow_drawCircleShape(window, tmp->circle, NULL);
        }
    }
    if (global->global_value->hub_index[0] == 6)
        sfRenderWindow_drawSprite(window, global->sprite->robot, NULL);
}

static void display_player(player_t *player, sfRenderWindow *window)
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



static int draw_units_score(global_t *global)
{
    char *string = NULL; 
    for (int i = 0; i <= 4; i ++) {
        
        sfText_setString(global->texts->sfText_skills[i],
        string = my_int_to_str(global->player->skills.units[i]));
        sfRenderWindow_drawText(global->main->window,
        global->texts->sfText_skills[i], NULL);
    }
}

void map2(map_t *map, sfRenderWindow *window, player_t *player)
{
    for (map_t *tmp = map; tmp != NULL; tmp = tmp->next) {
        if (tmp->num == 29 || tmp->num == 37)
            continue;
        if (tmp->pos.x - 1100 < player->pos.x && tmp->pos.x + 1100 >
        player->pos.x && tmp->pos.y - 1100 < player->pos.y &&
        tmp->pos.y + 1100 > player->pos.y)
            sfRenderWindow_drawSprite(window, tmp->sp, NULL);
    }
}

void map1(map_t *map, sfRenderWindow *window, player_t *player)
{
    for (map_t *tmp = map; tmp != NULL; tmp = tmp->next) {
        if (tmp->num != 29 && tmp->num != 37)
            continue;
        if (tmp->pos.x - 1100 < player->pos.x && tmp->pos.x + 1100 >
        player->pos.x && tmp->pos.y - 1100 < player->pos.y &&
        tmp->pos.y + 1100 > player->pos.y)
            sfRenderWindow_drawSprite(window, tmp->sp, NULL);
    }
}

void map2opti(map_t *map, sfRenderWindow *window, player_t *player)
{
    for (map_t *tmp = map; tmp != NULL; tmp = tmp->next) {
        if (tmp->num == 29 || tmp->num == 37)
            continue;
        if (tmp->pos.x - 990 < player->pos.x && tmp->pos.x + 990 >
        player->pos.x && tmp->pos.y - 600 < player->pos.y &&
        tmp->pos.y + 600 > player->pos.y)
            sfRenderWindow_drawSprite(window, tmp->sp, NULL);
    }
}

void map1opti(map_t *map, sfRenderWindow *window, player_t *player)
{
    for (map_t *tmp = map; tmp != NULL; tmp = tmp->next) {
        if (tmp->num != 29 && tmp->num != 37)
            continue;
        if (tmp->pos.x - 990 < player->pos.x && tmp->pos.x + 990 >
        player->pos.x && tmp->pos.y - 600 < player->pos.y &&
        tmp->pos.y + 600 > player->pos.y)
            sfRenderWindow_drawSprite(window, tmp->sp, NULL);
    }
}

void display_map(global_t *global, sfRenderWindow *wd)
{
    sfRenderWindow_setView(wd, global->main->view);
    map1(global->map, wd, global->player);
    display_player(global->player, wd);
    map2(global->map,wd, global->player);
    display_npc(global->npc, wd);
    if (global->player->take_pc != 1)
        display_objects(global->objects, wd);
    display_hub(global->hub, wd, global);
    sfRenderWindow_drawSprite(wd, global->sprite->floor_particule, NULL);
    if (global->player->is_farting == 1)
        display_fart(global);
}

void display_map_opti(global_t *global, sfRenderWindow *wd)
{
    sfRenderWindow_setView(wd, global->main->view);
    map1opti(global->map, wd, global->player);
    display_player(global->player, wd);
    map2opti(global->map,wd, global->player);
    display_npc(global->npc, wd);
    display_objects(global->objects, wd);
    display_hub(global->hub, wd, global);
    sfRenderWindow_drawSprite(wd, global->sprite->floor_particule, NULL);
    if (global->player->is_farting == 1)
        display_fart(global);
}

void display_minimap(global_t *global)
{
    sfRenderWindow_setView(global->main->window, global->main->wiew_mmap);
    map1(global->map, global->main->window, global->player);
    display_player(global->player, global->main->window);
    map2(global->map, global->main->window, global->player);
    display_npc(global->npc, global->main->window);
}

void display_interface(global_t *global, sfRenderWindow *wd)
{
    sfRenderWindow_setView(wd, global->main->interface);
    sfRenderWindow_drawSprite(wd, global->sprite->interface, NULL);
    sfRenderWindow_drawText(wd, global->texts->txt_fps, NULL);
    sfRenderWindow_drawText(wd, global->texts->txt_nb_fps, NULL);
    if (global->global_value->npc_id != 0 && global->global_value->npc_id <= 7)
        sfRenderWindow_drawSprite(wd, global->sprite->npc_interfaces, NULL);
    draw_units_score(global);
    if (global->global_value->npc_id != 0 && global->global_value->npc_id <= 6
    || global->global_value->npc_id == 13 || global->global_value->npc_id == 14
    || global->global_value->npc_id == 10 || global->global_value->npc_id == 7
    || global->global_value->npc_id == 16 || global->global_value->npc_id == 17)
        display_bubble_text(global, global->bubbule_text->text,
        (sfVector2f) {1920 / 2, 900}, global->bubbule_text->sftext);
    if (global->global_value->npc_id == 3 &&
    global->global_value->hub_index[0] == 5)
        sfRenderWindow_drawSprite(wd, global->sprite->interface_game[0], NULL);
    if (global->global_value->npc_id != 0 && global->global_value->npc_id >= 6)
        sfRenderWindow_drawSprite(wd, global->sprite->interface_game[1], NULL);
    if (global->global_value->is_on == 1)
        sfRenderWindow_drawSprite(wd, global->sprite->interface_game[2], NULL);
    if (global->global_value->display_notice == 0 &&
    global->player->take_pc == 0)
        sfRenderWindow_drawSprite(wd, global->sprite->notice, NULL);
}

void display_sprite_game(global_t *global)
{
    sfRenderWindow_clear(global->main->window, sfBlack);
    if (global->global_value->opti_flag == 0)
        display_rain(global);
    if (global->global_value->opti_flag == 0)
        display_map(global, global->main->window);
    if (global->global_value->opti_flag == 1)
        display_map_opti(global, global->main->window);
    display_interface(global, global->main->window);
    if (global->global_value->opti_flag == 0)
        display_minimap(global);
    return;
}
