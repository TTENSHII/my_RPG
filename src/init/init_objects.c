/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_objects
*/

#include "rpg.h"

static const char PC[] = "confs/objects/pc.ini";
static const char PAPER[] = "confs/objects/paper.ini";
static const char MOUSE[] = "confs/objects/mouse.ini";
static const char KEYBOARD[] = "confs/objects/keyboard.ini";
static const char CHARGER[] = "confs/objects/charger.ini";
static const char WRENCH[] = "confs/objects/hub/piece_one.ini";
static const char SCREWDRIVER[] = "confs/objects/hub/piece_two.ini";
static const char ROBOT1[] = "confs/objects/hub/three_piece.ini";
static const char ROBOT2[] = "confs/objects/hub/four_piece.ini";
static const char ROBOT3[] = "confs/objects/hub/five_piece.ini";
static const char ROBOT[] = "assets/hub/final_robot.png";

static int init_object(const char *path, objects_t **object)
{
    double scale = 0;
    objects_t *new = malloc(sizeof(objects_t));
    new->next = NULL;
    get_int_from_file(path, "id", &new->id);
    get_string_from_file(path, "name", &new->name);
    get_pos_from_file(path, "pos", &new->pos);
    if (get_texture_from_file(path, "texture", &new->tx) == sfFalse)
        return (84);
    new->sp = sfSprite_create();
    new->is_on = false;
    sfSprite_setTexture(new->sp, new->tx, sfTrue);
    get_double_from_file(path, "scale", &scale);
    sfSprite_setScale(new->sp, (sfVector2f) {scale, scale});
    sfSprite_setPosition(new->sp, new->pos);
    new->next = (*object);
    (*object) = new;
    return (0);
}

static int init_object_hub(const char *path, hub_t **hub)
{
    double scale = 0;
    hub_t *new = malloc(sizeof(hub_t));
    get_int_from_file(path, "id", &new->id);
    get_string_from_file(path, "name", &new->name);
    get_pos_from_file(path, "pos", &new->pos);
    if (get_texture_from_file(path, "texture", &new->tx) == sfFalse)
        return (84);
    new->sp = sfSprite_create();
    new->is_on = false;
    sfSprite_setTexture(new->sp, new->tx, sfTrue);
    get_double_from_file(path, "scale", &scale);
    sfSprite_setScale(new->sp, (sfVector2f) {scale, scale});
    sfSprite_setPosition(new->sp, new->pos);
    new->circle = sfCircleShape_create();
    sfCircleShape_setFillColor(new->circle, sfColor_fromRGBA(191, 191, 191, 150.5));
    sfCircleShape_setRadius(new->circle, 5);
    sfCircleShape_scale(new->circle, (sfVector2f) {5, 5});
    sfCircleShape_setPosition(new->circle, new->pos);
    new->next = (*hub);
    (*hub) = new;
    return 0;
}

static int init_robot(global_t *global)
{
    global->texture->robot = sfTexture_createFromFile(ROBOT, NULL);
    global->sprite->robot = sfSprite_create();
    if (global->texture->robot == NULL || global->sprite->robot == NULL)
        return (84);
    sfSprite_setTexture(global->sprite->robot, global->texture->robot, sfTrue);
    sfSprite_setPosition(global->sprite->robot, (sfVector2f) {350, 4293});
    return 0;
}


int init_objects(global_t *global)
{
    global->objects = NULL;
    global->hub = NULL;
    global->global_value->hub_index[0] = 0;
    global->global_value->hub_index[1] = 0;

    if (init_object(PC, &global->objects) == 84 ||
    init_object_hub(WRENCH, &global->hub) == 84 ||
    init_object_hub(SCREWDRIVER, &global->hub) == 84 ||
    init_object_hub(ROBOT1, &global->hub) == 84 ||
    init_object_hub(ROBOT2, &global->hub) == 84 ||
    init_object_hub(ROBOT3, &global->hub) == 84 ||
    init_robot(global) == 84)
        return (84);
    return (0);
}
