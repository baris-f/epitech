##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Fri Jun  3 13:21:50 2016 Florent Baris
##

PRF	:=	profondeur
LARG	:=	largeur
AST	:=	astar
TR	:=	tournoi

SRC	:=	main.c		\
		parser.c	\
		utils.c		\
		recup.c

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	gcc -g
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-W -Wall -Wextra -ansi -pedantic -I$(INCD)

LIB	:=	-lmy -L$(LIBD)

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.c
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(PRF) $(LARG) $(AST) $(TR) generate

$(PRF):		$(OBJ) $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRCD)/$(PRF).c)
		@$(CC) -o $(PRF)/solver $(OBJ) $(OBJD)/$(PRF).o $(LIB)

$(LARG):	$(OBJ) $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRCD)/$(LARG).c)
		@$(CC) -o $(LARG)/solver $(OBJ) $(OBJD)/$(LARG).o $(LIB)

$(AST):		$(OBJ) $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRCD)/$(AST).c)
		@$(CC) -o $(AST)/solver $(OBJ) $(OBJD)/$(AST).o $(LIB)

$(TR):		$(OBJ) $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRCD)/$(PRF).c)
		@$(CC) -o $(TR)/solver $(OBJ) $(OBJD)/$(PRF).o $(LIB)

generate:
	cd generateur && $(MAKE)

clean:
		@$(RM) $(OBJD)/*.o
		@$(RM) *~
		@$(RM) \#*
		@$(RM) vgcore.*
		@$(RM) $(SRCD)/*~
		@$(RM) $(SRCD)/\#*

fclean:		clean
		@$(RM) $(PRF)/solver
		@$(RM) $(LAR)/solver
		@$(RM) $(AST)/solver
		@$(RM) $(TR)/solver

re:		fclean all

.PHONY:		all fclean re $(PRF) $(LARG) $(AST) $(TR)
