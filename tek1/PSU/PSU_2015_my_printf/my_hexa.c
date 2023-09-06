/*
** my_hexa.c for my_hexa in /home/baris_f/rendu/PSU_2015_my_printf
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 16 18:27:54 2015 Florent Baris
** Last update Mon Nov 16 18:36:58 2015 Florent Baris
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"

void    my_puthexa(unsigned int nbr, char *base, char *bases, char x)
{
  if (nbr > 16)
    {
      my_puthexa(nbr / 16, base, bases, x);
    }
  if (x == 'x')
    my_putchar(base[nbr % 16]);
  else
    my_putchar(bases[nbr % 16]);
}


void    my_puthexal(long nbr, char *base)
{
  if (nbr > 16)
    my_puthexal(nbr / 16, base);
  my_putchar(base[nbr % 16]);
}

void    my_hexa(unsigned int nbr, t_stock_par t, char x)
{
  if (t.flags == '#' && x == 'x')
    my_putstr("0x");
  if (t.flags == '#' && x == 'X')
    my_putstr("0X");
  if (t.flags == ' ' && t.larg <= my_nbrlen(nbr))
    my_putchar(' ');
  if (t.flags == '-')
    my_puthexa(nbr, "0123456789abcdef", "0123456789ABCDEF", x);
  while (--t.larg >= my_nbrlen(nbr))
    my_putchar(t.tlarg);
  if (t.flags != '-')
    my_puthexa(nbr, "0123456789abcdef", "0123456789ABCDEF", x);
}
