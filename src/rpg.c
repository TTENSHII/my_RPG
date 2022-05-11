/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** rpg
*/

#include "rpg.h"

void gameloop(global_t *global, sfRenderWindow *wnd)
{
    while (sfRenderWindow_isOpen(wnd)) {
        if (global->global_value->opti_flag == 0)
            sfRenderWindow_setFramerateLimit(wnd, global->global_value->fps);
        else
            sfRenderWindow_setFramerateLimit(wnd, 240);
        event_listner(global);
        update_listener(global);
        display_listener(global);
        sfRenderWindow_display(wnd);
    }
}

static void check_flag(global_t *global, int argc, char **argv)
{
    global->global_value->opti_flag = 0;
    if (argc < 2)
        return;
    if (my_strcmp(argv[1], "--opti") == 0) {
        global->global_value->opti_flag = 1;
    }
}
static void destroy_music(global_t *global)
{
    sfMusic_destroy(global->music->music);
    sfSound_destroy(global->music->sound_click);
    sfSoundBuffer_destroy(global->music->sound_buffer_click);
    sfSound_destroy(global->music->sound_fart);
    sfSoundBuffer_destroy(global->music->sound_buffer_fart);
}

int main(int ac, char **av)
{
    global_t *global = malloc(sizeof(global_t));

    global->scene = MENU;
    if (malloc_structs(global) == 84)
        return (84);
    check_flag(global, ac, av);
    if (start_config(global) == 84) {
        if (global->main->window != NULL)
            sfRenderWindow_destroy(global->main->window);
        return (84);
    }
    gameloop(global, global->main->window);
    destroy_music(global);
    return (0);
}
