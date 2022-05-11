/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** new
*/

#include "rpg.h"

static void display_left_right_button(sfRenderWindow *window, load_save_t *load)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos1 = sfSprite_getPosition(load->sp_left[0]);
    sfVector2f pos2 = sfSprite_getPosition(load->sp_right[0]);

    if (sfMouse_isButtonPressed(sfMouseLeft) && mouse.x > pos1.x && mouse.x <
    pos1.x +100 && mouse.y > pos1.y && mouse.y < pos1.y + 100) {
        sfRenderWindow_drawSprite(window, load->sp_left[1], NULL);
    } else {
        sfRenderWindow_drawSprite(window, load->sp_left[0], NULL);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && mouse.x > pos2.x && mouse.x <
    pos2.x + 100 && mouse.y > pos2.y && mouse.y < pos2.y + 100) {
        sfRenderWindow_drawSprite(window, load->sp_right[1], NULL);
    } else {
        sfRenderWindow_drawSprite(window, load->sp_right[0], NULL);
    }
}

void display_load_save_event(global_t *global)
{
    sfRenderWindow_setView(global->main->window, global->main->interface);
    sfRenderWindow_drawSprite(global->main->window, global->load_save->sp_bg, NULL);
    sfRenderWindow_drawSprite(global->main->window, global->load_save->sp_button, NULL);
    display_left_right_button(global->main->window, global->load_save);
    sfRenderWindow_drawText(global->main->window, global->load_save->txt_save, NULL);
    sfRenderWindow_drawSprite(global->main->window, global->load_save->sp_play, NULL);
}
