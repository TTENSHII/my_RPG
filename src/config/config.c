/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** config
*/

#include "rpg.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void ini_game_clock(my_clock_t *clock)
{
    clock->clock = sfClock_create();
    clock->second = 0;
}

static void ini_interface(global_t *global)
{
    global->sprite->interface = sfSprite_create();
    global->texture->interface =\
    sfTexture_createFromFile("assets/interface/interface.png", NULL);
    global->sprite->npc_interfaces = sfSprite_create();
    global->texture->npc_interfaces =\
    sfTexture_createFromFile("assets/interface/talk_npc.png", NULL);
    if (!global->texture->interface)
        return;
    sfSprite_setTexture(global->sprite->interface, global->texture->interface,
    sfTrue);
    sfSprite_setTexture(global->sprite->npc_interfaces,
    global->texture->npc_interfaces, sfTrue);
    sfSprite_setPosition(global->sprite->interface,
    (sfVector2f) {0, -70});
    sfSprite_setPosition(global->sprite->npc_interfaces,
    (sfVector2f) {1370, 310});
}

static int add_save(save_t **saves, char *name)
{
    char *path = malloc(sizeof(char) * (my_strlen(name) + 15));

    path = my_strcpy(path, "./confs/saves/");
    path = my_strcat(path, name);
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return (84);
    save_t *new = malloc(sizeof(save_t));
    new->path = my_strdup(path);
    new->save_name = my_strdup(name);
    new->next = NULL;
    new->prev = NULL;
    if (new->path == NULL || new->save_name == NULL)
        return (84);
    if ((*saves) == NULL) {
        new->next = new;
        new->prev = new;
        (*saves) = new;
        close(fd);
        return (0);
    }
    (*saves)->prev->next = new;
    new->prev = (*saves)->prev;
    new->next = (*saves);
    (*saves)->prev = new;
    close(fd);
    return (0);
}

static int config_save_list(load_save_t *load)
{
    int nb = 0;
    struct dirent *files;

    DIR *folder = opendir("./confs/saves/");
    if (folder == NULL)
        return (84);
    while ((files = readdir(folder)) != NULL) {
        if (files->d_name[0] == '.' || files->d_type != 8)
            continue;
        if (add_save(&load->save, files->d_name) == 0)
            nb++;
    }
    closedir(folder);
    if (nb == 0)
        return (84);
    return (0);
}

int init_save(load_save_t *load, sfFont *font)
{
    if (!font) return (84);
    load->tx_bg = sfTexture_createFromFile("assets/save/menuload.png", NULL);
    load->tx_button = sfTexture_createFromFile("assets/save/button.png", NULL);
    load->tx_left[0] = sfTexture_createFromFile("assets/save/left1.png", NULL);
    load->tx_left[1] = sfTexture_createFromFile("assets/save/left2.png", NULL);
    load->tx_right[0] = sfTexture_createFromFile("assets/save/right1.png", NULL);
    load->tx_right[1] = sfTexture_createFromFile("assets/save/right2.png", NULL);
    load->txplay = sfTexture_createFromFile("assets/save/play.png", NULL);
    if (!load->tx_bg || !load->tx_button || !load->tx_left[0] ||
    !load->tx_left[1] || !load->tx_right[0] || !load->tx_right[1] || !load->txplay)
        return (84);
    load->sp_bg = sfSprite_create();
    load->sp_button = sfSprite_create();
    load->sp_left[0] = sfSprite_create();
    load->sp_left[1] = sfSprite_create();
    load->sp_right[0] = sfSprite_create();
    load->sp_right[1] = sfSprite_create();
    load->sp_play = sfSprite_create();
    load->txt_save = sfText_create();
    load->save = NULL;
    sfSprite_setTexture(load->sp_play, load->txplay, sfTrue);
    sfSprite_setTexture(load->sp_bg, load->tx_bg, sfTrue);
    sfSprite_setTexture(load->sp_button, load->tx_button, sfTrue);
    sfSprite_setTexture(load->sp_left[0], load->tx_left[0], sfTrue);
    sfSprite_setTexture(load->sp_left[1], load->tx_left[1], sfTrue);
    sfSprite_setTexture(load->sp_right[0], load->tx_right[0], sfTrue);
    sfSprite_setTexture(load->sp_right[1], load->tx_right[1], sfTrue);
    sfSprite_setPosition(load->sp_button, (sfVector2f) {495, 498});
    sfSprite_setPosition(load->sp_left[0], (sfVector2f) {385, 497});
    sfSprite_setPosition(load->sp_left[1], (sfVector2f) {385, 497});
    sfSprite_setPosition(load->sp_right[0], (sfVector2f) {1453, 497});
    sfSprite_setPosition(load->sp_right[1], (sfVector2f) {1453, 497});
    sfSprite_setPosition(load->sp_play, (sfVector2f) {750, 650});
    sfSprite_setScale(load->sp_left[1], (sfVector2f) {0.7, 0.7});
    sfSprite_setScale(load->sp_left[0], (sfVector2f) {0.7, 0.7});
    sfSprite_setScale(load->sp_right[1], (sfVector2f) {0.7, 0.7});
    sfSprite_setScale(load->sp_right[0], (sfVector2f) {0.7, 0.7});
    sfText_setFont(load->txt_save, font);
    sfText_setCharacterSize(load->txt_save, 50);
    sfText_setColor(load->txt_save, sfWhite);
    sfText_setPosition(load->txt_save, (sfVector2f) {900, 520});
    sfText_setString(load->txt_save, "Save");
    if (config_save_list(load) == 84) {
        write_error("Error: can't open save files\n");
        return (84);
    }
    return (0);
}

int start_config(global_t *global)
{
    if (init_value_one(global) == 84)
        return (84);
    if (init_value_two(global) == 84)
        return (84);
    if (init_save(global->load_save, global->texts->font2) == 84 || init_new_scene(global) == 84)
        return (84);
    if (init_map(global) == 84)
        return (84);
    start_particles(global->particles);
    if (check_math_texture(global) == 84)
        return (84);
    if (init_endgame(global) == 84)
        return (84);
    if (init_all_menu(global) == 84)
        return (84);
    if (init_info(global) == 84)
        return (84);
    if (init_pedago_npc(global) == 84)
        return (84);
    if (init_dev_npc(global) == 84)
        return (84);
    if (init_tek_npc(global) == 84)
        return (84);
    if (init_aer_npc(global) == 84)
        return (84);
    if (init_all_skills(global) == 84)
        return (84);
    if (init_hunter(global) == 84 || init_win_particule(global) == 84 ||
    init_craft_robot(global) == 84)
        return (84);
    init_fart(global);
    ini_game_clock(&global->clock);
    init_all_text(global);
    ini_interface(global);
    init_shape_circle(global);
    global->inventory_hub = NULL;
    return (0);
}
