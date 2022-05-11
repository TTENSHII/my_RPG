/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}
