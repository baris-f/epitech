NAME	= my_ls

SRC	= my_ls.c\
	my_strcmpls.c\
	lopt.c\
	bubble.c

OBJ	= $(SRC:.c=.o)

CC      = /usr/bin/gcc

FLAGS  = -W -Wall -Wextra -ansi -pedantic

LIB	= -L lib/ -lmy

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
