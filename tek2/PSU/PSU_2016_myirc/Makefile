CC		=	gcc -g

INC		=	./include

CFLAGS		=	-W -Wall -Wextra -I$(INC) -D_GNU_SOURCE

RM		=	@rm -f

SERVER		=	./src/server

CLIENT		=	./src/client


NAME_SERVER	=	server

NAME_CLIENT	=	client

SRC_SERVER	=	$(SERVER)/main.c		\
			$(SERVER)/server.c		\
			$(SERVER)/handler_server.c	\
			$(SERVER)/handler_client.c	\
			$(SERVER)/usersutils.c		\
			$(SERVER)/channelsutils.c	\
			$(SERVER)/socketutils.c		\
			$(SERVER)/commands.c		\
			$(SERVER)/file_related.c	\
			$(SERVER)/channels_related.c	\
			$(SERVER)/misc_related.c	\
			$(SERVER)/welcoming.c		\
			$(SERVER)/rbutils.c		\
			$(SERVER)/strtowordtab.c	\
			$(SERVER)/rbinit.c		\
			$(SERVER)/utils.c		\
			$(SERVER)/sockutils.c

SRC_CLIENT	=	$(CLIENT)/main.c		\
			$(CLIENT)/commands.c		\
			$(CLIENT)/cmd_handler.c		\
			$(CLIENT)/connect.c		\
			$(CLIENT)/commands_bis.c	\
			$(CLIENT)/utils.c		\
			$(CLIENT)/strtowordtab.c	\
			$(CLIENT)/rbutils.c		\
			$(CLIENT)/rbinit.c		\
			$(CLIENT)/sockutils.c

OBJS		=	$(SRC_SERVER:.c=.o)

OBJC		=	$(SRC_CLIENT:.c=.o)


all		:
			@$(MAKE) --no-print-directory $(NAME_SERVER)
			@$(MAKE) --no-print-directory $(NAME_CLIENT)

server		:	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME_SERVER)

client		:	$(OBJC)
			@$(CC) $(CFLAGS) $(OBJC) -o $(NAME_CLIENT)

clean		:
			$(RM) $(OBJS) $(OBJC)

fclean		:	clean
			$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re		:	fclean all
