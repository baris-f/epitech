##
## Makefile for Makefile in /home/baris_f/rendu/Piscine_C_J10/do-op
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Fri Oct  9 10:55:07 2015 Florent Baris
## Last update Fri Oct  9 17:44:19 2015 Florent Baris
##

NAME	= do-op

SRC	= $(shell echo *.c)

OBJ	= $(SRC:.c=.o)

LIB	= -L ../lib/ -lmy

RM	= rm -f

all	: $(NAME)

clean	:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) \#*#

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) $(LIB) 

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
