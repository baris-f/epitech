##
## Makefile for hashcode17 in /home/baris_f/rendu/tek2/hashcode17/baris
## 
## Made by baris_f
## Login   <florent.baris@epitech.eu>
## 
## Started on  Thu Feb 23 19:22:42 2017 baris_f
## Last update Thu Feb 23 22:19:16 2017 baris_f
##

NAME	:=	hashcode17

SRC	:=	parser.cpp	\
		writeToFile.cpp	\
		main.cpp

SRCD	:=	src
OBJD	:=	obj
INCD	:=	inc

CC	:=	g++ -g
RM	:=	rm -f
MV	:=	mv

CFLAGS	:=	-I$(INCD) -Wall -Wextra -std=c++14

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.cpp, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.cpp
		$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJD)/*.o
		@$(RM) *~
		@$(RM) \#*
		@$(RM) $(SRCD)/*~
		@$(RM) $(SRCD)/\#*

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
