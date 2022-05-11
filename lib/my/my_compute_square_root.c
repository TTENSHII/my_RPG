/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday05-vincent.ballandi
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    if (nb <= 0)
        return 0;
    if (nb == 1)
        return 1;
    int res = 0;
    for (int i = 1; i < nb; i++) {
        res = i * i;
        if (res == nb)
            return i;
    }
    return 0;
}
