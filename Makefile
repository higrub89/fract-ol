# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 20:24:19 by rhiguita          #+#    #+#              #
#    Updated: 2024/10/14 21:41:54 by rhiguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Werroe -Wextra -g
LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a
SRCS = *.c
OBJ = ${SRCS:%.c=%.o}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(MLX):
	$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME) -lXext -lX11 -lm

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	fclean all

.PHONY: all clean fclean re
