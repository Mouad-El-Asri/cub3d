# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 02:03:16 by moel-asr          #+#    #+#              #
#    Updated: 2023/06/15 17:54:24 by moel-asr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = main.c \
	./get_next_line/get_next_line.c \
	./parser/parse_colors.c \
	./parser/parse_map.c \
	./parser/parse_path_and_map.c \
	./parser/parse_texture_utils.c \
	./parser/parse_texture.c \
	./parser/parser_utils.c \
	./rey_casting/utils.c

OBJ_DIR = files_objects

OBJ= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

CC = cc

# CFLAGS=  -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

# DIB= -fsanitize=address -g3

$(RM) = rm -f 

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C minilibft
	$(CC) $(CFLAGS) minilibft/minilibft.a $(MLX) $(OBJ) $(DIB) -o $(NAME)

clean:
	$(RM) $(OBJ)
	@$(RM) -rf $(OBJ_DIR)
	make clean -C minilibft

fclean: clean
	$(RM) $(NAME)
	$(RM) -rf $(OBJ_DIR)
	make fclean -C minilibft

re: fclean all
