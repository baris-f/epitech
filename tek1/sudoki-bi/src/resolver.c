/*
** resolver.c for resolver in /home/baris-f/rendu/sudoki-bi
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Feb 27 18:08:50 2016 Florent Baris
** Last update Sat Feb 27 18:59:41 2016 Florent Baris
*/

#include "bibi.h"

int     testcol(int nb, int x, int y, int *tab)
{
  int   i;

  i = -1;
  while (++i < 9)
    {
      if (tab[i * 9 + x] == nb)
	return (1);
    }
  return (0);
}

int	testlin(int nb, int x, int y, int *tab)
{
  int	i;

  i = -1;
  while (++i < 9)
    {
      if (tab[y * 9 + i] == nb)
	return (1);
    }
  return (0);
}

int     testsq(int nb, int x, int y, int *tab)
{
  int   lel;
  int   i, j;

  i = -1;
  j = -1;

  lel = (y - y % 3) * 9 + x - (x % 3);
  x = lel % 9;
  y = lel / 9;
  i = x - 1;
  while (++i < x + 3)
    {
      j = y - 1;
      while (++j < y + 3)
	if (tab[j * 9 + i] == nb)
	  return (1);
    }
  return (0);
}

int     fill(int *tab, int x, int y)
{
  int   i, j;
  int   nb;

  srand(time(NULL));
  nb = rand() % (10 - 2 + 1) + 1;
  i = 9 * y - 1;
  j = -1;
  while (++i <= y * 9 + x)
    {
      if (testlin(nb, x, y, tab))
	{
	  nb = rand() % (10 - 2 + 1) + 1;
	  i = 9 * y - 1;
	}
      else if (i == y * 9 + x)
	{
	  /* printf("i : %d nb %d\n", i, nb); */
	  j++;
	  if (j >= 100)
	    {
	      return (-1);
	    }
	  if (testcol(nb, x, y, tab) || testsq(nb, x, y, tab))
	    {
	      nb = rand() % (10 - 2 + 1) + 1;
	      i = 9 * y - 1;
	    }
	}
    }
  return (nb);
}

int	resolver(int *tab)
{

  int   y, x;

  y = -1;
  while (++y < 9)
    {
      x = -1;
      while (++x < 9)
	{
	  if (tab[x + 9 * y] == 0)
	    {
	      if ((tab[x + 9 * y] = fill(tab, x, y)) < 0)
		{
		  if (tab[x + 9 * y] == -1)
		    return (-1);
		}
	    }
	}
    }
  return (0);
}
