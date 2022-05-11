/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "rpg.h"

typedef struct global_value_s {
    int volume;
    int fps;
    int math_answer[4];
    int units[5];
    int npc_id;
    int volume_id[4];
    int object_id[5];
    int hub_index[2];
    int is_on;
    int index_new;
    int opti_flag;
    int start_game;
    int display_notice;
} global_value_t;

typedef struct interact_with_npc_s {
    int npc_id;
    sfSprite *sp;
} interact_with_npc_t;

typedef struct music_s {
    sfMusic *music;
    sfSound *sound_click;
    sfSoundBuffer *sound_buffer_click;
    sfSound *sound_fart;
    sfSoundBuffer *sound_buffer_fart;
} music_t;

typedef struct rect_s {
    sfIntRect menu_back;
    sfIntRect button[4];
} rect_t;

typedef struct shape_s {
    sfCircleShape *circle_item_hub[4];
    sfCircleShape *circle_item_inventory[5];
} shape_t;

typedef struct sprite_s {
    sfSprite *math_game[1];
    sfSprite *math_button[21];
    sfSprite *menu_back;
    sfSprite *button[5];
    sfSprite *bubbule;
    sfSprite *help_back;
    sfSprite *settings_back[13];
    sfSprite *fps;
    sfSprite *interface;
    sfSprite *npc_interfaces;
    sfSprite *student_card;
    sfSprite *inventory;
    sfSprite *robot;
    sfSprite *floor_particule;
    sfSprite *button_pause[2];
    sfSprite *interface_game[3];
    sfSprite *new_game[5];
    sfSprite *notice;
} sprite_t;

typedef struct texture_s {
    sfTexture *interface_game[3];
    sfTexture *npc_interfaces;
    sfTexture *math_game[1];
    sfTexture *fps;
    sfTexture *math_button[21];
    sfTexture *help_back;
    sfTexture *texture_back_settings[13];
    sfTexture *texture_back_menu;
    sfTexture *button[5][3];
    sfTexture *map[2];
    sfTexture *bubbule;
    sfTexture *interface;
    sfTexture *robot;
    sfTexture *new_game[5];
    sfTexture *notice;
} texture_t;

typedef struct skills_s {
    int units[5];
} skills_t;

typedef struct map_s {
    sfVector2f pos;
    sfSprite *sp;
    int num;
    struct map_s *next;
} map_t;

typedef struct npc_s {
    int id;
    char *path;
    sfVector2f pos;
    sfTexture *tx;
    sfSprite *sp;
    sfText *txt_name;
    char *name;
    struct npc_s *next;
} npc_t;

typedef struct objects_s {
    int id;
    int is_on;
    char *name;
    sfVector2f pos;
    sfTexture *tx;
    sfSprite *sp;
    struct objects_s *next;
} objects_t;

typedef struct inventory_s {
    int id;
    char *name;
    sfVector2f pos;
    sfSprite *sp;
    struct inventory_s *next;
} inventory_t;

typedef struct my_clock_t {
    sfClock *clock;
    sfTime time;
    float second;
} my_clock_t;

typedef struct player_s {
    sfVector2f pos;
    sfTexture *tx[4];
    sfSprite *sp[4];
    inventory_t *inventory;
    char *name;
    int direction;
    sfIntRect rect;
    sfVector2f velocity;
    my_clock_t clock;
    skills_t skills;
    int is_walking;
    int take_pc;
    int is_farting;
} player_t;

typedef struct texts_s {
    sfFont *font;
    sfFont *font2;
    sfText *sfText_volume;
    sfText *sfText_win_math;
    sfText *sfText_math_game[15];
    sfText *sfText_skills[5];
    sfText *sfText_skills_info[5];
    sfText *text_name;
    sfText *txt_fps;
    sfText *txt_nb_fps;
    sfText *text_new;
    char *str;
} texts_t;

typedef struct sokoban_s {
    map_t *map;
    char **map_char;
    player_t player;
    my_clock_t clock;
    sfTexture *tx[5];
    sfSprite *sp;
    int win;
} sokoban_t;

typedef struct bubbule_text_s {
    sfText *sftext;
    sfText *sftext2;
    int index_text;
    int is_valid;
    int value;
    float sec;
    char *text;
    sfTime time;
    sfClock *clock;
} bubbule_text_t;

typedef struct main_s {
    sfRenderWindow *window;
    sfEvent event;
    sfView *view;
    sfView *wiew_mmap;
    sfView *interface;
} main_t;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                           FIGHT STRUCTS                                    //
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

typedef struct jutsu_s {
    int dammages;
    char *name;
    struct jutsu_s *next;
} jutsu_t;

