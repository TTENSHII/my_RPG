/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday05-vincent.ballandi
** File description:
** my_is_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (int i = 0; i <= __INT16_MAX__; i++) {
        if (my_is_prime(i))
            return i;
    }
    return 0;
}
