##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## initializes cat
##

SRC	=	csfml.c	\
		drawfunc.c	\
		windowmanager.c	\
		animfuncs.c	\
		gameloopmanage.c	\
		ennemyfuncs.c	\
		csfml2.c	\
		free.c	\
		textfuncs.c	\
		drawfunc2.c	\
		getscore.c	\
		makehigh.c	\
		windowmanager2.c

OBJ	=	$(SRC:.c=.o)

COPIES	=	*~

COPIES2	=	#*#

NAME	=	my_hunter

MAKE	=	make

LIB	=	lib/my/libmy.a

CFLAGS	=	-g -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	princ clean

princ:	$(OBJ)
	cd lib/my/ && $(MAKE)
	rm -f '*.o'
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -lm lib/my/libmy.a

clean:
	rm -f $(OBJ)
	rm -f $(COPIES)
	rm -f $(COPIES2)

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB)

re:     fclean all clean
