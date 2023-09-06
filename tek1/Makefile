NAME	= test

SRC	= main.c

OBJ	= $(SRC:.c=.o)

LIB	= -L ~/.froot/lib/ \
	-llapin \
	-L/usr/local/lib \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ \
	-ldl \
	-lm \
	-I /home/fernan_g/.froot/include/


all:	$(NAME)

$(NAME): $(OBJ)
	gcc  $(OBJ) $(LIB) -o $(NAME)

clean:	
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

go:	
	LD_LIBRARY_PATH="/home/fernan_g/.froot/lin/" ./$(NAME)
