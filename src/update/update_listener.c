/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** update_listener
*/

#include "rpg.h"

int update_listener(global_t *global)
{
    if (global->scene >= 0 && global->scene <= 12)
        update_tab[global->scene].func(global);
    return (0);
}
