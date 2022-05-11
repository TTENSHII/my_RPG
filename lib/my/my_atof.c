/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** convert a string to a double
*/

double after_comma(int index, char *str, double result, int after_comma_nb)
{
    if (str[index] == '.') {
        index += 1;
        while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9') {
            after_comma_nb = after_comma_nb - 1;
            result = result * 10.0;
            result += str[index] - '0';
            index += 1;
        }
    }
    while (after_comma_nb < 0) {
        result = result * 0.1;
        after_comma_nb += 1;
    }
    return (result);
}

double my_atof(char *str)
{
    double result = 0.0;
    int after_comma_nb = 0;
    int index = 0;
    int is_neg = 0;

    if (str[index] == '-') {
        is_neg = 1;
        index += 1;
    }
    while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9') {
        result = result * 10.0;
        result += str[index] - '0';
        index ++;
    }
    result = after_comma(index, str, result, after_comma_nb);
    if (is_neg == 1)
        result = -result;
    return (result);
}
