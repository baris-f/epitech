/*
** addinf.c for operation in /home/grandm_a/Piscine_C_infinadd
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Fri Oct 23 11:19:01 2015 Corentin Grandmaire
** Last update Sun Nov  1 18:56:20 2015 Gaspard Thirion
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char    *mstrcat(char *dest, char *src)
{
  int   i;
  int   initlen;

  initlen = my_strlen(dest);
  i = initlen;
  while (i <= my_strlen(src) + initlen - 1)
    {
      dest[i] = src[i - initlen];
      i++;
    }
  dest[i] = 0;
  return ;
}

char	*print(char *res)
{
  int	i;

  while (*res == 0)
    res++;
  i = 0;
  while ((res[i] + 1) != '\0')
    {
      res[i] = res[i] + '0';
      i++;
    }
  res[i] = 0;

  return (res);
}

void	add(char *res, int n, char c1, char c2)
{
  int	d;
  int	u;

  u = n + 1;
  d = n;
  res[u] = ((res[u]) + (c1 - '0') * (c2 - '0'));
  res[d] = ((res[d]) + (res[u]) / 10);
  res[u] = ((res[u]) % 10);
}

char	*cor(char *nb1, char *nb2)
{
  char	*res;
  int	res_size;
  int	ret;
  int	i;
  int	j;

  i = my_strlen(nb1) - 1;
  j = my_strlen(nb2) - 1;
  ret = j;
  res_size = my_strlen(nb1) + my_strlen(nb2);
  res = malloc(sizeof(*res) * (res_size + 1));
  my_memset(res, res_size, '\0');
  res[res_size] = -1;
  while (i >= 0)
    {
      j = ret;
      while (j >= 0)
	{
	  add(res, i + j, nb1[i], nb2[j]);
	  j--;
	}
      i--;
    }
    return (res);
}

void	mult2(char **nb1, char *nb2, int neg, int tmp)
{
  char	*mem;

  if (neg == 1 && tmp == 0)
    {
      mem = print(cor(*nb1, nb2));
      my_memset(*nb1, my_strlen(*nb1));
      *nb1[0] = '-';
      mstrcat(*nb1, mem);
    }
  else
    *nb1 = print(cor(*nb1, nb2));
  if (tmp != 0)
    {
      *nb1[0] = '0';
      *nb1[1] = '\0';
    }
  }

void	mult(char **nb1, char *nb2)
{
  int	neg;
  int	i;
  int	tmp;

  tmp = 0;
  i = 0;
  neg = 0;
  while (*nb1[i] == '0' || nb2[i] == '0')
    {
      tmp++;
      i++;
    }
  if (*nb1[0] == '-')
    {
      neg++;
      *nb1++;
    }
  if (nb2[0] == '-')
    {
      neg++;
      nb2++;
    }
  mult2(nb1, nb2, neg, tmp);
}
