/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday04-vincent.ballandi
** File description:
** my_getnbr
*/

#include <stdio.h>

int count_sub(char const *str)
{
    int sub = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '-')
            sub++;
    return sub;
}

int my_getnbr(char *str)
{
    int i = 0;
    int result = 0;
    int sub = count_sub(str);

    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10;
            result = result + str[i] - 48;
        }
    }
    if ((sub % 2) != 0 && result > 0)
        return 0;
    if ((sub % 2) == 0 && result < 0)
        return 0;
    if ((sub % 2) != 0)
        return -1 * result;
    else
        return result;
}
