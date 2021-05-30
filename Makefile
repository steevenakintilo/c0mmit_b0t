#
## EPITECH PROJECT, 2020
## Makefile addition
## File description:
## Makefile addition
##

SRC	=	main.c	\

NAME	=	c0mmit_b0t

CPPFLAGS = -I include/ -g3

FLAGS = -Wall -Wextra

OBJ = $(SRC:.c=.o)

CFLAGS =

all:     $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(FLAGS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
