NAME	= asm

SRC	= main.c \
	op.c \
	match.c \
	utils.c \
	utils2.c \
	epur.c \
	arg.c \
	trait.c


LIB	= -L ./lib/ -lmy

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc

CFLAGS	= -I include/ -W -Wall -Wextra -ansi -pedantic -g
CDEBUG	= -O2 -g -ggdb

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
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

