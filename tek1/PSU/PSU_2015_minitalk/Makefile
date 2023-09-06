NAME	:= server/server

NAME2	:= client/client

SRC_DIR	:= src
SRC_DIR2 := src2
OBJ_DIR := obj
OBJ_DIR2 := obj2
INC_DIR := inc

RM	= rm -f
ECHO	= echo -e

LIB	= -L lib/ -lmy

CC	= /usr/bin/gcc

 CFLAGS	:= -Wall -Wextra -ansi -pedantic
 CFLAGS 	+= -I$(INC_DIR)
LDFLAGS	:= -L lib/ -lmy

SRC	:= main.c

SRC2	:= main.c

SRC	:=	$(addprefix $(SRC_DIR)/, $(SRC))
SRC2	:=	$(addprefix $(SRC_DIR2)/, $(SRC2))
OBJ	:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ2	:=	$(patsubst $(SRC_DIR2)/%.c, $(OBJ_DIR2)/%.o, $(SRC2))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<
$(OBJ_DIR2)/%.o: $(SRC_DIR2)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME) $(NAME2)

$(NAME)	: $(OBJ)
	$(CC) $(INC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB)

$(NAME2): $(OBJ2)
	$(CC) $(INC) $(CFLAGS) -o $(NAME2) $(OBJ2) $(LDFLAGS) $(LIB)

clean	:
	-@$(RM) $(OBJ)
	-@$(RM) $(OBJ2)
	-@$(RM) *~
	-@$(RM) \#*#


fclean	: clean
	-@$(RM) $(NAME)
	-@$(RM) $(NAME2)

re	: fclean all

.PHONY	: all clean fclean re
