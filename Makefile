##
## EPITECH PROJECT, 2021
## Sans titre(Espace de travail)
## File description:
## Makefile
##

RM	= rm -f

NAME	= mysh

SRC	=	$(wildcard *.c)	\
		$(wildcard lib/*.c) \
		$(wildcard sources/*.c) \
		$(wildcard sources/linked_list/*.c) \
		$(wildcard sources/signal_handling/*.c) \
		$(wildcard sources/init_store_data_struct/*.c) \
		$(wildcard sources/command_execution/*.c) \

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -g3 -I include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(wildcard lib/*.gcno)
	$(RM) $(wildcard lib/*.gcda)
	make -C tests fclean
	rm -f vgcore.*

re:	fclean all

tests_run:
	make -C tests all