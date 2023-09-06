##
## Makefile for Makefile in /home/baris_f/rendu/Piscine_C_infinadd/lib/my
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Mon Oct 19 10:55:56 2015 Florent Baris
## Last update Mon Oct 19 15:25:07 2015 Florent Baris
##

NAME	= infin_add

SRC	= infin_add.c
LIB	= -L lib/my/ -lmy
INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc

RM	= rm -f

CFLAGS = -g -W -Wall -Wextra -Werror -ansi -pedantic

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(INC) -o $(NAME) $(OBJ) $(LIB)


clean	:
	$(RM) $(OBJ)


fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re

