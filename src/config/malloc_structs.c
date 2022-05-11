/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** malloc_structs
*/

#include "rpg.h"

static void malloc_my_structs(global_t *global)
{
    global->fight_intro = malloc(sizeof(fight_intro_t));
    global->sokoban = malloc(sizeof(sokoban_t));
    global->music = malloc(sizeof(music_t));
    global->main = malloc(sizeof(main_t));
    global->sprite = malloc(sizeof(sprite_t));
    global->texture = malloc(sizeof(texture_t));
    global->player = malloc(sizeof(player_t));
    global->texts = malloc(sizeof(texts_t));
    global->global_value = malloc(sizeof(global_value_t));
    global->bubbule_text = malloc(sizeof(bubbule_text_t));
    global->fight = malloc(sizeof(fight_t));
    global->hunter = malloc(sizeof(hunter_t));
    global->particule = malloc(sizeof(particule_t));
    global->particles = malloc(sizeof(particles_t));
    global->shape = malloc(sizeof(shape_t));
    global->load_save = malloc(sizeof(load_save_t));
    global->end_game = malloc(sizeof(load_save_t));
    global->fart = malloc(sizeof(fart_t));
}

int malloc_structs(global_t *global)
{
    malloc_my_structs(global);
    if (global->fight_intro == NULL || global->sokoban == NULL ||
    global->music == NULL || global->main == NULL ||
    global->sprite == NULL || global->texture == NULL ||
    global->player == NULL || global->texts == NULL ||
    global->global_value == NULL || global->bubbule_text == NULL
    || global->fight == NULL || global->particles == NULL
    || global->load_save == NULL || global->end_game == NULL
    || global->fart == NULL) {
        write_error("Error: malloc_structs\n");
        return (84);
    }
    return (0);
}
