##
## Makefile for dksfp in /home/fus/rendu/cpe/CPE_2015_corewar
## 
## Made by Gaspard Thirion
## Login   <thirio_b@epitech.net>
## 
## Started on  Sun Mar 27 22:20:06 2016 Gaspard Thirion
## Last update Sun Mar 27 22:40:50 2016 Gaspard Thirion
##

NAME	= 	pls

CORDIR	=	corewar
ASMDIR	=	asm

all	: $(NAME)

$(NAME)	:
	@cd $(CORDIR); make
	@cd $(ASMDIR); make	

clean	:
	@cd $(CORDIR); make clean
	@cd $(ASMDIR); make clean	

fclean	: clean
	@cd $(CORDIR); make fclean
	@cd $(ASMDIR); make fclean	

re	: fclean all

.PHONY	: all clean fclean re
