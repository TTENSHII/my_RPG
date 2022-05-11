/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** render_window
*/

#include "rpg.h"

sfRenderWindow *create_render_window(int x, int y, int bpp, char *title)
{
    sfVideoMode videomode = {x, y, bpp};
    sfRenderWindow *window = sfRenderWindow_create(videomode, title,
    sfClose, NULL);
    return (window);
}
