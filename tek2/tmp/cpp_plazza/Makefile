##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Wed Mar  8 18:15:24 2017 baris_f
##

NAME	:=	plazza

SRC		:=	RegexRes.cpp	\
			Order.cpp		\
			Parse.cpp		\
			Thread.cpp		\
			Tasker.cpp		\
			Pipe.cpp		\
			main.cpp

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc

CC	:=	g++
EXT	:=	cpp
RM	:=	rm -f
MKD	:=	mkdir -p

CFLAGS	:=	-I$(INCD) -Wall -Wextra -g -std=c++0x

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.$(EXT), $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.$(EXT)
				$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

dirs:
			@$(MKD) $(SRCD) $(OBJD) $(INCD)
			@echo "void" > $(OBJD)/.void

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -lpthread

clean:
			@$(RM) $(OBJD)/*.o
			@$(RM) *~
			@$(RM) \#*
			@$(RM) $(SRCD)/*~
			@$(RM) $(SRCD)/\#*

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
