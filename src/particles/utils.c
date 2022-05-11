/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** utils
*/

#include "rpg.h"

enum PIXEL {
    RED = 0,
    GREEN = 1,
    BLUE = 2,
    ALPHA = 3
};

framebuffer_t *create_framebuffer(int x, int y)
{
    int i = 0;
    unsigned int size = x * y * 4;
    framebuffer_t *framebuffer;
    sfUint8 *pixels;

    pixels = malloc(sizeof(sfUint8) * size);
    framebuffer = malloc(sizeof(framebuffer_t));
    framebuffer->width = x;
    framebuffer->height = y;
    framebuffer->pixels = pixels;
    for (i = 0; i < size; i += 4) {
        framebuffer->pixels[RED] = 0;
        framebuffer->pixels[GREEN] = 0;
        framebuffer->pixels[BLUE] = 0;
        framebuffer->pixels[ALPHA] = 255;
    }
    return (framebuffer);
}

sfColor color_from_rgba(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a)
{
    sfColor color = {r, g, b, a};
    return (color);
}

void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color)
{
    if (x < 0 || x >= framebuffer->width || y < 0 || y >= framebuffer->height)
        return;
    x *= 4;
    y *= 4;
    framebuffer->pixels[framebuffer->width * y + x] = color.r;
    framebuffer->pixels[framebuffer->width * y + x + 1] = color.g;
    framebuffer->pixels[framebuffer->width * y + x + 2] = color.b;
    framebuffer->pixels[framebuffer->width * y + x + 3] = color.a;
}

void clear_buffer(framebuffer_t *framebuffer)
{
    unsigned int i;
    unsigned int size = framebuffer->width * framebuffer->height * 4;

    for (i = 0; i < size; i += 4) {
        framebuffer->pixels[i + RED] = 0;
        framebuffer->pixels[i + GREEN] = 0;
        framebuffer->pixels[i + BLUE] = 0;
        framebuffer->pixels[i + ALPHA] = 0;
    }
}
