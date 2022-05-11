/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-vincent.ballandi
** File description:
** my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int index = 0;

    for (int i = 0; i < len / 2; i++) {
        index = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = index;
    }
    return str;
}
