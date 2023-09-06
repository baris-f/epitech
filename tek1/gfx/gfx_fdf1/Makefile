
NAME	= fdf1

SRC	= update.c

TOOL	= src/tekpixel.c \
	src/tekline.c \
	src/tekllproject.c \
	src/my_fill.c \
	src/gfx_fdf1.c

LIB	= -L ~/.froot/lib -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

INC	= -I ./src/my_lap.h

OBJ	= $(SRC:.c=.o) $(TOOL:.c=.o)

CC	= gcc -g

CFLAGS	= -W -Wall -Wextra -ansi -pedantic

RM	= rm -f

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L lib/ -lmy $(INC) $(LIB)

my	: $(NAME) clean

clean	:
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) \#*#
	@$(RM) ./src/*~
	@$(RM) ./src/\#*#

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all my clean fclean re
