# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 02:03:16 by moel-asr          #+#    #+#              #
#    Updated: 2023/06/09 18:23:48 by moel-asr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = main.c \
	./parsing/check_errors.c \
	./parsing/check_path_and_map.c \
	./get_next_line/get_next_line.c \
	./rey_casting/utils.c

OBJ_DIR = files_objects

OBJ= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

CC = cc

# CFLAGS=  -Wall -Wextra -Werror

MLX= -lmlx -framework OpenGL -framework AppKit

DIB= -fsanitize=address -g3

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
