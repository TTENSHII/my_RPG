/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "enum.h"
    #include "my.h"
    #include "struct.h"
    #include "const.h"

void init_fart(global_t *global);
void update_fart(global_t *global);
void display_fart(global_t *global);
int init_endgame(global_t *global);
void display_sprite_game(global_t *global);
void display_sprite_menu(global_t *global);
void display_sprite_pause(global_t *global);
void display_sprite_sokoban(global_t *global);
void display_sprite_math(global_t *global);
void display_sprite_info(global_t *global);
void display_fight_intro(global_t *global);
void display_fight(global_t *global);
void display_sprite_hunter(global_t *global);
void display_load_save_event(global_t *global);
void display_new_save_event(global_t *global);
void display_endgame(global_t *global);
void update_endgame(global_t *global);
void event_endgame(global_t *global);
void display_help(global_t *global);
int init_tek_npc(global_t *global);

typedef struct listener_s {
    void (*func)(global_t *);
    int scene;
} listener_t;

static const listener_t display_tab[] = {
    {.func = display_sprite_menu, .scene = MENU},
    {.func = display_sprite_game, .scene = GAME},
    {.func = display_sprite_pause, .scene = PAUSE},
    {.func = display_sprite_sokoban, .scene = SOKOBAN},
    {.func = display_sprite_math, .scene = MATH},
    {.func = display_sprite_info, .scene = INFO},
    {.func = display_fight_intro, .scene = FIGHT_INTRO},
    {.func = display_fight, .scene = FIGHT},
    {.func = display_sprite_hunter, .scene = HUNTER},
    {.func = display_load_save_event, .scene = LOAD_SAVE},
    {.func = display_new_save_event, .scene = NEW_SAVE},
    {.func = display_endgame, .scene = ENDGAME},
    {.func = display_help, .scene = DISPLAY_HELP}
};

int init_save(load_save_t *load, sfFont *font);
// PARTICLES
framebuffer_t *create_framebuffer(int x, int y);
sfColor color_from_rgba(sfUint8 red, sfUint8 green,
sfUint8 blue, sfUint8 alpha);
void pixel_to_buffer(framebuffer_t *buffer, int x,int y, sfColor color);
void clear_buffer(framebuffer_t *buffer);
void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);

void start_particles(particles_t *particles);
void update_rain(global_t *global);
void display_rain(global_t *global);

//FIGHT
void player_fight_update(global_t *global);
void npc_fight_update(global_t *global);
//END
void exit_fight_intro(global_t *global);
void exit_sokoban(global_t *global);
void end_fight(global_t *global);
void manage_new_save_event(global_t *global);
//RENDER_WINDOW
sfRenderWindow *create_render_window(int x, int y, int bpp, char *title);
//FIGHT
int start_fight_intro(global_t *global);
int start_fight(global_t *global, npc_t *npc);
//EVENT_LISTENER
void event_listner(global_t *global);
void manage_menu_event(global_t *global);
void manage_game_event(global_t *global);
void manage_pause_event(global_t *global);
void manage_event_fight(global_t *global);
void manage_sokoban_event(global_t *global);
int is_object_colision(global_t *global);
void manage_load_save_event(global_t *global);
//SETTINGS
void event_power(global_t *global);
int init_info(global_t *global);
void display_sprite_info(global_t *global);
void manage_info_event(global_t *global);
void update_info(global_t *global);
//DISPLAY
void display_bubble_text(global_t *global, char *text,
sfVector2f position, sfText *SfmlText);
void reset_text(global_t *global);
void display_fight_intro(global_t *global);
void display_fight(global_t *global);
void display_npc(npc_t *npc, sfRenderWindow *window);
void display_objects(objects_t *objects, sfRenderWindow *window);
void display_new_save_event(global_t *global);
void display_load_save_event(global_t *global);

int game_events(sfRenderWindow *win, global_t *global);

void display_listener(global_t *global);
void display_sprite_game(global_t *global);
void display_sprite_menu(global_t *global);
void display_sprite_pause(global_t *global);
void display_sprite_sokoban(global_t *global);

