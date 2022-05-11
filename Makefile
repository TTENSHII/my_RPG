##
## EPITECH PROJECT, 2021
## lib [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

SRC = src/rpg.c \
		src/parsers/parse_char.c \
		src/parsers/parse_csfml.c \
		src/parsers/parse_numbers.c \
		src/event/event_listener.c \
		src/event/event_game.c \
		src/event/event_pause.c \
		src/config/malloc_structs.c\
		src/event/math/event_math.c \
		src/event/event_menu.c \
		src/event/event_settings_click.c \
		src/sokoban/event_sokoban.c \
		src/event/event_keyboard_text.c \
		src/event/sound_effect.c\
		src/event/math/event_buttons2.c \
		src/event/math/event_buttons3.c \
		src/event/pause/event_info.c \
		src/init/init_menu.c \
		src/config/config.c \
		src/display/bubbule_text.c \
		src/display/display_game.c \
		src/sokoban/display_sokoban.c \
		src/display/display_menu.c \
		src/display/display_listener.c \
		src/display/display_pause.c \
		src/display/math/display_math_game.c\
		src/display/pause/display_info.c\
		src/display/render_window.c \
		src/init/init_settings_value.c\
		src/init/init_scene_settings.c\
		src/init/init_map.c\
		src/init/pause/init_pause.c\
		src/init/init_all_menu.c\
		src/init/init_bubble.c \
		src/init/init_sound.c\
		src/init/init_volume.c\
		src/start/intro_fight.c\
		src/start/sokoban.c\
		src/end/end_fight_intro.c\
		src/end/sokoban.c\
		src/start/fight.c\
		src/utils/file_to_buffer.c\
		src/init/get_map_infos.c\
		src/init/init_npc.c\
		src/init/init_texts.c\
		src/init/init_skills.c\
		src/init/pause/init_text_skills.c\
		src/init/init_player.c\
		src/init/math/init_math_game.c\
		src/init/math/init_text.c\
		src/init/math/init_answer2.c\
		src/init/math/init_answer3.c\
		src/init/math/init_buttons.c\
		src/update/update.c\
		src/update/player.c\
		src/update/update_listener.c\
		src/update/pause.c\
		src/update/menu.c\
		src/update/math/update_math.c\
		src/sokoban/update_sokoban.c\
		src/sokoban/reset_sokoban.c\
		src/sokoban/colisions.c\
		src/update/fight/update_fight.c\
		src/update/fight/update_fight_intro.c\
		src/event/fight/intro_fight.c\
		src/display/fight/fight_intro.c\
		src/init/init_objects.c\
		src/init/init_help.c\
		src/update/pause/update_info.c\
		src/update/pause/collision_object.c\
		src/hunter/hunter_init.c\
		src/hunter/hunter_update.c\
		src/hunter/hunter_display.c\
		src/hunter/hunter_event.c\
		src/update/pause/collision_hub.c\
		src/display/dispay_entity.c\
		src/update/fight/player.c\
		src/update/fight/npc.c\
		src/init/init_win_particule.c\
		src/update/update_pixels.c\
		src/end/end_fight.c\
		src/particles/start.c\
		src/particles/update_rain.c\
		src/particles/utils.c\
		src/particles/display_rain.c\
		src/config/all_init.c\
		src/config/config_game.c\
		src/init/init_circle_shape.c\
		src/saves/save.c\
		src/update/save/load.c\
		src/utils/fart.c\
		src/update/save/new.c\
		src/event/save/load.c\
		src/event/save/new.c\
		src/display/save/load.c\
		src/display/save/new.c\
		src/init/init_interface_but.c\
		src/update/fight/annim_fight.c\
		src/start/sokoban1.c\
		src/start/fight_init.c\
		src/init/pause/init_skills2.c\
		src/init/init_new_scene.c\
		src/event/end_game.c\
		src/display/end_game.c\
		src/update/end_game.c\
		src/display/display_help.c\
		src/update/update_help.c\
		src/event/event_help.c

NAME = my_rpg

CFLAGS = -Iinclude

CSFML_FLAG = -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

OBJ = $(SRC:.c=.o)

all: $(NAME)

exec: re
		./$(NAME)

$(NAME): $(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) -Llib/my -lmy $(CSFML_FLAG)

clean:
		rm -f $(OBJ)
		@make clean -C lib/my

fclean: clean
		rm -f $(NAME)
		@make fclean -C lib/my

re: fclean all

.PHONY: all
