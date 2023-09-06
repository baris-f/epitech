##
## Makefile for tekGUI in /home/baris-f/rendu/gfx/gfx_tekgui
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Wed Feb  3 21:21:18 2016 Florent Baris
## Last update Sun Feb 21 14:24:07 2016 Florent Baris
##

NAME	:=	allum1

SRC	:=	get_next_line.c	\
		ai.c		\
		main.c

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc
LIBD	:=	lib

CC	:=	gcc -g
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-W -Wall -Wextra -ansi -pedantic
CFLAGS	+=	-I$(INCD)
LIB	:=	-L $(LIBD) -lmy

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
