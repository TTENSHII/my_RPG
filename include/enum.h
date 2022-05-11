/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-stephane.corbiere
** File description:
** enum
*/

#ifndef ENUM_H_
    #define ENUM_H_

enum math_game_t {
    MATH_BACKGROUND,
    MATH_VALIDATE,
    MATH_UNVALIDATE,
    MATH_CONTINUE
};

enum math_game_s {
    MATH_BUTTON1A_OFF,
    MATH_BUTTON1B_OFF,
    MATH_BUTTON1C_OFF,
    MATH_BUTTON2A_OFF,
    MATH_BUTTON2B_OFF,
    MATH_BUTTON2C_OFF,
    MATH_BUTTON3A_OFF,
    MATH_BUTTON3B_OFF,
    MATH_BUTTON3C_OFF,
    MATH_BUTTON1A,
    MATH_BUTTON1B,
    MATH_BUTTON1C,
    MATH_BUTTON2A,
    MATH_BUTTON2B,
    MATH_BUTTON2C,
    MATH_BUTTON3A,
    MATH_BUTTON3B,
    MATH_BUTTON3C,
    MATH_ContinueS
};

enum math_text {
    MATH_TEXT1,
    MATH_TEXT2,
    MATH_TEXT3,
    MATH_HEADER,
    MATH_ANSWER1A,
    MATH_ANSWER2A,
    MATH_ANSWER3A,
    MATH_ANSWER1B,
    MATH_ANSWER2B,
    MATH_ANSWER3B,
    MATH_ANSWER1C,
    MATH_ANSWER2C,
    MATH_ANSWER3C
};

enum npc_name {
    NICOLAS = 1,
    CLEMENT,
    JEROME,
    LILY,
    YANNICK
};

enum settings_buttons {
    BACK,
    VOLUME_LOW,
    VOLUME_UP,
    EXIT_SETTINGS,
    FPS_30_ON,
    FPS_30_OFF,
    FPS_60_ON,
    FPS_60_OFF,
    FPS_144_ON,
    FPS_144_OFF,
    VOLUME_STRING,
    VOLUME_LOW_S,
    VOLUME_UP_S
};

enum menu_boutton {
    NEW,
    LOAD,
    EXIT,
    SETTING,
    HELP
};

enum scene {
    MENU,
    GAME,
    PAUSE,
    SOKOBAN,
    MATH,
    INFO,
    FIGHT_INTRO,
    FIGHT,
    HUNTER,
    LOAD_SAVE,
    NEW_SAVE,
    ENDGAME,
    DISPLAY_HELP
};

enum player {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum units {
    PSU,
    CREDITS,
    MAT,
    MUL,
    HUB
};

enum event_value {
    OFF,
    START_COMPUTE,
    LYLY_TALK
};

#endif
