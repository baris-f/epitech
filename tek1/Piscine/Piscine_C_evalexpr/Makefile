##
## Makefile for Makefile in /home/thirio_b/rendu/Piscine_C_infinadd
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Mon Oct 19 11:15:52 2015 Gaspard Thirion
## Last update Tue Oct 20 15:49:13 2015 Gaspard Thirion
##

NAME	= evalexpr

SRC	= number.c \
	gest.c

LIB	= -L lib/ -lmy

INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= gcc -g

RM	= rm -f

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(INC) -o $(NAME) $(OBJ) $(LIB)

clean	:
	$(RM) $(OBJ)


fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
