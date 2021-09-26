##
## EPITECH PROJECT, 2019
## CPE_lemin_2019
## File description:
## Makefile
##

CC	=	cc
INCLUDE	=	-I./include
LIBS	=
CFLAGS	=	-Wall -Wextra -pipe -g	\
			$(INCLUDE) $(LIBS)
LDFLAGS	=	$(LIBS)

MINILIB_SRC	=	minilib/my_atoi.c		\
				minilib/my_itoa.c		\
				minilib/my_printf.c		\
				minilib/my_putbase.c	\
				minilib/my_putchar.c	\
				minilib/my_putnbr.c		\
				minilib/my_putptr.c		\
				minilib/my_putstr.c		\
				minilib/my_revstr.c		\
				minilib/my_splitstr.c	\
				minilib/my_strcat.c		\
				minilib/my_strcmp.c		\
				minilib/my_strcpy.c		\
				minilib/my_strdup.c		\
				minilib/my_strlen.c		\
				minilib/my_strstr.c		\
				minilib/paths.c

SRC	=	src/main.c						\
		src/rooms/connect.c				\
		src/rooms/create.c				\
		src/rooms/destroy.c				\
		src/rooms/parser.c				\
		src/rooms/get_room.c			\
		src/rooms/error.c				\
		src/algo/path_finding_algo.c	\
		src/algo/room_indexer.c			\
		src/rooms/ants.c				\
		src/algo/ant_path.c				\
		src/algo/choose_from_entrance.c	\
		src/algo/choose_best_path.c		\
		src/algo/move_ant.c				\
		src/rooms/input.c				\
		src/rooms/get_next_line.c

MINILIB_OBJ	=	$(MINILIB_SRC:.c=.o)
OBJ	=	$(SRC:.c=.o)

BINARY_NAME	=	lem_in

all:	$(MINILIB_OBJ)	$(OBJ)
	$(CC) -o $(BINARY_NAME) $(MINILIB_OBJ) $(OBJ)

clean:
	@rm -f vgcore.* *.gcno *.gcda

fclean:	clean
	@rm -f $(OBJ) $(MINILIB_OBJ) $(BINARY_NAME)

re:	fclean	all
