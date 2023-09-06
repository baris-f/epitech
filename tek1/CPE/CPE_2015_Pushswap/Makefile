NAME	= push_swap

SRC	= pushswap.c
LIB	= -L lib/ -lmy
INC	= -I include/

OBJ	= $(SRC:.c=.o)

CC	= /usr/bin/gcc

RM	= rm -f
ECHO	= echo -e

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(INC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
