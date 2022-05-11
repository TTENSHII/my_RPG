/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** fight_intro
*/

#include "rpg.h"

void display_fight_intro(global_t *global)
{
    sfRenderWindow_setView(global->main->window,
    global->main->interface);
    for (int i = 0; i < 4; i ++) {
        sfRenderWindow_drawSprite(global->main->window,
        global->fight_intro->sp[i], NULL);
    }
}

static void display_fight_end(global_t *global)
{
    sfRenderWindow_drawText(global->main->window, 
    global->fight->texts->npc_name, NULL);
    sfRenderWindow_drawText(global->main->window, 
    global->fight->texts->player_life, NULL);
    sfRenderWindow_drawText(global->main->window, 
    global->fight->texts->player_name, NULL);
    sfRenderWindow_drawRectangleShape(global->main->window,
    global->fight->life_bg[0], NULL);
    sfRenderWindow_drawRectangleShape(global->main->window,
    global->fight->life_bg[1], NULL);
    sfRenderWindow_drawRectangleShape(global->main->window,
    global->fight->life_bar[0], NULL);
    sfRenderWindow_drawRectangleShape(global->main->window,
    global->fight->life_bar[1], NULL);
}

static void display_button(global_t *global)
{
    if (global->fight->player_turn == false)
        return;
    if (global->fight->is_animation == true)
        return;
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(global->main->window,
    global->fight->rect_jutsu[i], NULL);
}

void display_fight(global_t *global)
{
    sfRenderWindow_setView(global->main->window,
    global->main->interface);
    sfRenderWindow_drawSprite(global->main->window,
    global->fight->sp_bg[0], NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->fight->sp_bg[1], NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->fight->player->sp[global->fight->nb_sprites], NULL);
    sfRenderWindow_drawSprite(global->main->window,
    global->fight->npc->sp[global->fight->nb_sprites], NULL);
    sfRenderWindow_drawText(global->main->window,
    global->fight->texts->jutsu, NULL);
    sfRenderWindow_drawText(global->main->window, 
    global->fight->texts->npc_life, NULL);
    display_fight_end(global);
    display_button(global);
    if (global->fight->is_animation == 1 &&
    (global->fight->player_attack == 1 || global->fight->npc_attack == 1))
        sfRenderWindow_drawText(global->main->window, global->fight->texts->jutsu, NULL);
}
