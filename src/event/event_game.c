/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** event_game
*/

#include "rpg.h"

static void player_event(global_t *global)
{
    global->player->is_walking = sfFalse;
    global->player->velocity = (sfVector2f) {0, 0};
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        global->player->velocity.y -= 160;
        global->player->direction = UP;
        global->player->is_walking = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        global->player->velocity.x -= 160;
        global->player->direction = LEFT;
        global->player->is_walking = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        global->player->velocity.y += 160;
        global->player->direction = DOWN;
        global->player->is_walking = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        global->player->velocity.x += 160;
        global->player->direction = RIGHT;
        global->player->is_walking = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        global->player->velocity.x *= 2;
        global->player->velocity.y *= 2;
    }
    if (global->player->velocity.x == 0 && global->player->velocity.y == 0)
        global->player->is_walking = sfFalse;
}

static void player_interaction(global_t *global)
{
    if (global->global_value->npc_id == CLEMENT && global->player->take_pc == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyG)) {
            if (start_sokoban(global) == 84)
                return;
        }
    }
    if (global->global_value->npc_id == NICOLAS && global->player->take_pc == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyG))
            global->scene = MATH;
    }
    if (global->global_value->npc_id == YANNICK && global->player->take_pc == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyG))
            global->scene = HUNTER;
    }
    if (global->global_value->npc_id == 3 && global->player->take_pc == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyG))
            global->global_value->hub_index[1] = 1;
        if (global->global_value->hub_index[0] == 5 &&
        sfKeyboard_isKeyPressed(sfKeyC)) {
            global->global_value->hub_index[0]++;
            global->player->skills.units[HUB] = 1;
        }
    }
    if (global->global_value->npc_id > 0 && global->global_value->npc_id < 6
    && sfKeyboard_isKeyPressed(sfKeyF) && global->player->take_pc == 1) {
        start_fight_intro(global);
    }
}

void player_talk_with_npc2(global_t *global)
{
    if (global->global_value->npc_id == 13 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char*) NATHAN_MSG);
    }
    if (global->global_value->npc_id == 7 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char*) GWENDO_MSG);
    }
    if (global->global_value->npc_id == 17 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char*) TENSHI_MSG);
    }
    if (global->global_value->npc_id == 16 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char*) ANTONIN_MSG);
    }
}

void player_talk_with_npc3(global_t *global)
{
    if (global->global_value->npc_id == 14 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char*) REMI_MSG);
    }
    if (global->global_value->npc_id == 10 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char*) MARCO_MSG);
    }
}

static void player_talk_with_npc(global_t *global)
{
    if (global->main->event.type != sfEvtKeyPressed) return;
    reset_text(global);
    if (global->global_value->npc_id == 3 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char *) LILY_MSG);
    }
    if (global->global_value->npc_id == YANNICK &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char*) YANNICK_MSG);
    }
    if (global->global_value->npc_id == NICOLAS &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char*) NICOLAS_MSG);
    }
    if (global->global_value->npc_id == CLEMENT &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        sfSound_play(global->music->sound_click);
        global->bubbule_text->index_text = 0;
        global->bubbule_text->is_valid = 0;
        global->bubbule_text->text = my_strdup((char*) CLEMENT_MSG);
    }
    player_talk_with_npc3(global);
    player_talk_with_npc2(global);
}

static void choose_scene(global_t *global)
{
    if ((global->main->event.type == sfEvtKeyPressed) &&
    (global->main->event.key.code == sfKeyEscape))
        global->scene = INFO;
}

void manage_game_event(global_t *global)
{
    choose_scene(global);
    save_aer_game(global);
    player_interaction(global);
    player_event(global);
    player_talk_with_npc(global);
    if (sfKeyboard_isKeyPressed(sfKeyP)) {
        if (global->player->is_farting == 0) {
            global->fart->clock.second = 0;
            global->fart->fart_time.second = 0;
            global->player->is_farting = 1;
            sfSound_play(global->music->sound_fart);
        }
    }
    if (global->global_value->display_notice == 1)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||
    sfKeyboard_isKeyPressed(sfKeySpace))
        global->global_value->display_notice = 1;
}
