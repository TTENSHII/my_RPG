/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday05-vincent.ballandi
** File description:
** my_is_prime
*/

int my_compute_power_rec(int nb, int p);

int my_is_prime(int nb)
{
    int i = my_compute_power_rec(2, nb) - 2;

    if (nb == 0 || nb == 1)
        return 0;
    if (i % nb == 0)
        return 1;
    else
        return 0;
}
