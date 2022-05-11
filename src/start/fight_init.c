/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** fight_init
*/

#include "rpg.h"

static int add_npc_jutsu(fight_t *fight, char *path, char *name, char *dmg)
{
    jutsu_t *new = malloc(sizeof(jutsu_t));
    if (get_string_from_file(path, name, &new->name) == false)
        return (84);
    if (get_int_from_file(path, dmg, &new->dammages) == false)
        return (84);
    new->next = NULL;
    if (fight->npc->jutsu == NULL)
        fight->npc->jutsu = new;
    else {
        new->next = fight->npc->jutsu;
        fight->npc->jutsu = new;
    }
    return (0);
}

static int init_npc_jutsu(fight_t *fight, char *path)
{
    fight->npc->jutsu = NULL;

    if (add_npc_jutsu(fight, path, "jt1name", "jt1damage") == 84)
        return (84);
    if (add_npc_jutsu(fight, path, "jt2name", "jt2damage") == 84)
        return (84);
    if (add_npc_jutsu(fight, path, "jt3name", "jt3damage") == 84)
        return (84);
    if (add_npc_jutsu(fight, path, "jt4name", "jt4damage") == 84)
        return (84);
    return (0);
}

int init_npc_fight(fight_t *fight, char *path)
{
    if (get_string_from_file(path, "name", &fight->npc->name) == sfFalse) {
        write_error("Error: can't get npc name\n");
        return (84);
    }
    if (get_int_from_file(path, "type", &fight->npc->type) == sfFalse) {
        write_error("Error: can't get npc type\n");
        return (84);
    }
    if (get_texture_from_file(path, "tx1", &fight->npc->tx[0]) == sfFalse) {
        write_error("Error: can't get npc texture 1\n");
        return (84);
    }
    if (get_texture_from_file(path, "tx2", &fight->npc->tx[1]) == sfFalse) {
        write_error("Error: can't get npc texture 2\n");
        return (84);
    }
    if (get_texture_from_file(path, "tx3", &fight->npc->tx[2]) == sfFalse) {
        write_error("Error: can't get npc texture 3\n");
        return (84);
    }
}

int init_fight_npc(fight_t *fight, npc_t *npc)
{
    char *path = my_strdup(npc->path);
    fight->npc = malloc(sizeof(f_npc_t));
    fight->npc->life = 100;
    init_npc_fight(fight, path);
    if (get_texture_from_file(path, "tx4", &fight->npc->tx[3]) == sfFalse) {
        write_error("Error: can't get npc texture 4\n");
        return (84);
    }
    for (int i = 0; i < 4; i++) {
        fight->npc->sp[i] = sfSprite_create();
        sfSprite_setTexture(fight->npc->sp[i], fight->npc->tx[i], sfTrue);
        sfSprite_setPosition(fight->npc->sp[i], (sfVector2f){1700, 625});
        sfSprite_setScale(fight->npc->sp[i], (sfVector2f){2, 2});
    }
    if (init_npc_jutsu(fight, path) == 84) {
        write_error("Error: can't init npc jutsu\n");
        return (84);
    }
    return (0);
}

void set_text_fight(fight_t *fight, sfFont *font)
{
    sfText_setString(fight->texts->jutsu, "Your turn: choose a jutsu");
    sfText_setString(fight->texts->npc_life, my_int_to_str(fight->npc->life));
    sfText_setString(fight->texts->npc_name, fight->npc->name);
    sfText_setString(fight->texts->player_life,
    my_int_to_str(fight->player->life));
    sfText_setString(fight->texts->player_name, fight->player->name);
    sfText_setFont(fight->texts->jutsu, font);
    sfText_setFont(fight->texts->npc_life, font);
    sfText_setFont(fight->texts->npc_name, font);
    sfText_setFont(fight->texts->player_life, font);
    sfText_setFont(fight->texts->player_name, font);
    sfText_setPosition(fight->texts->jutsu, (sfVector2f){400, 950});
    sfText_setPosition(fight->texts->npc_life, (sfVector2f){1100, 50});
    sfText_setPosition(fight->texts->npc_name, (sfVector2f){1400, 50});
    sfText_setPosition(fight->texts->player_life, (sfVector2f){760, 50});
    sfText_setPosition(fight->texts->player_name, (sfVector2f){400, 50});
    sfText_setColor(fight->texts->npc_name, sfWhite);
    sfText_setColor(fight->texts->player_life, sfWhite);
    sfText_setColor(fight->texts->player_name, sfWhite);
    sfText_setColor(fight->texts->npc_life, sfWhite);
}
