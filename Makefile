# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 20:24:19 by rhiguita          #+#    #+#              #
#    Updated: 2024/12/18 17:40:04 by rhiguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc 
CFLAGS = -Wall -Werror -Wextra -g
HEADER = ./include/fractol.h
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx.a
LFLAGS = -Lminilibx-linux -lmlx_Linux -Imlx_linux -lX11 -lXext -lm -lz 
SRC = 	
OBJ = $(SRC:.c=.o)
RM = rm -rf
GREEN = \033[1;32m

%.o: %.c
	@echo "$(GREEN)Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJ) $(Makefile)
		@echo "$(GREEN)Compiling MINILIBX ..."
		cp $(LIBFT) $(NAME)
		make -C minilibx-linux
		@echo "$(GREEN)Compiling $(NAME)..."
		$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(MINILIBX) $(LIBFT) -o $(NAME) -lX11 -lXext -lm 
		@echo "$(GREEN)Project successfully compiled"

$(MINILIBX):
		 minilibx-linux && make
		 
$(LIBFT):
	make bonus -C libft

all: libft $(NAME)

clean:
		@echo "$(GREEN) Cleaning Files objets..."
		$(RM) $(OBJ)
		make clean -C libft
		make clean -C minilibx-linux
		@echo "$(GREEN)All object files are deleted"

fclean: clean
		@echo "$(GREEN) Removing $(NAME)..."
		$(RM) $(NAME)
		@echo "$(GREEN) Removing LIBFT..."
		make clean -C libft
		@echo "$(GREEN) Removing MINILIBX-LINUX..."
		make clean -C minilibx-linux
		@echo "$(GREEN)Cleaned everything"

re: fclean all

.PHONY: all clean fclean re
