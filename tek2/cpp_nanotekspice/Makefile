##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Wed Feb 15 14:28:11 2017 fus
##

NAME	:=	nanotekspice

SRC	:=	main.cpp	\
		Parser.cpp	

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	g++
EXT	:=	cpp
RM	:=	rm -f
MKD	:=	mkdir -p

CFLAGS	:=	-I$(INCD) -Wall -Wextra -g
LIB	:=	-L$(LIBD)

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.$(EXT), $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.$(EXT)
		$(CC) $(CFLAGS) -c -o $@ $<

all:		dirs $(NAME)

dirs:	
		@$(MKD) $(SRCD) $(OBJD) $(INCD) $(LIBD)

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
