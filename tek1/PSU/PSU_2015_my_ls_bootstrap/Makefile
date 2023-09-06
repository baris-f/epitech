NAME	= info_file

SRC	= $(shell echo *.c)

LIB	= -L lib/ -lmy

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
