##
## Makefile for fdf in /home/fus/rendu/gfx_fdf1
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Wed Nov 18 22:14:17 2015 Gaspard Thirion
## Last update Sun Dec  6 23:33:20 2015 Florent Baris
##

NAME	= fire

TDIR	= src/

SRC	= incendie.c\
	flame.c

TOOL	= $(TDIR)tekpixel.c \
	$(TDIR)/tekline.c \
	$(TDIR)tekllproject.c \
	$(TDIR)tekisoproject.c \
	$(TDIR)tekfill.c \
	$(TDIR)tekkey.c \
	$(TDIR)tektabline.c \
	$(TDIR)tektabgradiant.c \
	$(TDIR)linelen.c \
	$(TDIR)gradiant.c \
	$(TDIR)teklinegrad.c \


LLAPIN	= -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

LMY	= -lmy -L ./

INC	= -I ./

OBJ	= $(SRC:.c=.o) $(TOOL:.c=.o)

CC	= gcc -g

CFLAGS	= -W -Wall -Wextra -ansi -pedantic

RM	= rm -f

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LMY) $(LLAPIN)

my	: $(NAME) clean

clean	:
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) \#*#
	@$(RM) ./src/*~
	@$(RM) ./src/\#*#

fclean	: clean
	@$(RM) $(NAME)

re	: fclean all

.PHONY	: all my clean fclean re
