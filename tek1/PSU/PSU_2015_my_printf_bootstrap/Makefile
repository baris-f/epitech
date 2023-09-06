##
## Makefile for Makefile in /home/baris_f/rendu/PSU_2015_my_printf_bootstrap
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Thu Nov  5 09:24:07 2015 Florent Baris
## Last update Thu Nov  5 10:37:00 2015 Florent Baris
##

NAME	= a.out

SRCDIR	= src

SRC	=	test.c\
		my_strlen.c\
		my_put_nbr.c\
		my_putchar.c\
		my_putstr.c
LIB	= -lmy -L./
INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	ar rc libmy.a *.o
	ranlib libmy.a

clean	:
	$(RM) $(OBJ)


fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re



