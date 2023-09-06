/*
** fill.c for fill in /home/baris-f/rendu/generator
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 14:31:43 2016 Florent Baris
** Last update Sun Feb 28 14:37:03 2016 Florent Baris
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int     testcol(int nb, int x, int y, int *tab);
int     testsq(int nb, int x, int y, int *tab);

void    afftab(int *tab)
{
  int   i;

  i = -1;
  while (++i < 81)
    {
      if (i % 9 == 0 && i != 0)
	printf("\n");
      printf("%d ", tab[i]);
    }
  printf("\n");
}

void    retry(int *nb, int *i, int y)
{
  *nb = rand() % (10 - 2 + 1) + 1;
  *i = 9 * y - 1;
}

int     fill(int *tab, int x, int y)
{
  int   i;
  int   j;
  int   nb;

  srand(time(NULL));
  retry(&nb, &i, y);
  j = -1;
  while (++i <= y * 9 + x)
    if (nb == tab[i])
      retry(&nb, &i , y);
    else if (i == y * 9 + x)
      {
	j++;
	if (j >= 100)
	  return (((y % 3) - 1 == 0) ? (-2) : (-1));
	else if (testcol(nb, x, y, tab) || testsq(nb, x, y, tab))
	  retry(&nb, &i , y);
      }
  return (nb);
}

void    memsetint(int *tab, int size, int nb)
{
  int   i;

  i = -1;
  while (++i < size)
    tab[i] = nb;
}

void    checknfill(int *tab, int *x, int *y)
{
  if ((tab[*x + 9 * *y] = fill(tab, *x, *y)) < 0)
    {
      if (tab[*x + 9 * *y] == -2)
	{
	  *x = -1;
	  while (++*x < 9)
	    tab[9 * *y + *x] = 0;
	  *x = -1;
	}
      else if (tab[*x + 9 * *y] == -1)
	{
	  memsetint(tab, 81, 0);
	  *y = -1;
	  *x = 9;
	}
    }
}
