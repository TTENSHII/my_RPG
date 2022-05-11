/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** update_info
*/

#include "rpg.h"

static void copy_text(sfText *to_copie, sfText *is_copied)
{
    sfText_setString(is_copied, sfText_getString(to_copie));
    return;
}

static void copy_skills_value(global_t *global)
{
    for (int i = 0; i <= 4; i++) {
        sfText_setColor(global->texts->sfText_skills_info[i], sfBlack);
        copy_text(global->texts->sfText_skills[i],
        global->texts->sfText_skills_info[i]);
    }
    return;
}

static void update_pos_inventory(global_t *global)
{
    sfVector2f pos = {55, 80};
    sfVector2f pos_hub = {60, 250};

    for (inventory_t *tmp = global->inventory;
    tmp != NULL; tmp = tmp->next) {
        sfSprite_setPosition(tmp->sp, pos);
        pos.x += 150;
    }
    for (inventory_hub_t *tmp = global->inventory_hub;
    tmp != NULL; tmp = tmp->next) {
        sfSprite_setPosition(tmp->sp, pos_hub);
        pos_hub.x += 165;
    }
    return;
}

void update_info(global_t *global)
{
    sfText_setString(global->texts->text_name, global->player->name);
    copy_skills_value(global);
    update_pos_inventory(global);
    return;
}