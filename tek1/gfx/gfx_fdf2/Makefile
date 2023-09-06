##
## Makefile for fdf in /home/fus/rendu/gfx_fdf1
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Wed Nov 18 22:14:17 2015 Gaspard Thirion
## Last update Mon Dec 21 22:17:08 2015 Florent Baris
##

NAME	= fdf2

TDIR	= src/

SDIR	= main/

SRC	= main.c\
	gfx_fdf2.c

TOOL	= $(TDIR)tekpixel.c \
	$(TDIR)/tekline.c \
	$(TDIR)/tekblit.c \
	$(TDIR)tekisoproject.c \
	$(TDIR)tekfill.c \
	$(TDIR)tekkey.c \
	$(TDIR)tektabline.c \
	$(TDIR)tekcircle.c

LLAPIN	= -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

LMY	= -lmy -L ./

INC	= -I ./

OBJ	= $(SRC:.c=.o) $(TOOL:.c=.o)

CC	= gcc

CFLAGS	= -W -Wall -Wextra -ansi -pedantic

RM	= rm -f

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LMY) $(LLAPIN)

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
