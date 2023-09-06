##
## Makefile for tekGUI in /home/baris-f/rendu/gfx/gfx_tekgui
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Wed Feb  3 21:21:18 2016 Florent Baris
## Last update Mon Jan  9 09:53:46 2017 baris_f
##

NAME	:=	my_convert_temp

SRC	:=	my_convert_temp.cpp

OBJ     = $(SRC:.cpp=.o)

CC      = g++

CFLAGS	= -Wall -Wextra -Werror

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
