/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday03-vincent.ballandi
** File description:
** my_isneg
*/

int my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
