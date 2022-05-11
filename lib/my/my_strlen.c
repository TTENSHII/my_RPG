/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday04-vincent.ballandi
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int count = 0;

    for (; str[count]; count++);
    return count;
}
