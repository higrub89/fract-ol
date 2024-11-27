# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 20:24:19 by rhiguita          #+#    #+#              #
#    Updated: 2024/11/27 22:18:25 by rhiguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc 
CFLAGS = -Wall -Werror -Wextra -g
HEADER = fractol.h
MINILIBX = minilibx-linux/libmlx.a
LFLAGS = -Lminilibx-linux -lmlx_Linux -Imlx_linux -lX11 -lXext -lm -lz 
SRC = events.c init.c math.c render.c utils.c main.c
OBJ = $(SRC:.c=.o)
RM = rm -rf
GREEN = \033[1;32m
%.o: %.c
	@echo "$(GREEN)Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) $(Makefile)
		@echo "$(GREEN)Compiling MINILIBX ..."
		make -C minilibx-linux
		@echo "$(GREEN)Compiling $(NAME)..."
		$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(MINILIBX) -o $(NAME) -lX11 -lXext -lm 
		@echo "$(GREEN)Project successfully compiled"

$(MINILIBX):
		 minilibx-linux && make

clean:
		@echo "$(GREEN) Cleaning Files objets..."
		$(RM) $(OBJ)
		@echo "$(GREEN)All object files are deleted"

fclean: clean
		@echo "$(GREEN) Removing $(NAME)..."
		$(RM) $(NAME)
		@echo "$(GREEN)Cleaned everything"

re: fclean all

.PHONY: all clean fclean re