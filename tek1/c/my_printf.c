/*
** my_printf.c for my_printf in /home/baris_f/rendu/PSU_2015_my_printf
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
x**
** Started on  Wed Nov  4 17:24:51 2015 Florent Baris
** Last update Thu Jan 28 17:48:39 2016 Florent Baris
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "my.h"

void		forest(char *s, va_list ap, t_stock_par t, int *i)
{
  if (s[++(*i)] == 'd' || s[*i] == 'i')
    nbr(va_arg(ap, int), t);
  else if (s[*i] == 's')
    char_star(va_arg(ap, char*), t);
  else if (s[*i] == 'p')
    adress(va_arg(ap, long), t);
  else if (s[*i] == 'c')
    charr(va_arg(ap, unsigned int), t);
  else if (s[*i] == 'o')
   octal(va_arg(ap, unsigned int), t);
  else if (s[*i] == 'u')
    my_u(va_arg(ap, unsigned int), t);
  else if (s[*i] == 'b')
    my_putnbr_base(va_arg(ap, unsigned int), "01");
  else if (s[*i] == 'x' || s[*i] == 'X')
    my_hexa(va_arg(ap, long), t, s[*i]);
  else if (s[*i] == 'S')
    my_putS(va_arg(ap, char*));
  else if (s[*i] == '%')
    my_putchar('%');
  else
    {
      my_putchar('%');
      (*i)--;
    }
}

void		flags(char *s, int *i, t_stock_par *t, va_list ap)
{
  if (s[*i + 1] == '+' || s[*i + 1] == '-' || s[*i + 1] == ' ' ||
      s[*i + 1] == '#')
    t->flags = s[++(*i)];
  if (s[*i + 1] == '0')
    t->tlarg = '0';
  else
    t->tlarg = ' ';
  if (s[*i + 1] == '*')
    {
      t->larg = va_arg(ap, int);
      (*i)++;
    }
  else
    t->larg = get_larg(s, i);
}

void		my_printf(char *s, ...)
{
  va_list	ap;
  int		i;
  t_stock_par	t;

  if (s == NULL)
    return ;
  va_start(ap, s);
  i = -1;
  while (s[++i])
    {
      t.larg = 0;
      t.flags = 0;
      if (s[i] == '%')
	{
	  flags(s, &i, &t, ap);
	  forest(s, ap, t, &i);
	}
      else
	my_putchar(s[i]);
    }
  va_end(ap);
}
