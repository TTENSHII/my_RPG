/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** load
*/

#include "rpg.h"

static void anim_when_mouse_on_button(sfRenderWindow *wnd, load_save_t *load)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wnd);
    sfVector2f pos1 = sfSprite_getPosition(load->sp_left[0]);
    sfVector2f pos2 = sfSprite_getPosition(load->sp_right[0]);

    if (mouse.x > pos1.x && mouse.x < pos1.x + 100 && mouse.y > pos1.y &&
    mouse.y < pos1.y + 100) {
        sfSprite_setScale(load->sp_left[0], (sfVector2f) {0.73, 0.7});
    } else {
        sfSprite_setScale(load->sp_left[0], (sfVector2f) {0.7, 0.7});
    }
    if (mouse.x > pos2.x && mouse.x < pos2.x + 100 && mouse.y > pos2.y &&
    mouse.y < pos2.y + 100) {
        sfSprite_setScale(load->sp_right[0], (sfVector2f) {0.73, 0.7});
    } else {
        sfSprite_setScale(load->sp_right[0], (sfVector2f) {0.7, 0.7});
    }
}

static void manage_click_left(global_t *global, sfRenderWindow *wnd)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f pos1 = sfSprite_getPosition(global->load_save->sp_left[0]);

    if (global->load_save->save->prev == NULL)
        return;
    if (mouse.x > pos1.x && mouse.x < pos1.x + 100 && mouse.y >
    pos1.y && mouse.y < pos1.y + 100) {
        global->load_save->save = global->load_save->save->prev;
    }
}

static void manage_click_right(global_t *global, sfRenderWindow *wnd)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f pos2 = sfSprite_getPosition(global->load_save->sp_right[0]);

    if (global->load_save->save->next == NULL)
        return;
    if (mouse.x > pos2.x && mouse.x < pos2.x + 100 && mouse.y >
    pos2.y && mouse.y < pos2.y + 100) {
        global->load_save->save = global->load_save->save->next;
    }
}

void check_click_play(global_t *global, sfRenderWindow *wnd)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f pos2 = sfSprite_getPosition(global->load_save->sp_play);

    if (mouse.x > pos2.x && mouse.x < pos2.x + 500 && mouse.y >
    pos2.y && mouse.y < pos2.y + 200) {
        sfSprite_setScale(global->load_save->sp_play, (sfVector2f) {1.01, 1.01});
    } else {
        sfSprite_setScale(global->load_save->sp_play, (sfVector2f) {1, 1});
    }
    if (global->main->event.type != sfEvtMouseButtonPressed)
        return;
    if (mouse.x > pos2.x && mouse.x < pos2.x + 500 && mouse.y >
    pos2.y && mouse.y < pos2.y + 200) {
        if (init_player(global->player, global->load_save->save->path) == 84) {
            write_error("Error: can't load player | verif your save");
            return;
        }
        global->scene = GAME;
    }
}

void manage_load_save_event(global_t *global)
{
    anim_when_mouse_on_button(global->main->window, global->load_save);
    if (global->main->event.type == sfEvtMouseButtonPressed)
        manage_click_left(global, global->main->window);
    if (global->main->event.type == sfEvtMouseButtonPressed)
        manage_click_right(global, global->main->window);
    check_click_play(global, global->main->window);
}
