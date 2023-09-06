##
## Makefile for tekGUI in /home/baris-f/rendu/gfx/gfx_tekgui
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Wed Feb  3 21:21:18 2016 Florent Baris
## Last update Mon Jan  9 14:27:36 2017 baris_f
##

NAME	:=	my_cat

SRC	:=	my_cat.cpp

OBJ     = $(SRC:.cpp=.o)

CC      = g++

CFLAGS	= -Wall -Wextra -Werror -std=c++03

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
