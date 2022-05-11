/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday07-vincent.ballandi
** File description:
** my_strcat
*/

#include <stdlib.h>

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}

static int my_strlen(char const *str)
{
    int count = 0;

    for (; str[count]; count++);
    return count;
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i ++;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i ++;
        j ++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strfcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *temp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    my_strcpy(temp, dest);
    while (temp[i] != '\0')
        i ++;
    while (src[j] != '\0') {
        temp[i] = src[j];
        i ++;
        j ++;
    }
    temp[i] = '\0';
    return (temp);
}

