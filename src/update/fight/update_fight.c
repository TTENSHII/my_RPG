/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update_fight
*/

#include "rpg.h"

static void update_texts_and_clock(global_t *global)
{
    global->fight->clock_anims.time =
    sfClock_getElapsedTime(global->fight->clock_anims.clock);
    global->fight->clock_anims.second +=
    global->fight->clock_anims.time.microseconds / 1000000.0;
    sfClock_restart(global->fight->clock_anims.clock);
    global->fight->clock_npc.time =
    sfClock_getElapsedTime(global->fight->clock_npc.clock);
    global->fight->clock_npc.second =
    global->fight->clock_npc.time.microseconds / 1000000.0;
    global->fight->clock.time =
    sfClock_getElapsedTime(global->fight->clock.clock);
    global->fight->clock.second =
    global->fight->clock.time.microseconds / 1000000.0;
    sfText_setString(global->fight->texts->player_life,
    my_int_to_str(global->fight->player->life));
    sfText_setString(global->fight->texts->npc_life,
    my_int_to_str(global->fight->npc->life));
    if (global->fight->player_turn == true)
        sfText_setString(global->fight->texts->jutsu,
        "Your turn : choose a jutsu");
}

void anims_fight_update(global_t *global)
{
    if (global->fight->is_animation == false) return;
    if (global->fight->player_attack == 1 && global->fight->clock.second > 2) {
        char *str = malloc(sizeof(char) * 400);
        str = my_strcpy(str, global->fight->player->name);
        str = my_strcat(str, " has inflicted ");
        str = my_strcat(str,
        my_int_to_str(global->fight->player->jutsudammage));
        str = my_strcat(str, " damage to ");
        str = my_strcat(str, global->fight->npc->name);
        sfText_setString(global->fight->texts->jutsu, str);
    }
    restart_clock_fight(global);
}

static void update_rect(global_t *global)
{
    if (global->fight->player_attack == false &&
    global->fight->npc_attack == false)
        return;
    if (global->fight->clock_anims.second > 1) {
        global->fight->clock_anims.second = 0;
        global->fight->nb_sprites += 1;
        if (global->fight->nb_sprites >= 3)
            global->fight->nb_sprites = 0;
    }
}

static void update_life_bar(sfRectangleShape *life_bar, int life)
{
    sfVector2f size = sfRectangleShape_getSize(life_bar);

    size.x = (float)life / 100 * 600;
    sfRectangleShape_setSize(life_bar, size);
    if (life <= 30)
        sfRectangleShape_setFillColor(life_bar, sfRed);
    if (life > 30 && life <= 60)
        sfRectangleShape_setFillColor(life_bar, sfYellow);
    if (life > 60)
        sfRectangleShape_setFillColor(life_bar, sfGreen);
}

void update_fight(global_t *global)
{
    update_texts_and_clock(global);
    update_rect(global);
    update_life_bar(global->fight->life_bar[0], global->fight->player->life);
    update_life_bar(global->fight->life_bar[1], global->fight->npc->life);
    if (global->main->event.key.code == sfKeyEscape) {
        end_fight(global);
        global->scene = GAME;
        return;
    }
    event_update_fight(global);
}
