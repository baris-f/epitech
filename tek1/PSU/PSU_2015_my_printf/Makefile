##
## Makefile for Makefile in /home/baris_f/rendu/PSU_2015_my_printf_bootstrap
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Thu Nov  5 09:24:07 2015 Florent Baris
## Last update Mon Nov 16 18:40:12 2015 Florent Baris
##

NAME	= libmy.a

SRCDIR	= src

SRC	=	my_printf.c\
		larg_S_o_p.c\
		my_char.c\
		my_strlen.c\
		my_put_nbr.c\
		my_putchar.c\
		my_putstr.c\
		my_putnbr_base.c\
		my_unsigned.c\
		my_int.c\
		my_hexa.c
LIB	= -lmy -L./
INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean	:
	$(RM) $(OBJ)


fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re



