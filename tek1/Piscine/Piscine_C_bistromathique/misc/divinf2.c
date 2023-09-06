/*
** divinf2.c for divinf2 in /home/baris_f/rendu/bibi/op
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Nov  1 17:49:01 2015 Florent Baris
** Last update Sun Nov  1 17:51:42 2015 Florent Baris
*/

#include <stdlib.h>
#include "divinf.h"

int     is_higher(char *nb1, char *nb2)
{
  if (nb1[0] == '0')
    return (-1);
  if (my_strlen(nb1) > my_strlen(nb2))
    return (2);
  else if (my_strlen(nb2) > my_strlen(nb1))
    return (-1);
  else
    return (my_strcmp(nb1, nb2));
}

int     taille_final(char *nbr, char *div)
{
  if (my_strcmp(nbr, div) < 0)
    return (my_strlen(nbr) - my_strlen(div));
  else
    return (my_strlen(nbr) - my_strlen(div) + 1);
}

char    *my_setmem(char *str, int len)
{
  int   i;

  i = -1;
  if ((str = malloc(sizeof(char) * len)) == NULL)
    return (0);
  while (++i < len)
    str[i] = '0';
  str[i] = '\0';
  return (str);
}

char    *my_settmp(t_stock_char *stokaj, char *nbr, int *len)
{
  int   k;

  stokaj->tmp = my_setmem(stokaj->tmp, *len);
  k = -1;
  if (stokaj->rest[0] != '\0')
    while (stokaj->rest[k + 1])
      {
	k++;
        stokaj->tmp[k] = stokaj->rest[k];
      }
  *len = k;
}

char    *my_settmp2(t_stock_char *stokaj, char *nbr, int *k)
{
  int   z;

  z = 0;
  while (stokaj->tmp[++(*k)])
    {
      z++;
      stokaj->tmp[(*k)] = nbr[++stokaj->pos];
    }
  *k = z;
}
