/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_npc
*/

#include "rpg.h"

void add_my_npc(npc_t *new, npc_t **npc)
{
    sfText_setPosition(new->txt_name,\
    (sfVector2f) {new->pos.x - 10, new->pos.y - 30});
    new->next = (*npc);
    (*npc) = new;
}

static char *my_strdup_const(const char *str)
{
    int i = 0;
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (i = 0; str[i] != '\0'; i += 1)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

static int init_pnj(const char *path, npc_t **npc, sfFont *font)
{
    double scale = 0;
    npc_t *new = malloc(sizeof(npc_t));
    get_string_from_file(path, "name", &new->name);
    get_int_from_file(path, "id", &new->id);
    get_pos_from_file(path, "pos", &new->pos);
    get_double_from_file(path, "scale", &scale);
    if (get_texture_from_file(path, "texture", &new->tx) == sfFalse)
        return (1);
    new->sp = sfSprite_create();
    new->txt_name = sfText_create();
    sfText_setFont(new->txt_name, font);
    sfText_setString(new->txt_name, new->name);
    sfText_setScale(new->txt_name, (sfVector2f) {0.7, 0.7});
    sfText_setFillColor(new->txt_name, sfWhite);
    sfText_setOutlineColor(new->txt_name, sfBlack);
    sfText_setOutlineThickness(new->txt_name, 0.9);
    sfSprite_setTexture(new->sp, new->tx, sfTrue);
    sfSprite_setScale(new->sp, (sfVector2f) {scale, scale});
    sfSprite_setPosition(new->sp, new->pos);
    new->path = my_strdup_const(path);
    add_my_npc(new, npc);
}

int init_pedago_npc(global_t *global)
{
    global->npc = NULL;
    global->global_value->npc_id = 0;

    if (init_pnj(SAVE_NICOLAS, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_CLEMENT, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_LILLY, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_JEROME, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_YANNICK, &global->npc, global->texts->font2) == 84)
        return (84);
    return (0);
}

int init_tek_npc(global_t *global)
{
    if (init_pnj(SAVE_TENSHI, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_ANTONIN, &global->npc, global->texts->font2) == 84)
        return (84);
    return (0);
}

int init_aer_npc(global_t *global)
{
    global->global_value->npc_id = 0;

    if (init_pnj(SAVE_REMI, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_MARCO, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_MAYLIS, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_NATHAN, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_JOHAN, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_THOMAS, &global->npc, global->texts->font2) == 84)
        return (84);
    return (0);
}

int init_dev_npc(global_t *global)
{
    global->global_value->npc_id = 0;

    if (init_pnj(SAVE_GWENDO, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_MANEVA, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_MARIE, &global->npc, global->texts->font2) == 84)
        return (84);
    if (init_pnj(SAVE_ADRIEN, &global->npc, global->texts->font2) == 84)
        return (84);
    return (0);
}
