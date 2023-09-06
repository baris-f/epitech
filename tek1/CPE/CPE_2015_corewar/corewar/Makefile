##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Thu Mar 24 16:55:56 2016 Florent Baris
##

NAME	:=	corewar

SRC	:=	main.c		\
		opt.c		\
		init.c		\
		chaine.c	\
		tomem.c		\
		new_get.c	\
		ins.c

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	gcc -g
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-W -Wall -Wextra -ansi -pedantic
CFLAGS	+=	-I$(INCD)

LIB	:=	-lmy
LIB	+=	-L$(LIBD)

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
		@$(RM) vgcore*
		@$(RM) $(SRCD)/*~
		@$(RM) $(SRCD)/\#*
		@$(RM) vg*

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
