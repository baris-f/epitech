##
## Makefile for Makefile in /home/tandra_a/rendu/Dansloriginal
## 
## Made by Tandrayen Anil
## Login   <tandra_a@epitech.net>
## 
## Started on  Sat Oct 24 15:36:36 2015 Tandrayen Anil
## Last update Sat Oct 24 19:34:08 2015 Tandrayen Anil
##

SRC	:=	main.c \
		my_aff_colle3.c \
		my_aff_colle2.c \
		my_aff_colle1.c 

NAME	:=	colle3

OBJ	:=	$(SRC:.c=.o)

LDFLAGS	:=	-L ./lib/ -lmy

CFLAGS	:=	-I ./include/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
