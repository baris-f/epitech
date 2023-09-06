/*
** my_char.c for my_char.c in /home/baris_f/rendu/PSU_2015_my_printf
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 16 18:34:42 2015 Florent Baris
** Last update Thu Jan 28 17:47:54 2016 Florent Baris
*/

 #include <stdarg.h>
 #include <stdlib.h>
 #include "my_printf.h"
#include "my.h"

void    charr(int nbr, t_stock_par t)
{
  if (t.flags == '-')
    my_putchar(nbr);
  while (--t.larg >= 1)
    my_putchar(t.tlarg);
  if (t.flags != '-')
    my_putchar(nbr);
}

void            char_star(char *str, t_stock_par t)
{
  if (t.flags == '-')
    {
      if (str == NULL)
	my_putstr("(null)");
      else
	my_putstr(str);
    }
  if (str == NULL)
    while (--t.larg >= 6)
      my_putchar(t.tlarg);
  else
    while (--t.larg >= my_strlen(str) && str != NULL)
      my_putchar(t.tlarg);
  if (t.flags != '-')
    {
      if (str == NULL)
	my_putstr("(null)");
      else
	my_putstr(str);
    }
}
