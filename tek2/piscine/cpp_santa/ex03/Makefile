##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Sat Jan 14 16:22:29 2017 baris_f
##

NAME	:=	box

SRC	:=	main.cpp	\
		Box.cpp		\
		GiftPaper.cpp	\
		Object.cpp	\
		Wrap.cpp	\
		Toy.cpp		\
		Teddy.cpp

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc

CC	:=	g++ -g
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-I$(INCD) -Wall -Wextra -Werror

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.cpp, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.cpp
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ)

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
