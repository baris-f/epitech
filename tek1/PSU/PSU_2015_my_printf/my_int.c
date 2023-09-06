/*
** my_int.c for my_int.c in /home/baris_f/rendu/PSU_2015_my_printf
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 16 18:31:39 2015 Florent Baris
** Last update Mon Nov 16 18:32:29 2015 Florent Baris
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int     my_nbrlen(int nbr)
{
  int   i;

  i = 1;
  while (nbr > 9)
    {
      nbr = nbr / 10;
      i++;
    }
  return (i);
}

void    nbr(int nbr, t_stock_par t)
{
  if (t.flags == '+')
    if (nbr >= 0)
      my_putchar('+');
  if (t.flags == ' ' && t.larg <= my_nbrlen(nbr) && nbr >= 0)
    my_putchar(' ');
  if (t.flags == '-')
    my_put_nbr(nbr);
  while (--t.larg >= my_nbrlen(nbr))
    my_putchar(t.tlarg);
  if (t.flags != '-')
    my_put_nbr(nbr);
}
