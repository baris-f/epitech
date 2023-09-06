##
## Makefile for nmobj in /home/baris_f/rendu/tek2/PSU_2016_nmobjdump
## 
## Made by baris_f
## Login   <florent.baris@epitech.eu>
## 
## Started on  Mon Feb 20 13:55:47 2017 baris_f
## Last update Sun Feb 26 22:58:37 2017 baris_f
##

NAME	= my_nm
NAME2	= my_objdump

SRC     :=      mainnm.c

SRC2	:=	mainobj.c	\
		affObj.c

SRCD    :=      src
OBJD    :=      obj
INCD    :=      inc

CC	:= /usr/bin/gcc
RM      :=      rm -f
MV      :=      mv

CFLAGS	+= -I$(INCD) -W -Wall -Wextra
CDEBUG	= -O2 -g -ggdb

SRC     :=	$(addprefix $(SRCD)/, $(SRC))
SRC2	:=	$(addprefix $(SRCD)/, $(SRC2))
OBJ     :=	$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))
OBJ2	:=	$(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC2))

$(OBJD)/%.o:    $(SRCD)/%.c
		$(CC) $(CFLAGS) -c -o $@ $<

all	: nm objdump

nm	:$(OBJ)
	$(CC) -o $(NAME) -I$(INCD) $(CFLAGS) $(OBJ)

objdump	:$(OBJ2)
	$(CC) -o $(NAME2) -I$(INCD) $(CFLAGS) $(OBJ2)

clean	:
	@$(RM) $(OBJD)/*.o
	@$(RM) *~
	@$(RM) \#*
	@$(RM) $(SRCD)/*~
	@$(RM) $(SRCD)/\#*


fclean	: clean
	-@$(RM) $(NAME) $(NAME2)

re	: fclean all

.PHONY	: all clean fclean re
