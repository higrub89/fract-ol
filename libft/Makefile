NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
REMOVE = rm -f
AR = ar
ARFLAGS = -rcs
NAME_BONUS= .bonus

SRC = ft_isalpha.c \
      ft_isdigit.c \
      ft_isalnum.c \
      ft_isascii.c \
      ft_isprint.c \
      ft_strlen.c  \
      ft_memset.c  \
      ft_memmove.c  \
      ft_bzero.c   \
      ft_memcpy.c  \
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_strchr.c  \
      ft_strrchr.c \
      ft_strncmp.c \
      ft_memchr.c  \
      ft_memcmp.c  \
      ft_strnstr.c \
      ft_atoi.c    \
      ft_calloc.c  \
      ft_strdup.c  \
      ft_substr.c  \
      ft_strjoin.c \
      ft_strtrim.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c  \
      ft_putendl_fd.c \
      ft_putnbr_fd.c  \
      ft_itoa.c       \
      ft_split.c      \
      ft_strmapi.c    \
      ft_striteri.c   

BONUS =	ft_lstnew_bonus.c       \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c      \
	ft_lstlast_bonus.c      \
	ft_lstadd_back_bonus.c  \
	ft_lstdelone_bonus.c    \
	ft_lstclear_bonus.c     \
	ft_lstiter_bonus.c      \
	ft_lstmap_bonus.c       

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)
	@touch $(NAME_BONUS)

bonus : $(NAME) $(NAME_BONUS)

all : $(NAME)

clean :
	$(REMOVE) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(REMOVE) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re
