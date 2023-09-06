##
## Makefile for Makefile in /home/baris_f/rendu/PSU_2015_my_printf_bootstrap
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Thu Nov  5 09:24:07 2015 Florent Baris
## Last update Sun Feb 28 14:49:39 2016 Florent Baris
##

NAME	= generator

SRC	= generator.c	\
	fill.c		\
	writab.c

INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc -g

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean	:
	$(RM) $(OBJ)


fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re



