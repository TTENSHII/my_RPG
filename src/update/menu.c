/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** menu
*/

#include "rpg.h"

void update_menu(global_t *global)
{
    sfVector2f vect_n = sfSprite_getPosition(global->sprite->button[NEW]);
    sfVector2f vect_l = sfSprite_getPosition(global->sprite->button[LOAD]);
    sfVector2f vect_s = sfSprite_getPosition(global->sprite->button[SETTING]);
    sfVector2f vect_e = sfSprite_getPosition(global->sprite->button[EXIT]);
    sfVector2f vect_h = sfSprite_getPosition(global->sprite->button[HELP]);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->main->window);
    sfVector2f tab[5] = {vect_n, vect_l, vect_e, vect_s, vect_h};
    int clic = 1 + sfMouse_isButtonPressed(sfMouseLeft);

    for (int i = 0; i != 5; i++) {
        if (mouse.x > tab[i].x && mouse.x < tab[i].x + 251 &&
        mouse.y > tab[i].y && mouse.y < tab[i].y + 67) {
            sfSprite_setTexture(global->sprite->button[i],
            global->texture->button[i][clic], sfTrue);
        } else {
            sfSprite_setTexture(global->sprite->button[i],
            global->texture->button[i][0], sfTrue);
        }
    }
}