void display_load_save_event(global_t *global);
void display_load_save_event(global_t *global);
//INIT
int malloc_structs(global_t *global);
int init_text_volume(global_t *global);
int init_objects(global_t *global);
int init_button_n_menu(global_t *global);
int init_button_l_menu(global_t *global);
int init_button_e_menu(global_t *global);
int init_button_s_menu(global_t *global);
int init_volume_string(global_t *global);
int init_cpe_skill(global_t *global);
int init_button_h_menu(global_t *global);
int init_mul_skill(global_t *global);
int init_all_menu(global_t *global);
int init_all_settings(global_t *global);
int init_back_exit(global_t *global);
int init_psu_skill(global_t *global);
int init_button_volume(global_t *global);
int init_buttons_30_on_off(global_t *global);
int init_buttons_144_on_off(global_t *global);
int init_buttons_60_on_off(global_t *global);
int init_craft_robot(global_t *global);
int init_bubbule(global_t *global);
int init_value_one(global_t *global);
int init_help(global_t *global);
int init_files(global_t *global);
int init_shape_circle(global_t *global);
int init_map(global_t *global);
int get_info_map(int *nb_lines, int *line_size, char *file);
int init_pedago_npc(global_t *global);
int init_aer_npc(global_t *global);
int init_dev_npc(global_t *global);
int init_value_two(global_t *global);
int ini_texts(global_t *global);
int init_player(player_t *player, char *path);
int init_npc_fight(fight_t *fight, char *path);
int init_music_background(global_t *global);
int init_fight_npc(fight_t *fight, npc_t *npc);
void init_life_bar(fight_t *fight);
int init_sound(global_t *global);
int start_sokoban(global_t *global);
void update_sokoban(global_t *global);
int init_jutsu_texture(fight_t *fight);
void set_texture_fight_player(fight_t *fight);
int init_jutsu_button(fight_t *fight);
void update_clock(global_t *global);
int init_new_scene(global_t *global);
void ini_map(sokoban_t *sokoban);
int init_all_text(global_t *global);
void update_new_save(global_t *global);
void update_load_save(global_t *global);
//CONFIG
int start_config(global_t *global);
char *my_strndup(char *str, int n);
//PARSERS
sfBool get_int_from_file(const char *path, char *name, int *value);
sfBool get_double_from_file(const char *path, char *name, double *value);
sfBool get_pos_from_file(const char *path, char *name, sfVector2f *pos);
sfBool get_texture_from_file(const char *path, char *name,
sfTexture **texture);
sfBool get_font_from_file(const char *path, char *name, sfFont **font);
sfBool get_sound_from_file(const char *path, char *name, sfSound **sound);
sfBool get_music_from_file(const char *path, char *name, sfMusic **music);
sfBool get_string_from_file(const char *path, char *name, char **value);
char *get_file_info(const char *path, char *name);
char *my_int_to_str(int nb);
//UTILS
char *file_to_buffer(const char *path);
int init_all_skills(global_t *global);
int is_npc(global_t *global, int id, npc_t *tmp);
int number_size(int number);
void update_fight(global_t *global);
int save_game(global_t *global);
//UPDATE
int update_listener(global_t *global);
void update_game(global_t *global);
void update_player(global_t *global);
void player_talk_with_npc2(global_t *global);
void player_talk_with_npc3(global_t *global);
void update_pause(global_t *global);
void set_text_fight(fight_t *fight, sfFont *font);
void init_value_fight(global_t *global);
void update_fight_intro(global_t *global);
void update_menu(global_t *global);
void up_player(sokoban_t *sokoban, float seconds);
void reset_my_sokoban(sokoban_t *sokoban);
void add_node_start(sokoban_t *sokoban, int y, int x, char c);
int is_hub_colision_hub(global_t *global);
void add_node_end(sokoban_t *sokoban, int y, int x, char c);
void restart_clock_fight(global_t *global);
char **create_map_char(void);
void event_update_fight(global_t *global);
void anims_fight_update(global_t *global);
int update_pixel(global_t *global);
int init_win_particule(global_t *global);
//MATH
void display_sprite_math(global_t *global);
int check_math_texture(global_t *global);
int init_header_text(global_t *global);
int init_all_math_answer1(global_t *global);
int init_all_math_answer2(global_t *global);
int init_all_math_answer3(global_t *global);
int init_buttons_answer(global_t *global);
int init_buttons_math(global_t *global);
void manage_math_event(global_t *global);
void manage_math_event2(global_t *global);
void manage_math_event3(global_t *global);
void update_math(global_t *global);
void save_aer_game(global_t *global);
//HUNTER
int init_hunter(global_t *global);
void update_hunter(global_t *global);
void display_sprite_hunter(global_t *global);
void manage_hunter_event(global_t *global);
void event_help(global_t *global);

static const listener_t event_tab[] = {
    {.func = manage_menu_event, .scene = MENU},
    {.func = manage_game_event, .scene = GAME},
    {.func = manage_pause_event, .scene = PAUSE},
    {.func = manage_sokoban_event, .scene = SOKOBAN},
    {.func = manage_math_event, .scene = MATH},
    {.func = manage_info_event, .scene = INFO},
    {.func = manage_event_fight, .scene = FIGHT_INTRO},
    {.func = manage_event_fight, .scene = FIGHT},
    {.func = manage_hunter_event, .scene = HUNTER},
    {.func = manage_load_save_event, .scene = LOAD_SAVE},
    {.func = manage_new_save_event, .scene = NEW_SAVE},
    {.func = event_endgame, .scene = ENDGAME},
    {.func = event_help, .scene = DISPLAY_HELP}
};

void update_help(global_t *global);

static const listener_t update_tab[] = {
    {.func = update_menu, .scene = MENU},
    {.func = update_game, .scene = GAME},
    {.func = update_pause, .scene = PAUSE},
    {.func = update_sokoban, .scene = SOKOBAN},
    {.func = update_math, .scene = MATH},
    {.func = update_info, .scene = INFO},
    {.func = update_fight_intro, .scene = FIGHT_INTRO},
    {.func = update_fight, .scene = FIGHT},
    {.func = update_hunter, .scene = HUNTER},
    {.func = update_load_save, .scene = LOAD_SAVE},
    {.func = update_new_save, .scene = NEW_SAVE},
    {.func = update_endgame, .scene = ENDGAME},
    {.func = update_help, .scene = DISPLAY_HELP}
};

#endif
