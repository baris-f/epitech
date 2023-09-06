NAME	= lib/libmy_malloc.so

SRC     :=      malloc.c

SRCD    :=      src
OBJD    :=      obj
INCD    :=      inc

CC	:= /usr/bin/gcc
RM      :=      rm -f
MV      :=      mv

CFLAGS	+= -I$(INCD) -W -Wall -Wextra -fpic
CDEBUG	= -O2 -g -ggdb

SRC     :=      $(addprefix $(SRCD)/, $(SRC))
OBJ     :=      $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:    $(SRCD)/%.c
		$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME):$(OBJ)
	$(CC) -c -I$(INCD) $(CFLAGS) $(SRC)
	$(CC) -shared -o $(NAME) $(OBJ)
	rm *.o

clean	:
	@$(RM) $(OBJD)/*.o
	@$(RM) *~
	@$(RM) \#*
	@$(RM) $(SRCD)/*~
	@$(RM) $(SRCD)/\#*


fclean	: clean
	-@$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
