/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** sound_effect
*/

#include "rpg.h"

int init_music_background(global_t *global)
{
    global->music->music = sfMusic_createFromFile(MUSIC_BACK);
    if (!global->music->music)
        return 84;
    sfMusic_setLoop(global->music->music, sfTrue);
    sfMusic_play(global->music->music);
    return 0;
}
