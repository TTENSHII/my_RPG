/*
** EPITECH PROJECT, 2021
** $$
** File description:
** my_strncmp
*/

int my_strncmp(const char *src1, char const *src2, int n)
{
    int i = 0;

    while (src1[i] != '\0' && src2[i] != '\0' && i < n) {
        if (src1[i] != src2[i])
            return (src1[i] - src2[i]);
        i += 1;
    }
    return (src1[i - 1] - src2[i - 1]);
}
