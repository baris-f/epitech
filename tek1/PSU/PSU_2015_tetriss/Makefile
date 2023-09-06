NAME	:= tetris

SRC_DIR	:= src
OBJ_DIR := obj
INC_DIR := inc

RM	= rm -f
ECHO	= echo -e

LIB	= -L lib/ -lmy

CC	= /usr/bin/gcc

SRC     := main.c	\
        other.c		\
        parser.c	\
        set_key.c	\
	draw.c		\
	draw_letters.c	\
	game.c		\
	col.c		\
	match.c		\
	tri.c


CFLAGS := -Wall -Wall -Wextra  -pedantic -g #-ansi
CFLAGS += -I$(INC_DIR)

SRC	:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ	:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) -g $(INC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB) -lncurses

clean	:
	-@$(RM) $(OBJ)
	-@$(RM) *~
	-@$(RM) \#*#


fclean	: clean
	-@$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
