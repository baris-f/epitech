##
## Makefile for  colle in /home/baris-f/rendu/gfx/colle/gfx_colle_science_fiction/mu_quantum
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Tue May 17 14:35:15 2016 Florent Baris
## Last update Fri May 20 10:44:53 2016 Florent Baris
##

NAME	:=	colle5

SRC	:=	main.c		\
		update.c	\
		other.c		\
		utils.c		\
		get.c		\
		line.c		\
		tektabline.c	\
		tools.c		\
		printlap.c

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
