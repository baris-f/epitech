/*
** my_getnbr.c for p4 in /home/baris-f/rendu/colle/CPE_colle_semaine2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed May  4 16:59:36 2016 Florent Baris
** Last update Wed May  4 17:35:09 2016 Florent Baris
*/

#include "p4.h"

void	my_putnbr(int nb)
{
  while (nb > 0)
    {
      my_putchar(nb % 10 + 48);
      nb /= 10;
    }
}

int	my_getnbr(char *str)
{
  int	res;
  int	i;
  int	len;

  len = 1;
  i = -1;
  res = 0;
  while (str[++i] && str[i] >= '0' && str[i] <= '9');
  if (i == 0)
    return (-1);
  while (--i >= 0)
    {
      res += (str[i] - 48) * len;
      len = len * 10;
    }
  return (res);
}
