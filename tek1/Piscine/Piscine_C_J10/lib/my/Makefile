##
## Makefile for Makefile in /home/baris_f/rendu/Piscine_C_J10/lib/my
## 
## Made by Florent Baris
## Login   <baris_f@epitech.net>
## 
## Started on  Fri Oct  9 09:16:34 2015 Florent Baris
## Last update Fri Oct  9 12:15:55 2015 Florent Baris
##

SRC=	$(shell echo *.c)

OBJ=	$(SRC:.c=.o)

LIBNAME= libmy.a

all:	$(LIBNAME)

$(LIBNAME):$(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	ranlib $(LIBNAME)
	cp $(LIBNAME) ../
	cp my.h ../../include

clean:
	rm $(OBJ)
