##
## Makefile for tekgui in /home/baris-f/rendu/gfx/gfx_tekgui
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Sun Feb 28 21:32:44 2016 Florent Baris
## Last update Sun Feb 28 23:06:54 2016 Florent Baris
##


NAME	:=	lib/libtekgui.a

SRC	:=	boxs.c		\
		tekfunction.c	\
		load_bitmap.c   \
		key.c           \
		tekpixel.c      \
		tekblit.c       \
		tekfill.c       \
		font.c          \
		window.c        \
		button.c        \
		parser.c        \
		get.c   \
		get2.c  \
		click.c \
		display.c


SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	gcc -g
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-W -Wall -Wextra -ansi -pedantic
CFLAGS	+=	-I$(INCD) -I${HOME}/.froot/include

LIB	:=	-ltekgui -lmy -llapin -ldl
LIB	+=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
LIB	+=	-L$(LIBD) -L${HOME}/.froot/lib

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.c
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

demo:		clean
		gcc -c src/main.c $(CFLAGS)
		$(CC) -o demo_tekgui main.o $(LIB)

clean:
		@$(RM) $(OBJD)/*.o
		@$(RM) *~
		@$(RM) \#*
		@$(RM) main.o
		@$(RM) $(SRCD)/*~
		@$(RM) $(SRCD)/\#*

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) test

re:		fclean all

.PHONY:		all clean fclean re
