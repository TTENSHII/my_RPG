/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday05-vincent.ballandi
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int exp = 1;
    int i = p;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    if (p > 0)
        exp = nb * my_compute_power_rec(nb, p - 1);
    return exp;
}
