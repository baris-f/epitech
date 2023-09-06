##
## Makefile for puiss in /home/baris-f/rendu/colle/CPE_colle_semaine2
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Wed May  4 14:41:58 2016 Florent Baris
## Last update Wed May  4 17:53:12 2016 Florent Baris
##

NAME	= power4

SRCDIR	= src

SRC	=	src/main.c	\
		src/utils.c	\
		src/power4.c	\
		src/over.c	\
		src/my_getnbr.c	\
		src/ia.c	\
		src/param.c	\
		src/check_err.c


INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc

CFLAGS	= -W -Wall -Wextra -Werror -I ./inc/
CDEBUG	= -O2 -g -ggdb

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $(INC) $(CFLAGS) -o $(NAME) $(OBJ)
	@$(ECHO) '\033[0;32m> Compiled\033[0m'

clean	:
	-@$(RM) $(OBJ)
	-@$(RM) *~
	-@$(RM) \#*#
	@$(ECHO) '\033[0;31m> Directory cleaned\033[0m'


fclean	: clean
	-@$(RM) $(NAME)
	@$(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

.PHONY	: all clean fclean re

debug	: $(OBJ)
	@$(CC) $(INC) $(CDEBUG) -o $(NAME) $(OBJ) $(LIB)
	@$(ECHO) '\033[0;33m> Mode Debug: done\033[0m'

