/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** sokoban
*/

#include "rpg.h"

void add_node_start(sokoban_t *sokoban, int y, int x, char c)
{
    map_t *new = malloc(sizeof(map_t));
    new->next = NULL;
    new->num = c;
    new->pos = (sfVector2f) {x * 48, y * 48};
    new->sp = sfSprite_create();
    if (c == '#') sfSprite_setTexture(new->sp, sokoban->tx[1], sfTrue);
    if (c == ' ') sfSprite_setTexture(new->sp, sokoban->tx[2], sfTrue);
    if (c == 'X') sfSprite_setTexture(new->sp, sokoban->tx[0], sfTrue);
    if (c == 'O') sfSprite_setTexture(new->sp, sokoban->tx[3], sfTrue);
    sfSprite_setPosition(new->sp, new->pos);
    if (sokoban->map == NULL) {
        sokoban->map = new;
    } else {
        new->next = sokoban->map;
        sokoban->map = new;
    }
}

void add_node_end(sokoban_t *sokoban, int y, int x, char c)
{
    map_t *new = malloc(sizeof(map_t));
    new->next = NULL;
    new->num = c;
    new->pos = (sfVector2f) {x * 48, y * 48};
    new->sp = sfSprite_create();
    if (c == '#') sfSprite_setTexture(new->sp, sokoban->tx[1], sfTrue);
    if (c == ' ') sfSprite_setTexture(new->sp, sokoban->tx[2], sfTrue);
    if (c == 'X') sfSprite_setTexture(new->sp, sokoban->tx[0], sfTrue);
    if (c == 'O') sfSprite_setTexture(new->sp, sokoban->tx[3], sfTrue);
    sfSprite_setPosition(new->sp, new->pos);
    if (sokoban->map == NULL) {
        sokoban->map = new;
    } else {
        map_t *tmp = sokoban->map;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

char **create_map_char(void)
{
    char **map = malloc(sizeof(char * ) * 22);
    map[0] = my_strdup("########################################");
    map[1] = my_strdup("#O    #O                 #             #");
    map[2] = my_strdup("#     #       #######        ###########");
    map[3] = my_strdup("#     #                        X       #");
    map[4] = my_strdup("#     #########          #             #");
    map[5] = my_strdup("#                 ##########           #");
    map[6] = my_strdup("#   X             #                    #");
    map[7] = my_strdup("#                 #       #   ######   #");
    map[8] = my_strdup("##########        #       #        #   #");
    map[9] = my_strdup("#O             P          #        #   #");
    map[10] = my_strdup("#                        #        #    #");
    map[11] = my_strdup("#     #        #############           #");
    map[12] = my_strdup("#     #                    #X###########");
    map[13] = my_strdup("#     #O                   #           #");
    map[14] = my_strdup("#     #########         X  #       #   #");
    map[15] = my_strdup("#                                  #   #");
    map[16] = my_strdup("#            #                 #####   #");
    map[17] = my_strdup("########   X #####         #           #");
    map[18] = my_strdup("#            #                        O#");
    map[19] = my_strdup("#            #            ##############");
    map[20] = my_strdup("########################################");
    map[21] = NULL;
    return (map);
}

void set_texture_fight_player(fight_t *fight)
{
    for (int i = 0; i < 4; i++) {
        fight->player->sp[i] = sfSprite_create();
        sfSprite_setTexture(fight->player->sp[i], fight->player->tx[i], sfTrue);
        sfSprite_setPosition(fight->player->sp[i], (sfVector2f){130, 625});
        sfSprite_setScale(fight->player->sp[i], (sfVector2f){2, 2});
    }
    fight->player->id_jutsu = 0;
}

int init_jutsu_button(fight_t *fight)
{
    if (init_jutsu_texture(fight) == 84)
        return (84);
    for (int i = 0; i < 4; i += 1) {
        fight->rect_jutsu[i] = sfSprite_create();
        sfSprite_setTexture(fight->rect_jutsu[i], fight->template_button[i], sfTrue);
        sfSprite_setPosition(fight->rect_jutsu[i], (sfVector2f){460, 250 + i * 150});
        sfSprite_setScale(fight->rect_jutsu[i], (sfVector2f){1, 1});
    }
    return (0);
}
