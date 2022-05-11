/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** start
*/

#include "rpg.h"

void create_raindrow(raindrop_t **raindrop)
{
    raindrop_t *new = malloc(sizeof(raindrop_t));
    new->pixel = malloc(sizeof(pixel_t) * 200);
    new->speed = rand() % 200;
    new->speed += 400;
    int i = 0;
    sfVector2f pos = {rand() % (1920 - 100) + 50, rand() % (1080 - 100) + 50};
    float salut = pos.y;
    for (i = 0; i < 50; i++) {
        new->pixel[i].x = pos.x;
        new->pixel[i].y = pos.y;
        new->pixel[i].color = sfCyan;
        pos.y += 1;
    }
    pos.y = salut;
    for (i = 50; i < 100; i++) {
        new->pixel[i].x = pos.x + 1;
        new->pixel[i].y = pos.y;
        new->pixel[i].color = sfCyan;
        pos.y += 1;
    }
    pos.y = salut;
    for (i = 100; i < 150; i++) {
        new->pixel[i].x = pos.x + 2;
        new->pixel[i].y = pos.y;
        new->pixel[i].color = sfCyan;
        pos.y += 1;
    }
    pos.y = salut;
    for (i = 150; i < 200; i++) {
        new->pixel[i].x = pos.x + 3;
        new->pixel[i].y = pos.y;
        new->pixel[i].color = sfCyan;
        pos.y += 1;
    }
    new->next = *raindrop;
    *raindrop = new;
}

void start_particles(particles_t *particles)
{
    particles->particule_nb = 100;
    particles->clock.clock = sfClock_create();
    particles->clock.second = 0;
    particles->raindrop = NULL;
    particles->framebuffer = create_framebuffer(1920, 1080);
    particles->tx = sfTexture_create(1920, 1080);
    particles->sp = sfSprite_create();
    sfSprite_setTexture(particles->sp, particles->tx, sfTrue);
    for (int i = 0; i < particles->particule_nb; i++)
        create_raindrow(&particles->raindrop);

}
