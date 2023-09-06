/*
** utils.c for tree in /home/baris-f/rendu/colle/CPE_colle_semaine1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Apr 27 15:17:35 2016 Florent Baris
** Last update Wed May  4 14:50:54 2016 Florent Baris
*/

#include "p4.h"

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (-1);
  return (0);
}

int	my_putstr(char *str)
{
  int	i;
  int	max;

  max = my_strlen(str);
  i = -1;
  while (++i < max)
    {
      if (my_putchar(str[i]) == -1)
	return (-1);
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

int	my_strcmp(char *src, char *cmp)
{
  int	i;
  int	srclen;
  int	cmplen;

  srclen = my_strlen(src);
  cmplen = my_strlen(cmp);
  if (srclen != cmplen)
    return (-1);
  i = 0;
  while (src[i] == cmp[i])
    i++;
  if (i != srclen)
    return (-1);
  return (1);
}
