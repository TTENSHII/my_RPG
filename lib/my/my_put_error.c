/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** my_put_error
*/

#include <unistd.h>

static int find_size(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void write_error(char *str)
{
    write(2, str, find_size(str));
}
