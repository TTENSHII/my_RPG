/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** new
*/

#include "rpg.h"
#include <sys/stat.h>
#include <fcntl.h>

static void write_list(global_t *global, int fd)
{
    write(fd, "credit=0", 8);
    write(fd, "\n", 1);
    write(fd, "tx1=./assets/player/left.png\n", 29);
    write(fd, "tx2=./assets/player/right.png\n", 30);
    write(fd, "tx3=./assets/player/up.png\n", 27);
    write(fd, "tx4=./assets/player/down.png\n", 29);
    write(fd, "score=0.5\n", 10);
    write(fd, "PSU=0\n", 6);
    write(fd, "CPE=0\n", 6);
    write(fd, "MUL=0\n", 6);
    write(fd, "MAT=0\n", 6);
    write(fd, "HUB=0\n", 6);
    write(fd, "PC=", 3);
    write(fd, my_int_to_str(global->player->take_pc),
    my_strlen(my_int_to_str(global->player->take_pc)));
}

static char *write_save(global_t *global)
{
    char *str = malloc(sizeof(char) * my_strlen(global->texts->str) + 20);

    str = my_strcpy(str, "./confs/saves/");
    str = my_strcat(str, global->texts->str);
    if (global->load_save->save->path != NULL)
        free(global->load_save->save->path);
    global->load_save->save->path = my_strdup(str);
    int fd = open(str, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd == -1)
        return NULL;
    write(fd, "name=", 5);
    write(fd, global->texts->str, my_strlen(global->texts->str));
    write(fd, "\n", 1);
    write(fd, "pos=3150,1340", 13);
    write(fd, "\n", 1);
    write(fd, "speed=10\n", 9);
    write_list(global, fd);
    return str;
}

static void event_click_new_game(global_t *global)
{
    char *str = NULL;
    sfVector2f pos_start = sfSprite_getPosition(global->sprite->new_game[1]);
    sfVector2f pos_back = sfSprite_getPosition(global->sprite->new_game[3]);

    if (global->main->event.type != sfEvtMouseButtonPressed) return;
    if (global->main->event.mouseButton.x >= pos_start.x &&
        global->main->event.mouseButton.x <= pos_start.x + 625 &&
        global->main->event.mouseButton.y >= pos_start.y &&
        global->main->event.mouseButton.y <= pos_start.y + 126) {
        str = write_save(global);
        init_player(global->player, str);
        global->scene = GAME;
    }
    if (global->main->event.mouseButton.x >= pos_back.x &&
        global->main->event.mouseButton.x <= pos_back.x + 625 &&
        global->main->event.mouseButton.y >= pos_back.y &&
        global->main->event.mouseButton.y <= pos_back.y + 126) {
        global->scene = MENU;
    }
}

static void event_keyboard_input(global_t *global)
{
    if (global->main->event.type != sfEvtTextEntered) return;
    if (global->main->event.text.unicode < 128 && \
        global->main->event.text.unicode > 31 &&
        global->global_value->index_new < 16) {
        global->texts->str[global->global_value->index_new] =
        global->main->event.text.unicode;
        global->texts->str[global->global_value->index_new + 1] = '\0';
        sfText_setString(global->texts->text_new, global->texts->str);
        sfText_setFont(global->texts->text_new, global->texts->font);
        sfText_setColor(global->texts->text_new, sfWhite);
        sfText_setCharacterSize(global->texts->text_new, 50);
        global->global_value->index_new++;
    }
}

void manage_new_save_event(global_t *global)
{
    event_click_new_game(global);
    event_keyboard_input(global);
}
