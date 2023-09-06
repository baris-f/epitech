/*
** my_printf2.c for my_printf2 in /home/baris_f/rendu/PSU_2015_my_printf
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 16 12:31:37 2015 Florent Baris
** Last update Mon Nov 16 18:32:27 2015 Florent Baris
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

int     my_nbrlenu(unsigned int nbr)
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

void            my_putu(unsigned int nb)
{
  if (nb > 10 - 1)
    my_putu(nb / 10);
  my_putchar(nb % 10 + '0');
}

void            my_u(unsigned int nbr, t_stock_par t)
{
  if (t.flags == ' ' && t.larg <= my_nbrlenu(nbr))
    my_putchar(' ');
  if (t.flags == '-')
    my_putu(nbr);
  while (--t.larg >= my_nbrlenu(nbr))
    my_putchar(t.tlarg);
  if (t.flags != '-')
    my_putu(nbr);
}
