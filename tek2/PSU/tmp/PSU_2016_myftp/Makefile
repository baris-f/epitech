##
## Makefile for make in /home/baris_f/rendu/tek2/PSU/tmp/PSU_2016_myftp
## 
## Made by baris_f
## Login   <florent.baris@epitech.eu>
## 
## Started on  Sun May 21 22:47:17 2017 baris_f
## Last update Sun May 21 23:06:13 2017 baris_f
##

NAME	:=	server

SRC	:=	main.c		\
		utils.c		\
		pwd.c		\
		request.c	\
		myfunctions.c	\
		init.c

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc

CC	:=	gcc
EXT	:=	c
RM	:=	rm -f
MKD	:=	mkdir -p

CFLAGS	:=	-I$(INCD) -Wall -Wextra -g

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.$(EXT), $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.$(EXT)
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

dirs:
		@$(MKD) $(SRCD) $(OBJD) $(INCD)

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

re:		fclean all

.PHONY:		all clean fclean re
