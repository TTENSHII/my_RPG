/*
** EPITECH PROJECT, 2022
** parser
** File description:
** parse_csfml
*/

#include "rpg.h"

sfBool get_texture_from_file(const char *path, char *name, sfTexture **texture)
{
    int i = 0;
    (*texture) = NULL;
    char *str = get_file_info(path, name);
    if (str == NULL) return (false);
    while (str[i] != '\0') {
        if (str[i] == '=')
            break;
        i += 1;
    }
    if (str[i] == '\0' || str[i] != '=' || str[i + 1] == '\0') {
        free(str);
        return (false);
    }
    char *my_path = my_strdup(&str[i + 1]);
    (*texture) = sfTexture_createFromFile(my_path, NULL);
    free(str);
    free(my_path);
    if (*texture == NULL)
        return (false);
    return (true);
}

sfBool get_font_from_file(const char *path, char *name, sfFont **font)
{
    int i = 0;
    (*font) = NULL;
    char *str = get_file_info(path, name);
    if (str == NULL) return (false);
    for (; str[i] != '\0'; i += 1)
        if (str[i] == '=')
            break;
    if (str[i] != '=' || str[i + 1] == '\0') {
        free(str);
        return (false);
    }
    char *my_path = my_strdup(&str[i + 1]);
    (*font) = sfFont_createFromFile(my_path);
    if (*font == NULL)
        return (false);
    free(str);
    free(my_path);
    return (true);
}

sfBool get_sound_from_file(const char *path, char *name, sfSound **sound)
{
    int i = 0;
    (*sound) = NULL;
    sfSoundBuffer *sb = NULL;
    char *str = get_file_info(path, name);
    if (str == NULL) return (false);
    for (; str[i] != '\0'; i += 1)
        if (str[i] == '=')
            break;
    if (str[i] != '=' || str[i + 1] == '\0') {
        free(str);
        return (false);
    }
    char *my_path = my_strdup(&str[i + 1]);
    sb = sfSoundBuffer_createFromFile(my_path);
    (*sound) = sfSound_create();
    sfSound_setBuffer((*sound), sb);
    if (*sound == NULL)
        return (false);
    free(str);
    free(my_path);
    return (true);
}

sfBool get_music_from_file(const char *path, char *name, sfMusic **music)
{
    int i = 0;
    (*music) = NULL;
    char *str = get_file_info(path, name);
    if (str == NULL) return (false);
    for (; str[i] != '\0'; i += 1)
        if (str[i] == '=')
            break;
    if (str[i] != '=' || str[i + 1] == '\0') {
        free(str);
        return (false);
    }
    char *my_path = my_strdup(&str[i + 1]);
    (*music) = sfMusic_createFromFile(my_path);
    if (*music == NULL)
        return (false);
    free(str);
    free(my_path);
    return (true);
}
