##
## Makefile for Makefile in /home/cridli_p/rendu/colles/CPE_colle_semaine3
## 
## Made by Paul Cridlig
## Login   <cridli_p@epitech.net>
## 
## Started on  Wed May 11 15:00:33 2016 Paul Cridlig
## Last update Tue May 17 16:54:20 2016 Florent Baris
##


NAME=		colle2

CC=		gcc -W -Wall 

RM=		rm -f *~

SRC=		main.c \
		fonction.c

OBJ=		$(SRC:.c=.o)

INC=		-I ./include

LIB=		-L/home/${USER}/.froot/lib/ -llapin \
		-L/usr/local/lib \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-lm


$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(INC)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
