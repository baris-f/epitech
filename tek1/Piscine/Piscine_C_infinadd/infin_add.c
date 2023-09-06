/*
** infin_add.c for infin_add in /home/baris_f/rendu/Piscine_C_infinadd/lib/my
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Oct 19 11:00:09 2015 Florent Baris
** Last update Thu Oct 22 14:05:30 2015 Florent Baris
*/

#include <stdlib.h>
#include "./include/my.h"

int	ntwelve(int len1, int i, char *nb1)
{
  if (len1 - i >= 0)
    return (nb1[len1 - i] - '0');
  else
    return (0);
}

char	*infinadd(char *res, char *nb1, char *nb2, int len)
{
  int	ret;
  int	n1;
  int	n2;
  int	i;

  ret = 0;
  i = -1;
  while (++i < len)
    res[i] = '0';
  i = 0;
  while (i <= my_strlen(nb1) - 1 || i <= my_strlen(nb2) - 1 || ret == 1)
    {
      n1 = ntwelve(my_strlen(nb1) - 1, i, nb1);
      n2 = ntwelve(my_strlen(nb2) - 1, i, nb2);
      res[len - i] = (n1 + n2 + ret) % 10 + '0';
      ret = (n1 + n2 + ret) / 10;
      i++;
    }
  return (res);
}

void	my_superputstr(char *str, int len)
{
  int	i;

  i = 0;
  if (str[0] == '-')
    {
      my_putchar('-');
      i++;
    }
  while (str[i] == '0' && i < len)
    i++;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  my_putchar('\n');
}

int	main(int ac, char **av)
{
  char	*res;
  int	len;

  if (ac != 3)
    {
      my_putstr("USAGE: ./infin_add number1 number2\n");
      return (0);
    }
  if (my_strlen(av[1]) > my_strlen(av[2]))
    len = my_strlen(av[1]);
  else
    len = my_strlen(av[2]);
  if ((res = malloc(sizeof(*res) * len)) == NULL)
    return (0);
  if (av[1][0] == '-' && av[2][0] == '-')
    {
      av[1]++;
      av[2]++;
      infinadd(res, av[1], av[2], len);
      res[0] = '-';
    }
  res = infinadd(res, av[1], av[2], len);
  my_superputstr(res, len);
  free(res);
  return (0);
}
