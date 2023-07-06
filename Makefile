# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 02:03:16 by moel-asr          #+#    #+#              #
#    Updated: 2023/07/06 07:18:39 by kmahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

SRC = main.c\
	./mandatory/main_rey.c\
	./mandatory/wall_casting.c\
	./mandatory/move_directions.c\
	./get_next_line/get_next_line.c \
	./parser/parse_colors.c \
	./parser/parse_map.c \
	./parser/parse_path_and_map.c \
	./parser/parse_texture_utils.c \
	./parser/parser_utils.c \
	./parser/parse_texture.c \
	./utils.c\
	./vertical_rays.c\
	./horizontal_rays.c\
	./init.c\
	./textures.c\
	./wall_textures/init_textures_imgs.c\
	./rey_casting.c\

BONUS_SRS = ./bonus/mini_map_bonus.c\
			./parser/parse_colors.c \
			./parser/parse_map.c \
			./parser/parse_path_and_map.c \
			./parser/parse_texture_utils.c \
			./parser/parser_utils.c \
			./parser/parse_texture.c \
			./bonus/main_bonus.c\
			./bonus/collision_bonus.c\
			./bonus/draw_bonus.c\
			./bonus/player_movement_bonus.c\
			./bonus/wall_casting_bonus.c\
			./get_next_line/get_next_line.c \
			./utils.c\
			./vertical_rays.c\
			./horizontal_rays.c\
			./init.c\
			./wall_textures/init_textures_imgs.c\
			./textures.c\
			./rey_casting.c\


OBJ_DIR = files_objects
OBJ_DIR_BONUS = files_objects_bonus


OBJ= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

OBJ_BONUS= $(patsubst %.c,$(OBJ_DIR_BONUS)/%.o,$(BONUS_SRS))


CC = cc

# CFLAGS=  -Wall -Wextra -Werror 

MLX= -lmlx -framework OpenGL -framework AppKit

DIB= -fsanitize=address -g3

$(RM) = rm -f 
  
all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C minilibft
	$(CC) $(CFLAGS) minilibft/minilibft.a $(MLX) $(OBJ) $(DIB) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C minilibft
	$(CC) $(CFLAGS) minilibft/minilibft.a $(MLX) $(OBJ_BONUS) $(DIB) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(OBJ_DIR_BONUS)
	make clean -C minilibft

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(OBJ_DIR_BONUS)
	make fclean -C minilibft

re: fclean  all bonus

