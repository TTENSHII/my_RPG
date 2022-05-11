/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** display_listener
*/

#include "rpg.h"

void display_listener(global_t *global)
{
    if (global->scene >= 0 && global->scene <= 12)
        display_tab[global->scene].func(global);
}
