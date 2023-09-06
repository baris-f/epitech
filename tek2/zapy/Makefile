##
## Makefile for makefile in /home/baris_f/rendu/tek2/zapy
## 
## Made by baris_f
## Login   <florent.baris@epitech.eu>
## 
## Started on  Thu Jun 29 15:44:42 2017 baris_f
## Last update Sat Jul  1 17:12:50 2017 baris_f
##


NAME	:=	zappy_ia

SRC	:=	main.c	\
		parse.c	\
		ia.c	\
		actions.c

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	gcc
EXT	:=	c
RM	:=	rm -f
MKD	:=	mkdir -p

CFLAGS	:=	-I$(INCD) -Wall -Wextra -g

LIB	:=	$(addprefix $(LIBD)/, $(LIB))
SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.$(EXT), $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.$(EXT)
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

dirs:
		@$(MKD) $(SRCD) $(OBJD) $(INCD)

$(NAME):	$(OBJ)
		$(CC) -L$(LIBD) -o $(NAME) $(OBJ)

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
