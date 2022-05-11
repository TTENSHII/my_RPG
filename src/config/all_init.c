/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** all_init
*/

#include "rpg.h"

static int init_bubbule_value(global_t *global)
{
    global->bubbule_text->index_text = 0;
    global->bubbule_text->is_valid = 1;
    global->bubbule_text->sec = 0;
    global->bubbule_text->value = OFF;
    global->bubbule_text->text = my_strdup(" ");
}

static void init_view(global_t *global)
{
    global->main->view = sfView_create();
    global->main->wiew_mmap = sfView_create();
    global->main->interface = sfView_create();
    sfView_setCenter(global->main->view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfView_setSize(global->main->view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(global->main->window, global->main->view);
    sfView_setCenter(global->main->interface,
    (sfVector2f) {1920 / 2, 1080 / 2});
    sfView_setSize(global->main->interface, (sfVector2f) {1920, 1080});
    sfView_setCenter(global->main->view,
    (sfVector2f) {1920 / 2, 1080 / 2});
    sfView_setSize(global->main->view, (sfVector2f) {1920, 1080});
    sfView_setViewport(global->main->wiew_mmap,
    (sfFloatRect) {0.90, 0.01, 0.35, 0.40});
    sfRenderWindow_setView(global->main->window, global->main->view);
}

static int ini_random(void)
{
    unsigned int seed = 0;
    FILE *file = NULL;

    file = fopen("/dev/random", "r");
    if (file == NULL)
        file = fopen("/dev/urandom", "r");
    if (file == NULL) {
        write(2, "Error with /dev/random and /dev/urandom\n", 40);
        return (84);
    }
    fread(&seed, sizeof(seed), 1, file);
    srand(seed);
    fclose(file);
    return (0);
}

static int put_logo_and_loading(global_t *global)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
    sfTexture_createFromFile("assets/interface/loading.png", NULL);
    sfImage *logo = sfImage_createFromFile("assets/interface/logo.png");
    if (!texture || !sprite || !logo) {
        write_error("Error | check your files\n");
        return (84);
    }
    sfRenderWindow_setIcon(global->main->window, 280, 280, sfImage_getPixelsPtr(logo));
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(global->main->window, sprite, NULL);
    sfRenderWindow_display(global->main->window);
    return (0);
}

int init_value_one(global_t *global)
{
    global->inventory = NULL;
    global->global_value->start_game = 0;
    if (ini_random() == 84)
        return (84);
    global->main->window =
    create_render_window(1920, 1080, 32, "EPITECH RPG");
    if (global->main->window == NULL)
        return (84);
    if (put_logo_and_loading(global) == 84)
        return (84);
    sfRenderWindow_setPosition(global->main->window, (sfVector2i) {0, 0});
    if (global->main->window == NULL)
        return (84);
    init_view(global);
    init_bubbule_value(global);
    if (init_bubbule(global) == 84 || init_objects(global) == 84)
        return (84);
    return (0);
}
