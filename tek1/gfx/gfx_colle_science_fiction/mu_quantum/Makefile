##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Tue May 17 14:23:54 2016 Florent Baris
##

NAME	:=	quantum

SRC	:=	main.c		\
		other.c		\
		utils.c		\
		get.c		\
		line.c		\
		draw.c		\
		tektabline.c	\
		tools.c		\
		gui.c

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	gcc -g
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-W -Wall -Wextra -ansi -pedantic
CFLAGS	+=	-I$(INCD) -I${HOME}/.froot/include

LIB	:=	-lmy -llapin
LIB	+=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
LIB	+=	-L$(LIBD) -L${HOME}/.froot/lib

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.c
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

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
