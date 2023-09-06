##
## Makefile for tekGUI in /home/baris-f/rendu/gfx/gfx_tekgui
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Wed Feb  3 21:21:18 2016 Florent Baris
## Last update Wed Jan  4 13:55:42 2017 baris_f
##

NAME	:=	menger

SRC	:=	menger.c	\
		main.c

OBJ     = $(SRC:.c=.o)

CC      = /usr/bin/gcc -g

CFLAGS	= -Wall -Wextra -Werror -std=gnu99

RM      = rm -f
ECHO    = echo -e

all     : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean   :
	$(RM) $(OBJ)


fclean  : clean
	$(RM) $(NAME)

re      : fclean all

.PHONY  : all clean fclean re
