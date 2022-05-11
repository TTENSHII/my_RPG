/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** display_info
*/

#include "rpg.h"

static void display_inventory(global_t *global)
{
    for (inventory_t *tmp = global->inventory;
    tmp != NULL; tmp = tmp->next) {
        sfSprite_setScale(tmp->sp, (sfVector2f) {3, 3});
        sfRenderWindow_drawSprite(global->main->window, tmp->sp, NULL);
    }
}

static void display_hub(global_t *global)
{
    if (global->global_value->hub_index[0] >= 6)
        return;
    for (inventory_hub_t *tmp = global->inventory_hub;
    tmp != NULL; tmp = tmp->next) {
        sfSprite_setScale(tmp->sp, (sfVector2f) {3, 3});
        sfRenderWindow_drawSprite(global->main->window, tmp->sp, NULL);
    }
}

void display_sprite_info(global_t *global)
{
    sfRenderWindow_clear(global->main->window, sfCyan);
    sfRenderWindow_setView(global->main->window, global->main->interface);
    sfRenderWindow_drawSprite(global->main->window,
    global->sprite->student_card, NULL);
    for (int i = 0; i <= 4; i++) {
        if (i == 1)
            continue;
        sfRenderWindow_drawText(global->main->window,
        global->texts->sfText_skills_info[i], NULL);
    }
    sfRenderWindow_drawText(global->main->window,
    global->texts->text_name, NULL);
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(global->main->window,
        global->sprite->button_pause[i], NULL);
    display_inventory(global);
    display_hub(global);
    return;
}
