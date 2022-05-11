/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** get_map_infos
*/

#include "rpg.h"

static int check_map_file(char *file)
{
    if (file == NULL)
        return (false);
    if (file[0] == '\0' || file[1] == '\0')
        return (false);
    for (int i = 0; file[i + 1] != '\0'; i += 1) {
        if ((file[i] < '0' || file[i] > '9') &&
        (file[i] != '\n' && file[i] != ','))
            return (false);
        if (file[i] == ',' &&
        (file[i + 1] < '0' || file[i + 1] > '9'))
            return (false);
        if (file[i] == '\n' &&
        (file[i + 1] < '0' || file[i + 1] > '9'))
            return (false);
    }
    return (true);
}

static int find_nb_lines(char *file)
{
    int nb_lines = 1;

    for (int i = 0; file[i] != '\0'; i += 1)
        if (file[i] == '\n')
            nb_lines += 1;
    return (nb_lines);
}

static int find_line_size(char *file)
{
    int nb = 1, temp = 0;

    for (int i = 0; file[i] != '\0' && file[i] != '\n'; i += 1)
        if (file[i] == ',')
            nb += 1;
    for (int i = 0; file[i] != '\0'; i += 1) {
        if (file[i] == ',')
            temp += 1;
        if (file[i] == '\n' && temp != (nb - 1)) {
            return (-1);
        } else if (file[i] == '\n') {
            temp = 0;
        }
    }
    return (nb);
}

int get_info_map(int *nb_lines, int *line_size, char *file)
{
    if (check_map_file(file) == false)
        return (84);
    (*nb_lines) = find_nb_lines(file);
    (*line_size) = find_line_size(file);
    return (0);
}
