##
## EPITECH PROJECT, 2018
## malloc
## File description:
## Makefile for malloc
##

NAME	=	libmy_malloc.so

CC	=	gcc

CFLAGS	+=	-fPIC -W -Wall -Wextra -I./include -fno-builtin

SRC	=	src/malloc.c		\
		src/free.c		\
		src/realloc.c		\
		src/my_file.c		\
		src/my_strlen.c		\
		src/realign_size.c	\
		src/show_alloc_mem.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC)  -shared -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
