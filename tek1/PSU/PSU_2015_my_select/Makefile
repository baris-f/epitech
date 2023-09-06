NAME	= my_select

SRC	= my_select.c\
	matchselect.c\
	input.c\
	search.c\
	aff.c

OBJ	= $(SRC:.c=.o)

CFLAGS  = -W -Wall -Wextra -ansi -pedantic

LIB	= -L lib/ -lmy

all:	$(NAME)

$(NAME): $(OBJ)
	gcc  $(OBJ) $(LIB) -o $(NAME) -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
