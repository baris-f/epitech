NAME	= test

SRC	= main.c
LIB	= -L lib/ -lmy
INC	= -I inc/

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -lSDLmain -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
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
