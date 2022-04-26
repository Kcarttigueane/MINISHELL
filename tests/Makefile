##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

CC			=	gcc --coverage -g3 -I ../include
CFLAGS		=	-W -Wall -Werror

RM			= 	rm -f

TARGET		=	unit-tests

SRC			=	$(wildcard *.c)		\
				$(wildcard ../lib/*.c)		\


OBJ			= 	$(SRC:.c=.o)

CFLAGS		= 	-W -Wall -Wextra -g3

all			:	$(TARGET)
			./$(TARGET)

$(TARGET)	:	$(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lcriterion

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(TARGET)
			$(RM) $(wildcard *.gcno)
			$(RM) $(wildcard *.gcda)

re			:	fclean all