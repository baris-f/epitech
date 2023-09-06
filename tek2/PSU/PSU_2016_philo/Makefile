##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Wed Mar  8 18:15:24 2017 baris_f
##

NAME	:=	philo

SRC	:=	main.c	\
		parse.c	\
		philo.c

LIB	:=	libriceferee

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

export:
		export LD_LIBRARY_PATH=./lib/

dirs:
		@$(MKD) $(SRCD) $(OBJD) $(INCD)

$(NAME):	$(OBJ)
		$(CC) -L$(LIBD) -o $(NAME) $(OBJ) -lriceferee -lpthread

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
