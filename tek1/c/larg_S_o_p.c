/*
** my_printf3.c for my_printf3.c in /home/baris_f/rendu/PSU_2015_my_printf
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 16 12:33:11 2015 Florent Baris
** Last update Thu Jan 28 17:44:53 2016 Florent Baris
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "my.h"

int     get_larg(char *s, int *i)
{
  int   len;
  int   j;
  int   k;
  int   larg;

  larg = 0;
  k = 1;
  j = -1;
  len = 0;
  while (s[*i + 1] >= '0' && s[*i + 1] <= '9')
    {
      k *= 10;
      (*i)++;
      len++;
    }
  while (++j < len)
    (*i)--;
  while (--j >= 0)
    {
      (*i)++;
      k = k / 10;
      larg += (s[*i] - '0') * k;
    }
  return (larg);
}

void    adress(long nbr, t_stock_par t)
{
  if (t.flags == ' ' && t.larg <= my_nbrlen(nbr))
    my_putchar(' ');
  if (t.flags == '-')
    {
      my_putstr("0x");
      my_puthexal(nbr, "0123456789abcdef");
    }
  while (--t.larg >= 14)
    my_putchar(t.tlarg);
  if (t.flags != '-')
    {
      my_putstr("0x");
      my_puthexal(nbr, "0123456789abcdef");
    }
}

int     my_puto(int nbr, char *base, int i, int getlen)
{
  i++;
  if (nbr > 8)
    {
      my_puto(nbr / 8, base, i, getlen);
    }
  if (getlen == 0)
    my_putchar(base[nbr % 8]);
  if (nbr <= 8)
    return (i);
  return (0);
}

void            octal(unsigned int nbr, t_stock_par t)
{
  int           dif;

  dif = 0;
  if (t.flags == '#')
    dif++;
  if (t.flags == '-')
    {
      if (t.flags == '#')
        my_putchar('0');
      my_putnbr_base(nbr, "01234567");
    }
  while (--t.larg >= my_puto(nbr, "01234567", 0, 1) + dif)
    my_putchar(t.tlarg);
  if (t.flags != '-')
    {
      if (t.flags == '#')
        my_putchar('0');
      my_putnbr_base(nbr, "01234567");
    }
}

void    my_putS(char *s)
{
  int   i;
  int   len;

  if (s == NULL)
    {
      my_putstr("(null)");
      return ;
    }
  i = -1;
  while (s[++i])
    {
      if (s[i] < 32 || s[i] >= 127)
        {
	  len = my_puto(s[i], "01234567", 0, 1);
          my_putchar('\\');
          while (++len <= 3)
            my_putchar('0');
          my_puto(s[i], "01234567", 0, 0);
        }
      else
        my_putchar(s[i]);
    }
}
