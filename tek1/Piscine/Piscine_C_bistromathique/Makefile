##
## Makefile for Piscine_C_bistromathique in /home/linux/rendu/Piscine_C_bistromathique
## 
## Made by thirion gaspard
## Login   <thirio_b@epitech.net>
## 
## Started on  Tue Oct 27 23:44:06 2015 thirion gaspard
## Last update Sun Nov  1 22:07:12 2015 Gaspard Thirion
##

NAME	= calc

SRC	= evalexpr.c \
	number.c \
	./op/addinf.c \
	./op/multinf.c \
	./op/subinf.c \
	./op/common.c \
	./op/divinf.c \
	./op/divinf2.c \
	./op/modinf.c \
	main.c

LIB	= -L lib/my -lmy

INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= gcc -g

RM	= rm -f -r

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) -o $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

cclean:
	$(RM) *~
	$(RM) \#*

my:	all clean cclean

re:	fclean all

.PHONY:	all clean fclean cclean my re
