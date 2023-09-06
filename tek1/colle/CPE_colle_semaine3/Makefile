##
## Makefile for 2048 in /home/baris-f/rendu/colle/CPE_colle_semaine3
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Fri May 13 14:26:14 2016 Florent Baris
## Last update Fri May 13 16:38:24 2016 Florent Baris
##

NAME	:=	512

SRC	:=	game.c	\
		main.c	\
		draw.c	\
		check.c	\
		set.c

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc

CC	:=	gcc -g
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-W -Wall -Wextra -Werror -ansi -pedantic
CFLAGS	+=	-I$(INCD) -I${HOME}/.froot/include

LIB	:=	-llapin
LIB	+=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
LIB	+=	-L${HOME}/.froot/lib

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.c
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB)

clean:
		@$(RM) $(OBJD)/*.o
		@$(RM) *~
		@$(RM) \#*
		@$(RM) vgcore.*
		@$(RM) $(SRCD)/*~
		@$(RM) $(SRCD)/\#*

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all demo clean fclean re
