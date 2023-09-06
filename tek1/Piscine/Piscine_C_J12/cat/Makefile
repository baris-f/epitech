##
## Makefile for Makefile in /home/baris_f/rendu/Piscine_C_J12/cat
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Tue Oct 13 10:41:12 2015 Florent Baris
## Last update Wed Oct 14 14:36:45 2015 Florent Baris
##

NAME    = cat

SRC     = cat.c

CC	= gcc

OBJ     = $(SRC:.c=.o)

LIB     = -L ../lib/ -lmy

RM      = rm -f

FLAGS  += -Wextra -Wall -Werror
#CFLAGS  += -ansi -pedantic
CFLAGS  += -I.

all: $(NAME)

clean:
	$(RM) $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

