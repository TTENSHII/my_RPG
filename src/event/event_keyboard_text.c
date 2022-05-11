/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** event_keyboard_text
*/

#include "rpg.h"

void save_aer_game(global_t *global)
{
    if ((global->global_value->npc_id >= 6 ||
    global->global_value->npc_id <= 15) && sfKeyboard_isKeyPressed(sfKeyR))
        save_game(global);    
}

void reset_text(global_t *global)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) ||
    global->global_value->npc_id == 0) {
        global->bubbule_text->is_valid = 1;
        global->bubbule_text->value = OFF;
        global->bubbule_text->index_text = 0;
        global->bubbule_text->text = my_strdup(" ");
    }
}