/*
** common.c for operation in /home/grandm_a/Piscine_C_infinadd
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Fri Oct 23 11:17:11 2015 Corentin Grandmaire
** Last update Sun Nov  1 17:20:07 2015 Gaspard Thirion
*/

#include <stdlib.h>

void    my_memset(char *res, int len, char f)
{
  int   i;

  i = -1 ;
  while (++i < len)
    res[i] = f;
  res[i] = '\0';
}

void    spe_put_str(char *s, int sign)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (s[i] == '0' && i < my_strlen(s) - 1)
    {
      if (sign == 1)
	{
	  s[j] = '-';
	  sign = 0;
	}
      else
	s[j] = s[++i];
      j++;
      i++;
    }
  i--;
  j--;
  while (s[++i])
    s[++j] = s[i];
  s[++j] = 0;
}

int     carspe(char *nb, int *in)
{
  int   tmp;

  tmp = *in - 1;
  if (nb[tmp] < '0' || nb[tmp] > '9')
    return (0);
  return (nb[--*in] - '0');
}

int     spe_len(int nb1, int nb2)
{
  if (nb1 > nb2)
    return (nb1 + 1);
  return (nb2 + 1);
}

int     mult_len(int nb1, int nb2)
{
  if (nb1 > nb2)
    return (nb1 + nb2 + 1);
  return (nb2 + nb1 + 1);
}
