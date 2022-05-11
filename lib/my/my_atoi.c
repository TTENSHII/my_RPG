/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int nb = 0, index = 0, is_neg = 0;

    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
            nb = (nb * 10) + (str[index] - 48);
        } else {
            return (nb);
        }
        index ++;
    }
    return (nb);
}
