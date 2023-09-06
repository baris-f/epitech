/*
** disptab.c for euhoj in /home/fus/rendu/rush/sudoki-bi/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sat Feb 27 15:45:33 2016 Gaspard Thirion
** Last update Sat Feb 27 16:48:15 2016 Gaspard Thirion
*/

#include "bibi.h"

void	frame(int last, int a)
{
  int	i;

  if (last)
    {
      printf("\n");
      i = -1;
      while (++i < 20)
	printf("#");
    }
  i = -1;
  if (last)
    printf("\n");
  else if (a)
    printf("\n");
  printf("|");
  while (++i < 18)
    printf("-");
  printf("|");
}

void    disptab(int *tab, int bin, int first)
{
  int   i;

  i = -1;
  frame(first, 0);
  while (++i < 81)
    {
      if (i % 9 == 0)
	printf("\n|");
      if (tab[i] == -1)
	printf(" X");
      else if (tab[i] == 0)
	printf("  ");
      else if (!bin)
	printf(" %d", tab[i]);
      else
	my_putnbr_base(tab[i], 2);
      if (i % 9 == 8)
	printf("|");
    }
  frame(0, 1);
}
