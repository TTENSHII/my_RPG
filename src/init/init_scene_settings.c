/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** init_scene_settings
*/

#include "rpg.h"

int init_back_exit(global_t *global)
{
    global->sprite->settings_back[BACK] = sfSprite_create();
    global->sprite->settings_back[EXIT_SETTINGS] = sfSprite_create();
    global->texture->texture_back_settings[BACK] =
    sfTexture_createFromFile(SETTINGS_BACK, NULL);
    global->texture->texture_back_settings[EXIT_SETTINGS] =
    sfTexture_createFromFile(BUTTON_E_MENU, NULL);
    if (!global->texture->texture_back_settings[BACK] ||
    !global->texture->texture_back_settings[EXIT_SETTINGS])
        return 84;
    sfSprite_setTexture(global->sprite->settings_back[BACK],
    global->texture->texture_back_settings[BACK], sfTrue);
    sfSprite_setTexture(global->sprite->settings_back[EXIT_SETTINGS],
    global->texture->texture_back_settings[EXIT_SETTINGS], sfTrue);
    sfSprite_setPosition(global->sprite->settings_back[EXIT_SETTINGS],
    (sfVector2f) {1300, 700});
    return 0;
}

int init_button_volume(global_t *global)
{
    global->sprite->settings_back[VOLUME_LOW] = sfSprite_create();
    global->texture->texture_back_settings[VOLUME_LOW] =
    sfTexture_createFromFile(SETTINGS_VOLUME_LOW, NULL);
    global->sprite->settings_back[VOLUME_UP] = sfSprite_create();
    global->texture->texture_back_settings[VOLUME_UP] =
    sfTexture_createFromFile(SETTINGS_VOLUME_UP, NULL);
    if (!global->texture->texture_back_settings[VOLUME_LOW] ||
    !global->texture->texture_back_settings[VOLUME_UP])
        return 84;
    sfSprite_setTexture(global->sprite->settings_back[VOLUME_LOW],
    global->texture->texture_back_settings[VOLUME_LOW], sfFalse);
    sfSprite_setTexture(global->sprite->settings_back[VOLUME_UP],
    global->texture->texture_back_settings[VOLUME_UP], sfFalse);
    sfSprite_setPosition(global->sprite->settings_back[VOLUME_LOW],
    (sfVector2f) {1200, 450});
    sfSprite_setPosition(global->sprite->settings_back[VOLUME_UP],
    (sfVector2f) {1400, 450});
    return 0;
}

int init_buttons_30_on_off(global_t *global)
{
    global->sprite->settings_back[FPS_30_OFF] = sfSprite_create();
    global->sprite->settings_back[FPS_30_ON] = sfSprite_create();
    global->texture->texture_back_settings[FPS_30_OFF] =
    sfTexture_createFromFile(SETTINGS_FPS_30_OFF, NULL);
    global->texture->texture_back_settings[FPS_30_ON] =
    sfTexture_createFromFile(SETTINGS_FPS_30_ON, NULL);
    if (!global->texture->texture_back_settings[FPS_30_OFF] ||
    !global->texture->texture_back_settings[FPS_30_ON])
        return 84;
    sfSprite_setTexture(global->sprite->settings_back[FPS_30_OFF],
    global->texture->texture_back_settings[FPS_30_OFF], sfFalse);
    sfSprite_setTexture(global->sprite->settings_back[FPS_30_ON],
    global->texture->texture_back_settings[FPS_30_ON], sfFalse);
    sfSprite_setPosition(global->sprite->settings_back[FPS_30_ON],
    (sfVector2f) {580, 320});
    sfSprite_setPosition(global->sprite->settings_back[FPS_30_OFF],
    (sfVector2f) {580, 320});
    return 0;
}

int init_buttons_144_on_off(global_t *global)
{
    global->sprite->settings_back[FPS_144_ON] = sfSprite_create();
    global->sprite->settings_back[FPS_144_OFF] = sfSprite_create();
    global->texture->texture_back_settings[FPS_144_ON] =
    sfTexture_createFromFile(SETTINGS_FPS_144_ON, NULL);
    global->texture->texture_back_settings[FPS_144_OFF] =
    sfTexture_createFromFile(SETTINGS_FPS_144_OFF, NULL);
    if (!global->texture->texture_back_settings[FPS_144_ON] ||
    !global->texture->texture_back_settings[FPS_144_OFF])
        return 84;
    sfSprite_setTexture(global->sprite->settings_back[FPS_144_ON],
    global->texture->texture_back_settings[FPS_144_ON], sfFalse);
    sfSprite_setTexture(global->sprite->settings_back[FPS_144_OFF],
    global->texture->texture_back_settings[FPS_144_OFF], sfFalse);
    sfSprite_setPosition(global->sprite->settings_back[FPS_144_ON],
    (sfVector2f) {580, 520});
    sfSprite_setPosition(global->sprite->settings_back[FPS_144_OFF],
    (sfVector2f) {580, 520});
    return 0;
}

int init_buttons_60_on_off(global_t *global)
{
    global->sprite->settings_back[FPS_60_ON] = sfSprite_create();
    global->sprite->settings_back[FPS_60_OFF] = sfSprite_create();
    global->texture->texture_back_settings[FPS_60_ON] =
    sfTexture_createFromFile(SETTINGS_FPS_60_ON, NULL);
    global->texture->texture_back_settings[FPS_60_OFF] =
    sfTexture_createFromFile(SETTINGS_FPS_60_OFF, NULL);
    if (!global->texture->texture_back_settings[FPS_60_ON] ||
    !global->texture->texture_back_settings[FPS_60_OFF])
        return 84;
    sfSprite_setTexture(global->sprite->settings_back[FPS_60_ON],
    global->texture->texture_back_settings[FPS_60_ON], sfFalse);
    sfSprite_setTexture(global->sprite->settings_back[FPS_60_OFF],
    global->texture->texture_back_settings[FPS_60_OFF], sfFalse);
    sfSprite_setPosition(global->sprite->settings_back[FPS_60_ON],
    (sfVector2f) {580, 420});
    sfSprite_setPosition(global->sprite->settings_back[FPS_60_OFF],
    (sfVector2f) {580, 420});
    return 0;
}