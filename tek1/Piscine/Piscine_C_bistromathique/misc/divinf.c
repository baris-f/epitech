/*
** divinf.c for divinf in /home/baris_f/rendu/bibi/op
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Oct 29 17:02:01 2015 Florent Baris
** Last update Sun Nov  1 17:58:05 2015 Florent Baris
*/

#include <stdlib.h>
#include "divinf.h"

char    *subinf_de_clochard(char *nb1, char *nb2)
{
  int   res;
  int   i;
  char  *tmp;
  int   k;

  k = -1;
  i = 0;
  res = my_getnbr(nb1) - my_getnbr(nb2);
  while (tmp[++k])
    tmp[k] = '0';
  tmp[k] = '\0';
  while (res > 0)
    {
      tmp[my_strlen(nb2) - i] = (res % 10 + '0');
      res = res / 10;
      i++;
    }
  i = 0;
  while (tmp[i] == '0')
    *tmp++;
  return (tmp);
}

char	*clean_final(char *final, char *nbr, char *div)
{
  int	i;
  int	k;

  while (final[0] == '0')
    {
      i = 0;
      k = -1;
      while (final[++k + 1])
	final[k] = final[k + 1];
    }
  i = taille_final(nbr, div);
  final[i] = '\0';
  return (final);
}

char	*add_current_digit(t_stock_char *stokaj, int *z, char *final)
{
  int	i;
  int	j;

  i = stokaj->i;
  j = 0;
  while (is_higher(stokaj->tmp, stokaj->div) >= 0)
    {
      stokaj->tmp = subinf_de_clochard(stokaj->tmp, stokaj->div);
      j++;
      stokaj->rest = stokaj->tmp;
    }
  if (j == 0 && stokaj->nbr[stokaj->pos] == '\0')
    stokaj->pos = my_strlen(stokaj->nbr) + 1;
  else
    while (*z >= 2 && stokaj->nbr[stokaj->pos] != '\0')
      {
	*z--;
	final[++i] = '0';
      }
  final[++i] = (j + '0');
  stokaj->i = i;
  return (final);
}

void	div_by_zero(char *div)
{
  if (my_strcmp(div, "0") == 0)
    {
      my_putstr("error division by 0\n");
      exit (0);
    }
}

char	*calc_final(t_stock_char *stokaj, char *final)
{
  int	z;

  while (stokaj->pos <= my_strlen(stokaj->nbr))
    {
      z = my_strlen(stokaj->div);
      stokaj->prevpos = stokaj->pos;
      my_settmp(stokaj, stokaj->nbr, &z);
      my_settmp2(stokaj, stokaj->nbr, &z);
      if (is_higher(stokaj->tmp, stokaj->div) < 0 )
	{
	  stokaj->pos = stokaj->prevpos;
	  free(stokaj->tmp);
	  z = my_strlen(stokaj->div) + 1;
	  my_settmp(stokaj, stokaj->nbr, &z);
	  my_settmp2(stokaj, stokaj->nbr, &z);
	}
      final = add_current_digit(stokaj, &z, final);
    }
  return (final);
}

char	*divinf(char *nbr, char *div)
{
  char  *final;
  t_stock_char *stokaj;

  if ((stokaj = malloc(sizeof(t_stock_char))) == NULL)
    return (0);
  stokaj->nbr = nbr;
  stokaj->div = div;
  div_by_zero(div);
  if (is_higher(div, nbr) > 0)
    return ("0");
  final = my_setmem(final, (my_strlen(nbr) - my_strlen(div)));
  stokaj->pos = -1;
  stokaj->i = -1;
  stokaj->rest = malloc(sizeof(char) * my_strlen(div));
  stokaj->rest[0] = '\0';
  final = calc_final(stokaj,final);
  final = clean_final(final, nbr, div);
  free(stokaj);
  return (final);
}

int     main(int ac, char **av)
{
  printf("%s\n", divinf(av[1],av[2]));
}
