/*
** EPITECH PROJECT, 2022
** parser
** File description:
** parse_char
*/

#include "rpg.h"

char *get_file_info(const char *path, char *name)
{
    char *line = NULL;
    int size = my_strlen(name), find = false;
    FILE *file = fopen(path, "r");
    if (file == NULL) return (NULL);
    while (getline(&line, &(size_t) {0}, file) != -1) {
        if (my_strncmp(line, name, size) == 0) {
            find = true;
            break;
        }
    }
    fclose(file);
    if (find == false)
        return (NULL);
    for (int i = 0; line[i] != '\0'; i += 1)
        if (line[i] == '\n')
            line[i] = '\0';
    return (line);
}

sfBool get_string_from_file(const char *path, char *name, char **value)
{
    int i = 0;
    (*value) = NULL;
    char *str = get_file_info(path, name);
    if (str == NULL) return (false);
    for (; str[i] != '\0'; i += 1)
        if (str[i] == '=')
            break;
    if (str[i] != '=' || str[i + 1] == '\0') {
        (*value) = my_strdup("Invalid file");
        free(str);
        return (false);
    }
    (*value) = my_strdup(&str[i + 1]);
    free(str);
    return (true);
}
