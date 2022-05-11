/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-vincent.ballandi
** File description:
** my_strcmp
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int index = 0;

    for (int i = 0; s1[i] || s2[i]; i++) {
        index = s1[i] - s2[i];
        if (s1[i] != s2[i])
            return index;
    }
    return 0;
}
