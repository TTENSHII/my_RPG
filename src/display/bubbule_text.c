/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** bubbule_text
*/

#include "rpg.h"

char *my_strndup(char *str, int n)
{
    int i = 0;
    char *str2 = malloc(sizeof(char) * (n + 1));

    for (i = 0; str[i] != '\0' && i < n; i += 1) {
        str2[i] = str[i];
    }
    str2[i] = '\0';
    return (str2);
}

static void manage_speech_text(global_t *global, sfVector2f pos, char *str)
{
    sfSprite_setPosition(global->sprite->bubbule, pos);
    sfText_setString(global->bubbule_text->sftext, str);
    sfText_setFont(global->bubbule_text->sftext, global->texts->font);
    sfText_setCharacterSize(global->bubbule_text->sftext, 20);
    pos.y += 50;
    pos.x += 10;
    sfText_setPosition(global->bubbule_text->sftext, (pos));
    sfText_setColor(global->bubbule_text->sftext, sfBlack);
    sfClock_restart(global->bubbule_text->clock);
    return;
}

void display_bubble_text(global_t *global, char *text, 
    sfVector2f position, sfText *SfmlText)
{
    char *display_text = NULL;
    display_text = my_strdup(text);
    if (global->bubbule_text->is_valid == 1)
        return;
    sfSprite_setPosition(global->sprite->bubbule, position);
    sfRenderWindow_drawSprite(global->main->window,
    global->sprite->bubbule, NULL);
    sfRenderWindow_drawText(global->main->window,
    global->bubbule_text->sftext, NULL);
    global->bubbule_text->time =
    sfClock_getElapsedTime(global->bubbule_text->clock);
    global->bubbule_text->sec =
    global->bubbule_text->time.microseconds / 1000000.0;
    if (global->bubbule_text->sec < 0.05 || global->bubbule_text->index_text >
    my_strlen(text))
        return;
    display_text = my_strndup(text, global->bubbule_text->index_text);
    global->bubbule_text->index_text++;
    manage_speech_text(global, position, display_text);
    free(display_text);
}
