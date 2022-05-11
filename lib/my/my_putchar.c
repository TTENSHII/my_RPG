/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday07-vincent.ballandi
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
