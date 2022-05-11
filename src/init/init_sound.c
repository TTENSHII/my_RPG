/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_sound
*/

#include "rpg.h"

int init_sound(global_t *global)
{
    global->music->sound_click = sfSound_create();
    global->music->sound_fart = sfSound_create();
    if (global->music->sound_click == NULL || global->music->sound_fart == NULL)
        return (84);
    if ((global->music->sound_buffer_click = sfSoundBuffer_createFromFile(SOUND_CLICK)) == NULL)
        return (84);
    if ((global->music->sound_buffer_fart = sfSoundBuffer_createFromFile(SOUND_FART)) == NULL)
        return (84);
    sfSound_setBuffer(global->music->sound_click,
    global->music->sound_buffer_click);
    sfSound_setBuffer(global->music->sound_fart,
    global->music->sound_buffer_fart);
    return (0);
}