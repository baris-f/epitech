##
## Makefile for Makefile in /home/baris_f/rendu/PSU_2015_my_printf_bootstrap
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Thu Nov  5 09:24:07 2015 Florent Baris
## Last update Sun Dec 20 08:50:43 2015 Florent Baris
##

NAME	= bsq

SRC	= my_bsq_bootstrap.c\
	getnextline.c\
	main.c

LIB	= -L ./ -lmy
INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc -g

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean	:
	$(RM) $(OBJ)


fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re



