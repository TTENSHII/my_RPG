/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** save
*/

#include "rpg.h"
#include <sys/stat.h>
#include <fcntl.h>

static void save_info(int fd, global_t *global)
{
    write(fd, "name=", 5);
    write(fd, global->player->name, my_strlen(global->player->name));
    write(fd, "\n", 1);
    write(fd, "pos=", 4);
    write(fd, my_int_to_str(global->player->pos.x),
    my_strlen(my_int_to_str(global->player->pos.x)));
    write(fd, ",", 1);
    write(fd, my_int_to_str(global->player->pos.y),
    my_strlen(my_int_to_str(global->player->pos.y)));
    write(fd, "\n", 1);
    write(fd, "speed=10\n", 9);
    write(fd, "credit=", 7);
    write(fd, my_int_to_str(global->player->skills.units[CREDITS]),
    my_strlen(my_int_to_str(global->player->skills.units[CREDITS])));
    write(fd, "\n", 1);
}

static void save_skills(int fd, global_t *global)
{
    write(fd, "[MODULES]\n", 10);
    write(fd, "PSU=", 4);
    write(fd, my_int_to_str(global->player->skills.units[PSU]),
    my_strlen(my_int_to_str(global->player->skills.units[PSU])));
    write(fd, "\n", 1);
    write(fd, "CPE=", 4);
    write(fd, my_int_to_str(global->player->skills.units[CREDITS]),
    my_strlen(my_int_to_str(global->player->skills.units[CREDITS])));
    write(fd, "\n", 1);
    write(fd, "MUL=", 4);
    write(fd, my_int_to_str(global->player->skills.units[MUL]),
    my_strlen(my_int_to_str(global->player->skills.units[MUL])));
    write(fd, "\n", 1);
    write(fd, "MAT=", 4);
    write(fd, my_int_to_str(global->player->skills.units[MAT]),
    my_strlen(my_int_to_str(global->player->skills.units[MAT])));
    write(fd, "\n", 1);
    write(fd, "HUB=", 4);
    write(fd, my_int_to_str(global->player->skills.units[HUB]),
    my_strlen(my_int_to_str(global->player->skills.units[HUB])));
}

static void save_texture(int fd)
{
    write(fd, "tx1=./assets/player/left.png\n", 29);
    write(fd, "tx2=./assets/player/right.png\n", 30);
    write(fd, "tx3=./assets/player/up.png\n", 27);
    write(fd, "tx4=./assets/player/down.png\n", 29);
}

int save_game(global_t *global)
{
    int fd = open(global->load_save->save->path, O_WRONLY | O_TRUNC);

    if (fd == -1) return (84);
    save_info(fd, global);
    save_texture(fd);
    write(fd, "scale=0.5\n", 10);
    save_skills(fd, global);
    write(fd, "\n", 1);
    write(fd, "PC=", 3);
    write(fd, my_int_to_str(global->player->take_pc),
    my_strlen(my_int_to_str(global->player->take_pc)));
    close(fd);
    return 0;
}
