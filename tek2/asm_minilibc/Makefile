##
## Makefile for wolf3D in /home/fus/rendu/gfx_wolf3d
##
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
##
## Started on  Thu Dec 24 08:40:45 2015 Gaspard Thirion
## Last update Fri Mar 17 15:54:38 2017 baris_f
##

NAME	:=	libasm.so

SRC	:=	strlen.asm	\
		strcmp.asm	\
		rindex.asm	\
		strchr.asm	\
		memmove.asm	\
		strstr.asm	\
		memset.asm	\
		strpbrk.asm	\
		strcspn.asm	\
		strncmp.asm	\
		memcpy.asm	\
		strcasecmp.asm

SRCD	:=	src
OBJD	:=	obj

NA	:=	nasm
LD	:=	ld -shared
RM	:=	rm -f
MKD	:=	mkdir -p

SRC	:=	$(addprefix $(SRCD)/, $(SRC))
OBJ	:=	$(patsubst $(SRCD)/%.asm, $(OBJD)/%.o, $(SRC))

$(OBJD)/%.o:	$(SRCD)/%.asm
		$(NA) -o $@ $< -f elf64

all:		$(NAME)

dirs:
		@$(MKD) $(SRCD) $(OBJD)

$(NAME):	dirs $(OBJ)
		$(LD) $(OBJ) -o $(NAME)

test:		re
		gcc -g src/main.c -o test

clean:
		@$(RM) $(OBJD)/*.o
		@$(RM) *~
		@$(RM) \#*
		@$(RM) $(SRCD)/*~
		@$(RM) $(SRCD)/\#*

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) test

re:		fclean all

.PHONY:		all clean fclean re
