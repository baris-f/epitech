##
## Makefile for kk in /home/grandma/PSU_2015_42sh
## 
## Made by Corentin Grandmaire
## Login   <grandm_a@epitech.net>
## 
## Started on  Mon May  2 12:59:20 2016 Corentin Grandmaire
## Last update Sun Jun  5 21:35:04 2016 Corentin Grandmaire
##

NAME	:=	42sh

SRC	:=	main.c		\
		ast.c		\
		del_ast.c	\
		env.c		\
		init.c		\
		prompt.c	\
		utils2.c	\
		utils.c		\
		signal.c	\
		ptr.c		\
		ptr2.c		\
		builtin.c	\
		exec.c		\
		exec2.c		\
		cd_builtin.c	\
		echo_builtin.c	\
		verif.c		\
		verif2.c	\

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	gcc
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
		@$(RM) $(SRCD)/*~
		@$(RM) $(SRCD)/\#*

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
