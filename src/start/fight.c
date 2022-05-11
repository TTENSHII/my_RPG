/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** fight
*/

#include "rpg.h"

static int init_fight_scene(fight_t *fight)
{
    fight->clock_npc.second = 0;
    fight->clock_anims.second = 0;
    fight->clock_anims.clock = sfClock_create();
    fight->clock_npc.clock = sfClock_create();
    fight->clock.clock = sfClock_create();
    fight->clock.second = 0;
    fight->tx_bg[0] = sfTexture_createFromFile("assets/combats/bg.png", NULL);
    fight->tx_bg[1] = sfTexture_createFromFile("assets/combats/fight_interface.png", NULL);
    if (fight->tx_bg[0] == NULL || fight->tx_bg[1] == NULL) {
        write_error("Error: can't load fight scene\n");
        return (84);
    }
    fight->sp_bg[0] = sfSprite_create();
    fight->sp_bg[1] = sfSprite_create();
    sfSprite_setTexture(fight->sp_bg[0], fight->tx_bg[0], sfTrue);
    sfSprite_setTexture(fight->sp_bg[1], fight->tx_bg[1], sfTrue);
    return (0);
}

static int init_player_fight(fight_t *fight, char *name)
{
    fight->player = malloc(sizeof(player_t));
    if (fight->player == NULL)
        return (84);
    fight->player->life = 100;
    fight->player->name = my_strdup(name);
    fight->player->tx[0] = sfTexture_createFromFile("assets/npc/tenshi_1.png", NULL);
    fight->player->tx[1] = sfTexture_createFromFile("assets/npc/tenshi_2.png", NULL);
    fight->player->tx[2] = sfTexture_createFromFile("assets/npc/tenshi_3.png", NULL);
    fight->player->tx[3] = sfTexture_createFromFile("assets/npc/tenshi_4.png", NULL);
    if (fight->player->tx[0] == NULL || fight->player->tx[1] == NULL ||
        fight->player->tx[2] == NULL || fight->player->tx[3] == NULL) {
        write_error("Error: can't load player fight\n");
        return (84);
    }
    set_texture_fight_player(fight);
    return (0);
}

static int init_texts_fight(fight_t *fight, sfFont *font)
{
    fight->texts = malloc(sizeof(fight_texts_t));
    fight->texts->jutsu = sfText_create();
    fight->texts->npc_life = sfText_create();
    fight->texts->npc_name = sfText_create();
    fight->texts->player_life = sfText_create();
    fight->texts->player_name = sfText_create();
    if (fight->texts->jutsu == NULL || fight->texts->npc_life == NULL ||
        fight->texts->npc_name == NULL ||
        fight->texts->player_life == NULL ||
        fight->texts->player_name == NULL) {
        write_error("Error: can't load fight texts\n");
        return (84);
    }
    set_text_fight(fight, font);
    return (0);
}

void init_life_bar(fight_t *fight)
{
    fight->life_bg[0] = sfRectangleShape_create();
    fight->life_bg[1] = sfRectangleShape_create();
    fight->life_bar[0] = sfRectangleShape_create();
    fight->life_bar[1] = sfRectangleShape_create();
    sfRectangleShape_setSize(fight->life_bg[0], (sfVector2f){610, 46});
    sfRectangleShape_setSize(fight->life_bg[1], (sfVector2f){610, 46});
    sfRectangleShape_setSize(fight->life_bar[0], (sfVector2f){600, 40});
    sfRectangleShape_setSize(fight->life_bar[1], (sfVector2f){600, 40});
    sfRectangleShape_setFillColor(fight->life_bg[0], sfWhite);
    sfRectangleShape_setFillColor(fight->life_bg[1], sfWhite);
    sfRectangleShape_setFillColor(fight->life_bar[0], sfYellow);
    sfRectangleShape_setFillColor(fight->life_bar[1], sfYellow);
    sfRectangleShape_setPosition(fight->life_bg[0], (sfVector2f){200, 100});
    sfRectangleShape_setPosition(fight->life_bg[1], (sfVector2f){1110, 100});
    sfRectangleShape_setPosition(fight->life_bar[0], (sfVector2f){205, 103});
    sfRectangleShape_setPosition(fight->life_bar[1], (sfVector2f){1115, 103});
}

int start_fight(global_t *global, npc_t *npc)
{
    if (init_jutsu_button(global->fight) == 84)
        return (84);
    if (init_fight_npc(global->fight, npc) == 84)
        return (84);
    if (init_fight_scene(global->fight) == 84)
        return (84);
    if (init_player_fight(global->fight, global->player->name) == 84)
        return (84);
    if (init_texts_fight(global->fight, global->texts->font2) == 84)
        return (84);
    init_value_fight(global);
    return (0);
}