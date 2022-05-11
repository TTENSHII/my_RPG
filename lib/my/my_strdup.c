/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-leonore.clos-manescau
** File description:
** duplicate a string
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char *str)
{
    int i = 0;
    char *str2 = NULL;

    for (i = 0; str[i] != '\0'; i += 1);
    str2 = malloc(sizeof(char) * i + 1);
    for (i = 0; str[i] != '\0'; i += 1) {
        str2[i] = str[i];
    }
    str2[i] = '\0';
    return(str2);
}
