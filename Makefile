##
## EPITECH PROJECT, 2021
## Makefile ls
## File description:
## makefile
##

SRC 	=	src/event.c	\
			src/myloop.c	\
			src/enemies/enemy_chained.c	\
			src/enemies/gest_enemy.c	\
			src/clock.c	\
			src/my_strncmp.c	\
			src/menu/basemenu.c	\
			src/menu/ducks.c	\
			src/pause/pause.c	\
			src/pause/pausebuttons.c	\
			src/lose/lose.c	\
			src/lose/lives.c	\
			src/main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -Wshadow -Wpedantic -g

DFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

CPPFLAGS = -I./include

NAME = my_defender

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(DFLAGS)

$(LIBMY):
	make -C lib/my

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)

re: fclean all
