# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 02:03:16 by moel-asr          #+#    #+#              #
#    Updated: 2023/07/09 22:15:09 by moel-asr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

RM = rm

CC = cc

CFLAGS =  -Wall -Wextra -Werror -fsanitize=address -g3

MLX = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c\
	./mandatory/main_rey.c\
	./wall_casting.c\
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

BONUS_SRCS = ./bonus/mini_map_bonus.c\
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
			./wall_casting.c\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C minilibft
	$(CC) $(CFLAGS) minilibft/minilibft.a $(MLX) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C minilibft
	$(CC) $(CFLAGS) minilibft/minilibft.a $(MLX) $(OBJS_BONUS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	$(RM) -f $(OBJS) $(OBJS_BONUS)
	make clean -C minilibft

fclean: clean
	$(RM) -f $(NAME) $(NAME_BONUS)
	make fclean -C minilibft

re: fclean all bonus

.PHONY: clean fclean bonus