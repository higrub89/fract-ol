# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 20:24:19 by rhiguita          #+#    #+#              #
#    Updated: 2024/10/20 13:56:52 by rhiguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc 
CFLAGS = -Wall -Werror -Wextra -g
HEADER = fractol.h
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmx.a
LFLAGS = -Lminilibx-linux -lmlx_Linux -Imlx_linux -lx11 -lXext -lm -lz 
SCR = *.c
OBJ = $(SRC:.c=.o)
RM = rm -rf
GREEN = \033[1;32m

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJ)
		make -C libft
		make -C minilibx-linux
		$(CC) $(CFLAGS) $(OBJ) $(LFlAGS) -o $(NAME)

		@echo "$(GREEN)Project successfully compiled"

$(OBJ): $(LIBFT)
		$(CC) $(CFLAGS) -C $(SRC)

$(LIBFT):
		make libft
$(MINILIBX):
		make minilibx-linux

clean :
		$(RM) $(OBJ)
		@echo "$(GREEN)All object files are deleted"

fclean : clean
		make fclean -C libft
		$(RM) $(NAME)
		@echo "$(GREEN)Cleaned everything"

re : fclean all

.PHONY : all clean fclean re
