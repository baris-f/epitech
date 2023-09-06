NAME	:= mysh

SRC_DIR	:= src
OBJ_DIR := obj
INC_DIR := inc

RM	= rm -f
ECHO	= echo -e

LIB	= -L lib/ -lmy

CC	= /usr/bin/gcc

 CFLAGS	:= -Wall -Wall -Wextra -ansi -pedantic -g
 CFLAGS 	+= -I$(INC_DIR)

SRC     := main.c\
        list.c\
        env.c\
        signal.c\
        get.c\
        check.c\
        cd.c


SRC	:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ	:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) -g $(INC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB)

clean	:
	-@$(RM) $(OBJ)
	-@$(RM) *~
	-@$(RM) \#*#


fclean	: clean
	-@$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
