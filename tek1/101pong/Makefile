##
## Makefile for make in /home/fus/rendu/101pong
## 
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
## 
## Started on  Fri Nov 27 00:00:39 2015 Gaspard Thirion
## Last update Fri Nov 27 00:00:41 2015 Gaspard Thirion
##

NAME	= 101pong

CC	= /usr/bin/gcc

CFLAGS	= -W -Wall -Wextra -ansi -pedantic

RM	= rm -f

all	: $(NAME)

$(NAME)	:
	gcc -c main.c -o main.o
	gcc main.o -o $(NAME) -lm

clean	:
	-@$(RM) main.o
	-@$(RM) *~
	-@$(RM) \#*#


fclean	: clean
	-@$(RM) $(NAME)

re	: fclean all

my	: fclean all clean

.PHONY	: all clean fclean re my

debug	: $(OBJ)
	@$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJ) $(LIB)