typedef struct f_npc_s {
    int life;
    int type;
    char *jutsuname;
    int jutsudammage;
    jutsu_t *jutsu;
    sfTexture *tx[4];
    sfSprite *sp[4];
    char *name;
} f_npc_t;

typedef struct f_player_s {
    int life;
    int id_jutsu;
    char *jutsuname;
    int jutsudammage;
    sfTexture *tx[4];
    sfSprite *sp[4];
    char *name;
} f_player_t;

typedef struct fight_texts_s {
    sfText *player_life;
    sfText *npc_life;
    sfText *player_name;
    sfText *npc_name;
    sfText *jutsu;
    sfText *jutsu1;
    sfText *jutsu2;
    sfText *jutsu3;
    sfText *jutsu4;
} fight_texts_t;

typedef struct fight_s {
    int player_turn;
    int npc_turn;
    int is_animation;
    int player_attack;
    int npc_attack;
    int nb_sprites;
    f_npc_t *npc;
    sfRectangleShape *life_bg[2];
    sfRectangleShape *life_bar[2];
    sfTexture *template_button[4];
    sfSprite *rect_jutsu[4];
    f_player_t *player;
    sfTexture *tx_bg[2];
    sfSprite *sp_bg[2];
    my_clock_t clock;
    my_clock_t clock_anims;
    my_clock_t clock_npc;
    fight_texts_t *texts;
} fight_t;

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                FIGHT END                                   //
//                                                                            //  
////////////////////////////////////////////////////////////////////////////////

typedef struct fight_intro_s {
    int finished_animation;
    sfTexture *tx[4];
    sfSprite *sp[4];
    my_clock_t clock;
} fight_intro_t;

typedef struct hunter_s {
    sfTexture *texture[5];
    sfSprite *sprite[5];
    int loose;
    int value[2];
    sfText *sfText_score;
    my_clock_t clock;
} hunter_t;

typedef struct hub_s {
    int id;
    int is_on;
    char *name;
    sfVector2f pos;
    sfTexture *tx;
    sfSprite *sp;
    sfCircleShape *circle;
    struct hub_s *next;
} hub_t;

typedef struct inventory_hub_s {
    int id;
    char *name;
    sfVector2f pos;
    sfSprite *sp;
    int is_on;
    struct inventory_hub_s *next;
} inventory_hub_t;

typedef struct particule_s {
    my_clock_t clock;
    int dir;
} particule_t;

/////////DEBUT DES PARTICULES DE TENSHI////////

typedef struct framebuffer_s {
    int width;
    int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct pixel_s {
    sfColor color;
    int x;
    int y;
} pixel_t;

typedef struct raindrop_s {
    pixel_t *pixel;
    float speed;
    struct raindrop_s *next;
} raindrop_t;

typedef struct particles_s {
    my_clock_t clock;
    framebuffer_t *framebuffer;
    raindrop_t *raindrop;
    sfTexture *tx;
    sfSprite *sp;
    int particule_nb;
} particles_t;

typedef struct fart_s {
    framebuffer_t *buff_fart;
    my_clock_t clock;
    sfTexture *tx_fart;
    sfSprite *sp_fart;
    my_clock_t fart_time;
} fart_t;

typedef struct save_s {
    char *path;
    char *save_name;
    struct save_s *next;
    struct save_s *prev;
} save_t;

typedef struct load_save_s {
    sfTexture *tx_bg;
    sfTexture *tx_button;
    sfTexture *tx_left[2];
    sfTexture *tx_right[2];
    sfTexture *txplay;
    sfSprite *sp_bg;
    sfSprite *sp_button;
    sfSprite *sp_left[2];
    sfSprite *sp_right[2];
    sfSprite *sp_play;
    sfText *txt_save;
    save_t *save;
} load_save_t;

typedef struct end_game_s {
    sfTexture *tx_bg;
    sfSprite *sp_bg;
    sfTexture *tx_button_exit;
    sfSprite *sp_button_exit;
    sfTexture *tx_button_menu;
    sfSprite *sp_button_menu;
} end_game_t;

typedef struct global_s {
    int scene;
    particule_t *particule;
    shape_t *shape;
    main_t *main;
    sprite_t *sprite;
    texture_t *texture;
    map_t *map;
    objects_t *objects;
    npc_t *npc;
    bubbule_text_t *bubbule_text;
    global_value_t *global_value;
    texts_t *texts;
    player_t *player;
    music_t *music;
    my_clock_t clock;
    sokoban_t *sokoban;
    fight_intro_t *fight_intro;
    inventory_t *inventory;
    fight_t *fight;
    hunter_t *hunter;
    hub_t *hub;
    inventory_hub_t *inventory_hub;
    particles_t *particles;
    load_save_t *load_save;
    end_game_t *end_game;
    fart_t *fart;
} global_t;

#endif
