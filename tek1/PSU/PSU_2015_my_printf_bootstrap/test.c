/*
** test.c for test in /home/baris_f/rendu/PSU_2015_my_printf_bootstrap
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Nov  5 09:33:55 2015 Florent Baris
** Last update Thu Nov  5 12:36:04 2015 Florent Baris
*/

#include <stdarg.h>
#include "my.h"

int		sum_stdarg(int i, int nb, ...)
{
  va_list	ap;
  int		result;
  int		j;

  va_start(ap, nb);
  result = 0;
  j = -1;
  if (i == 0)
    while (++j < nb)
	result += va_arg(ap, int);
  else if (i == 1)
    while (++j < nb)
      result += my_strlen(va_arg(ap, char*));
  va_end(ap);
  return(result);
}

int		disp_stdarg(char *s, ...)
{
  va_list	ap;
  int		i;

  va_start(ap, s);
  i = -1;
  while (s[++i])
    {
      if (s[i] == 'c')
	my_putchar(va_arg(ap, unsigned int));
      else if (s[i] == 's')
	my_putstr(va_arg(ap, char*));
      else if (s[i] == 'i')
	my_put_nbr(va_arg(ap, int));
      my_putchar('\n');
    }
  va_end(ap);
  return (0);
}
