# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 02:03:16 by moel-asr          #+#    #+#              #
#    Updated: 2023/06/09 15:25:50 by kmahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = main.c\
	./rey_casting/get_next_line/get_next_line.c\
	./rey_casting/get_next_line/get_next_line_utils.c\
	./rey_casting/main_rey.c\
	./rey_casting/utils.c\

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
	@$(CC) ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(OBJ) $(DIB) -o $(NAME)

clean:
	$(RM) $(OBJ)
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) -rf $(OBJ_DIR)

re: fclean all
