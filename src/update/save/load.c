/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** load
*/

#include "rpg.h"

void update_load_save(global_t *global)
{
    sfText_setString(global->load_save->txt_save, global->load_save->save->save_name);
}
