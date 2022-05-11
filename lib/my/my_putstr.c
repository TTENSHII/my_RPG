/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday04-vincent.ballandi
** File description:
** my_putstr
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}
