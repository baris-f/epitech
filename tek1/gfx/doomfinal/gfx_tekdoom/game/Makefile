##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Thu Jan 21 12:59:49 2016 Gaspard Thirion
##

NAME	:=	gfx_tekdoom

SRC	:=	main.c		\
		mpixel.c	\
		mblit.c		\
		load_bitmap.c	\
		clear.c		\
		key.c		\
		display.c	\
		raycast.c	\
		draw_wall.c	\
		movement.c	\
		prs.c		\

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	gcc -g
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-W -Wall -Wextra -ansi -pedantic
CFLAGS	+=	-I$(INCD) -I/${HOME}/.froot/include
LIB	:=	-L$(LIBD) -L/${HOME}/.froot/lib -llapin -ldl
LIB	+=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
LIB	+=	-lm -lmy

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.c
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(LIB)

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
