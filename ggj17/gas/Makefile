##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Sat Jan 21 11:57:10 2017 Gaspard Thirion
##

NAME	:=	app

SRC	:=	main.cpp	\
		Object.cpp	\
		Data.cpp	\
		Entity.cpp	\
		Unit.cpp

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	g++
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-I$(INCD) -Wall -Wextra -g
LIB	:=	-L$(LIBD) -lpthread -lsfml-graphics -lsfml-window -lsfml-system

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.cpp, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.cpp
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
		@$(RM) $(OBJD)/*.o
		@$(RM) *~
		@$(RM) \#*
		@$(RM) $(SRCD)/*~
		@$(RM) $(SRCD)/\#*

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
