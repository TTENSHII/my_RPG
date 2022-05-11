/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update_fight
*/

#include "rpg.h"

static void update_this_clock(global_t *global)
{
    global->clock.time = sfClock_getElapsedTime(global->clock.clock);
    global->clock.second = global->clock.time.microseconds / 1000000.0;
    sfClock_restart(global->clock.clock);
}

static void check_for_scene_changement(global_t *global)
{
    global->fight_intro->clock.time =
    sfClock_getElapsedTime(global->fight_intro->clock.clock);
    global->fight_intro->clock.second =
    global->fight_intro->clock.time.microseconds / 1000000.0;
    if (global->fight_intro->clock.second >= 1) {
        exit_fight_intro(global);
    }
}

void update_fight_intro(global_t *global)
{
    update_this_clock(global);
    if (global->fight_intro->finished_animation == 1) {
        check_for_scene_changement(global);
        return;
    }
    sfVector2f posrouge = sfSprite_getPosition(global->fight_intro->sp[2]);
    sfVector2f posbleu = sfSprite_getPosition(global->fight_intro->sp[1]);
    posrouge.y += (global->clock.second * 2000);
    posbleu.y -= (global->clock.second * 2000);
    if (posrouge.y >= 0 || posbleu.y <= 0) {
        sfSprite_setPosition(global->fight_intro->sp[2], (sfVector2f) {0, 0});
        sfSprite_setPosition(global->fight_intro->sp[1], (sfVector2f) {0, 0});
        global->fight_intro->finished_animation = 1;
        return;
    }
    sfSprite_setPosition(global->fight_intro->sp[2], posrouge);
    sfSprite_setPosition(global->fight_intro->sp[1], posbleu);
}
