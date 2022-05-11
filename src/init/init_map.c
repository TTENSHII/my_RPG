/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_map
*/

#include "rpg.h"
#include <unistd.h>

static int find_top(int nb)
{
    int range_start = 0;
    int range_end = 9;
    int value = 0;
    while (nb < range_start || nb > range_end) {
        range_end += 10;
        range_start += 10;
        value += 1;
    }
    value *= 48;
    return (value);
}

void add_case(map_t **map, int y, int x, sfTexture *txt, int nb)
{
    map_t *new = malloc(sizeof(map_t));
    new->next = NULL;
    new->num = nb;
    new->pos = (sfVector2f) {x * 48, y * 48};
    new->sp = sfSprite_create();
    sfSprite_setTexture(new->sp, txt, sfTrue);
    int top = find_top(nb);
    int left = (nb % 10) * 48;
    sfSprite_setTextureRect(new->sp, (sfIntRect) {left, top, 48, 48});
    sfSprite_setPosition(new->sp, new->pos);
    if ((*map) == NULL) {
        (*map) = new;
        return;
    }
    for (map_t *tmp = (*map); tmp != NULL; tmp = tmp->next) {
        if (tmp->next == NULL) {
            tmp->next = new;
            return;
        }
    }
}

int *convert_to_int(char *str)
{
    int x = 0;
    int nb_number = 1;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i += 1)
        if (str[i] == ',')
            nb_number += 1;
    int *tab = malloc(sizeof(int) * (nb_number + 1));

    for (int i = 0; str[i] != '\0' && str[i] != '\n';) {
        while (str[i] < '0' || str[i] > '9')
            i += 1;
        tab[x] = my_atoi(&str[i]);
        x += 1;
        while (str[i] >= '0' && str[i] <= '9')
            i += 1;
    }
    tab[x] = -1;
    return (tab);
}

int **file_to_int_array(char **array, int nb_line)
{
    int i = 0;
    int **tab = malloc(sizeof(int *) * (nb_line + 1));

    for (; array[i] != NULL; i += 1) {
        tab[i] = convert_to_int(array[i]);
    }
    tab[i] = NULL;
    return (tab);
}

static int verif_line(char *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i += 1)
        if (str[i] != ',' && (str[i] < '0' || str[i] > '9'))
            return (0);
    return (1);
}

char **file_to_tab(const char *path, int nb_lines)
{
    int i = 0;
    char **tab = NULL;
    char *line = NULL;

    FILE *file = fopen(path, "r");
    if (file == NULL)
        return (NULL);
    tab = malloc(sizeof(char *) * (nb_lines + 1));
    while (i < nb_lines && (getline(&line, &(size_t) {0}, file) != - 1)) {
        if (verif_line(line) == 0)
            return (NULL);
        tab[i] = my_strdup(line);
        i += 1;
    }
    tab[i] = NULL;
    fclose(file);
    return (tab);
}

static int create_my_map(map_t **map, sfTexture *tx, const char *path)
{
    char **file = file_to_tab(path, 101);
    if (file == NULL) {
        write_error("Error: can't create map\n");
        return (84);
    }
    int **tab = file_to_int_array(file, 101);
    for (int y = 0; tab[y] != NULL; y += 1) {
        for (int x = 0; tab[y][x] != -1; x += 1) {
            add_case(map, y, x, tx, tab[y][x]);
        }
    }
    for (int y = 0; tab[y] != NULL; y += 1) {
        free(tab[y]);
    }
    free(tab);
    return (0);
}

int init_map(global_t *global)
{
    global->map = NULL;
    const char path1[] = "./assets/map/map_base.png";
    const char path2[] = "./assets/map/deco.png";
    const char path3[] = "./confs/map/floor_walls.txt";
    const char path4[] = "./confs/map/decorations.txt";

    global->texture->map[0] = sfTexture_createFromFile(path1, NULL);
    global->texture->map[1] = sfTexture_createFromFile(path2, NULL);
    if (!global->texture->map[0] || !global->texture->map[1])
        return (84);
    if (create_my_map(&global->map, global->texture->map[0], path3) == 84) {
        write_error("Incorrects map files\n");
        return (84);
    }
    if (create_my_map(&global->map, global->texture->map[1], path4) == 84) {
        write_error("Incorrects map files\n");
        return (84);
    }
    return (0);
}
