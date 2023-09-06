NAME	:= mort

SRC_DIR	:= src
OBJ_DIR := obj
INC_DIR := inc

RM	= rm -f
ECHO	= echo -e

CC	= /usr/bin/gcc

 CFLAGS	:= -Werror -Wall -Wall -Wextra -ansi -pedantic
 CFLAGS 	+= -I$(INC_DIR)
LDFLAGS	:= -I/home/${USER}/.froot/include -L/home/${USER}/.froot/lib -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

SRC	:=getnbr.c\
	mort.c\
	tekline.c\
	tektabline.c\
	tekpixel.c\
	tekfill.c\
	main.c


SRC	:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ	:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(INC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
	-@$(RM) $(OBJ)
	-@$(RM) *~
	-@$(RM) \#*#


fclean	: clean
	-@$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
