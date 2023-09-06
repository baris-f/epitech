/*
** do-op.c for do-op in /home/baris_f/rendu/Piscine_C_J10/do-op
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Oct  9 11:06:25 2015 Florent Baris
** Last update Mon Oct 12 19:50:25 2015 Florent Baris
*/

#include "do-op.h"

void	init(t_struct ptr[5])
{
  ptr[0].fct = &add;
  ptr[0].op = '+';
  ptr[1].fct = &sub;
  ptr[1].op = '-';
  ptr[2].fct = &mul;
  ptr[2].op = '*';
  ptr[3].fct = &div;
  ptr[3].op = '/';
  ptr[4].fct = &mod;
  ptr[4].op = '%';
  ptr[5].fct = 0;
}

int	do_op(int a, int b, char opt, t_struct ptr[5])
{
  int	i;
  if (b == 0 && a == 0)
    my_put_nbr(0);
  else
    {
      i = -1;
      while (++i <= 4)
	{
	  if ((ptr[i]).op == opt)
	    return (ptr[i].fct(a, b));
	}
      my_put_nbr(0);
    }
  return (0);
}

char	findop(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'
|| str[i] == '%')
	return (str[i]);
      i++;
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_struct	ptr[5];

  if (ac == 4)
    {
      init(ptr);

      do_op(my_getnbr(av[1]), my_getnbr(av[3]), findop(av[2]), ptr);
      my_putchar('\n');
    }
  return (0);
}
