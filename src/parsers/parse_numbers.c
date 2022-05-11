/*
** EPITECH PROJECT, 2022
** parser
** File description:
** parse_numbers
*/

#include "rpg.h"

sfBool get_int_from_file(const char *path, char *name, int *value)
{
    int i = 0;
    (*value) = 0;
    char *str = get_file_info(path, name);
    if (str == NULL) return (false);
    for (; str[i] != '\0'; i += 1)
        if (str[i] == '=')
            break;
    if ((my_strcmp(str, "Error") == 0) ||
    str[i] != '=' || str[i + 1] == '\0') {
        free(str);
        return (false);
    }
    (*value) = my_atoi(&str[i + 1]);
    free(str);
    return (true);
}

sfBool get_double_from_file(const char *path, char *name, double *value)
{
    int i = 0;
    (*value) = 0;
    char *str = get_file_info(path, name);
    if (str == NULL) return (false);
    for (; str[i] != '\0'; i += 1)
        if (str[i] == '=')
            break;
    if ((my_strcmp(str, "Error") == 0) ||
    str[i] != '=' || str[i + 1] == '\0') {
        free(str);
        return (false);
    }
    (*value) = my_atof(&str[i + 1]);
    free(str);
    return (true);
}

sfBool get_pos_from_file(const char *path, char *name, sfVector2f *pos)
{
    int i = 0;
    (*pos) = (sfVector2f) {0, 0};
    char *str = get_file_info(path, name);
    if (str == NULL) return (false);
    for (; str[i] != '\0'; i += 1)
        if (str[i] == '=')
            break;
    if ((my_strcmp(str, "Error") == 0) ||
    str[i] != '=' || str[i + 1] == '\0') {
        free(str);
        return (false);
    }
    i += 1;
    pos->x = my_atof(&str[i]);
    while (str[i] != '\0' && str[i] != ',')
        i ++;
    pos->y = my_atof(&str[i + 1]);
    return (true);
}
