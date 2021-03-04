##
## EPITECH PROJECT, 2020
## Makefile du main
## File description:
## le make lance tout le projet
##

SRC	=	hunter.c	\
		handle_textures.c	\
		draw.c	\
		assets.c	\
		main.c				\
		restart.c	\

OBJ	=	$(SRC)

NAME	=	my_hunter

all:		$(NAME)

$(NAME):
		make -C lib/my
		gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window -l csfml-network

clean:
		make -C lib/my clean

fclean:
		make -C lib/my fclean
		rm $(NAME)
		clear

re:		fclean all
