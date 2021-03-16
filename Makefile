##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile infin_add
##

NAME	=	102architect

SRC	=	main.c	\

all:	$(NAME)

$(NAME):
	make -C ./lib/my
	gcc -o $(NAME) -g $(SRC) -L./lib/my -lmymath -lm

clean:
	make clean -C ./lib/my
	rm -f *~
	rm -f *.c#

fclean:	clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:	fclean all
	make -C ./lib/my
