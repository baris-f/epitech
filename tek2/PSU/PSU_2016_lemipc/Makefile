##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Fri Mar 31 18:05:19 2017 baris_f
##

NAME	:=	lemipc

SRC		:=	main.c		\
			update.c	\
			draw.c		\
			ia.c		\
			move.c

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc

CC		:=	gcc
EXT		:=	c
RM		:=	rm -rf
MKD		:=	mkdir -p

CFLAGS	:=	-I$(INCD) -Wall -Wextra -g

SRC		:=	$(addprefix $(SRCD)/, $(SRC))
OBJ		:=	$(patsubst $(SRCD)/%.$(EXT), $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.$(EXT)
				$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

fixes:
			@touch * $(SRC)
			@$(MKD) $(SRCD) $(OBJD) $(INCD)
			@echo obj > $(OBJD)/.obj

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

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
