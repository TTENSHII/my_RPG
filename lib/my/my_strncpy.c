/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-vincent.ballandi
** File description:
** my_strncpy
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        if (n > my_strlen(src))
            dest[i] = '\0';
        dest[i] = src[i];
    }
    return dest;
}
