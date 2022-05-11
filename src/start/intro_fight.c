/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_intro_fight
*/

#include "rpg.h"

static void set_pos(global_t *global)
{
    for (int i = 0; i < 4; i ++) {
        global->fight_intro->sp[i] = sfSprite_create();
        sfSprite_setTexture(global->fight_intro->sp[i],
        global->fight_intro->tx[i], sfTrue);
    }
    sfSprite_setPosition(global->fight_intro->sp[1], (sfVector2f){0, 1080});
    sfSprite_setPosition(global->fight_intro->sp[2], (sfVector2f){0, -1080});
    sfSprite_setPosition(global->fight_intro->sp[3], (sfVector2f){0, 0});
}

static int init_intro_fight(global_t *global)
{
    global->fight_intro->tx[0] =
    sfTexture_createFromFile("assets/combats/blanc.png", NULL);
    global->fight_intro->tx[1] =
    sfTexture_createFromFile("assets/combats/bleu.png", NULL);
    global->fight_intro->tx[2] =
    sfTexture_createFromFile("assets/combats/red.png", NULL);
    global->fight_intro->tx[3] =
    sfTexture_createFromFile("assets/combats/vs.png", NULL);
    if (!global->fight_intro->tx[0] || !global->fight_intro->tx[1] ||
    !global->fight_intro->tx[2] || !global->fight_intro->tx[3]) {
        write_error("You don't have the good asset to run the fight scene\n");
        return (84);
    }
    set_pos(global);
    return (0);
}

int start_fight_intro(global_t *global)             
{
    if (init_intro_fight(global) == 84)
        return (84);
    global->fight_intro->clock.clock = sfClock_create();
    global->clock.second = 0;
    global->fight_intro->finished_animation = 0;
    global->scene = FIGHT_INTRO;
    return (0);
}

void init_value_fight(global_t *global)
{
    init_life_bar(global->fight);
    global->fight->npc_turn = false;
    global->fight->player_turn = true;
    global->fight->is_animation = false;
    global->fight->player_attack = false;
    global->fight->npc_attack = false;
    global->fight->nb_sprites = 0;
    global->fight->player->jutsudammage = 0;
    global->fight->npc->jutsudammage = 0;
    global->fight->npc->jutsuname = my_strdup("putchar");
    global->fight->player->jutsuname = my_strdup("putchar");
    global->scene = FIGHT;
}

int init_jutsu_texture(fight_t *fight)
{
    fight->template_button[0] =
    sfTexture_createFromFile("assets/combats/psu.png", NULL);
    fight->template_button[1] =
    sfTexture_createFromFile("assets/combats/mul.png", NULL);
    fight->template_button[2] =
    sfTexture_createFromFile("assets/combats/mat.png", NULL);
    fight->template_button[3] =
    sfTexture_createFromFile("assets/combats/hub.png", NULL);
    if (fight->template_button[0] == NULL || fight->template_button[1] == NULL ||
        fight->template_button[2] == NULL || fight->template_button[3] == NULL) {
        write_error("Error: can't load button texture\n");
        return (84);
    }
    return 0;
}
