/*
** convert_base.c for convert_base in /home/baris_f/rendu/bibi/misc
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Oct 28 09:50:36 2015 Florent Baris
** Last update Mon Feb  1 12:30:56 2016 Florent Baris
*/

#include <stdio.h>

int	valinbase(char nb, int pos, int len)
{
  int	res;

  res = nb - '0';
  res = res * my_power_rec(len, pos);
  return (res);
}

int	*convert_base(char *nbr, char *frombase, char *tobase)
{
  int	i;
  int	len;
  int	res;
  int	rest;
  int	tmp;
  int	final;

  len = my_strlen(frombase);
  i = 0;
  res = 0;
  if (nbr[0] == '-')
    (*nbr)++;
  while (i < my_strlen(nbr))
    {
      res += valinbase(nbr[my_strlen(nbr) - 1 - i], i, len);
      i++;
    }
  tmp = 0;
  len = my_strlen(tobase);
  i = 0;
  final = 0;
  while (final < res)
    {
      final = my_power_rec(len, i);
      i++;
    }
  final = 0;
  rest = res;
  while (i > 1)
    {
      tmp = rest / my_power_rec(len, --i - 1);
      rest = rest % my_power_rec(len, i - 1);
      final *= 10;
      final += tmp;
    }
  return(final);
}

int	main(int ac, char **av)
{
  if (ac != 4)
    {
      my_putstr("USAGE: ./a.out nbr frombase tobase");
      return (0);
    }
  my_put_nbr(convert_base(av[1], av[2], av[3]));
  my_putchar('\n');
  return (0);
}
