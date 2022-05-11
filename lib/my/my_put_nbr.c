/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday03-vincent.ballandi
** File description:
** my _put_nbr
*/

int my_putchar(char c);

int my_put_nbr(int nb)
{
    int modup = 0;

    if (nb < 0) {
        nb *= (-1);
        my_putchar('-');
    }
    if (nb >= 10) {
        modup = (nb % 10);
        nb = (nb - modup) / 10;
        my_put_nbr(nb);
        my_putchar(modup + 48);
    } else
        my_putchar(nb + 48);
    return (0);
}
