##
## Makefile for Makefile in /home/baris_f/rendu/PSU_2015_my_printf_bootstrap
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Thu Nov  5 09:24:07 2015 Florent Baris
## Last update Tue Oct 10 11:21:30 2017 baris_f
##

NAME	= inc/libtekgui.a

SRCDIR	= src

SRC	=	load_bitmap.c   \
		key.c           \
		tekpixel.c      \
		tekblit.c       \
		tekfill.c       \
		font.c          \
		window.c        \
		button.c        \
		parser.c        \
		get.c   \
		get2.c  \
		main.c  \
		click.c \
		display.c

LIB	= -lmy -L./
INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc

 CFLAGS := -Wall -Wall -Wextra -ansi -pedantic

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



