/*
** generator.c for generator in /home/baris-f/rendu/sudoki-bi
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Feb 27 11:07:09 2016 Florent Baris
** Last update Sun Feb 28 14:56:04 2016 Florent Baris
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void	afftab(int *tab);
void    memsetint(int *tab, int size, int nb);
void    checknfill(int *tab, int *x, int *y);
void    writab(int *tab, char *name);

int	testcol(int nb, int x, int y, int *tab)
{
  int	i;

  i = -1;
  while (++i < 9)
    {
      if (tab[i * 9 + x] == nb)
	return (1);
    }
  return (0);
}

int	testsq(int nb, int x, int y, int *tab)
{
  int	lel;
  int	i, j;

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
int	*generate(int dens)
{
  int	y;
  int	x;
  int	*tab;

  if ((tab = malloc(sizeof(int) * 81)) == NULL)
    return (0);
  memsetint(tab, 81, 0);
  y = -1;
  while (++y < 9)
    {
      x = -1;
      while (++x < 9)
	checknfill(tab, &x, &y);
    }
  return (tab);
}

void	put_res(int *tab, int nb)
{
  int	i;
  int	ran;

  i = -1;
  while (++i < 81 - nb)
    {
      ran = rand() % (81) + 1;
      if (tab[ran] > 0)
	tab[ran] = 0;
      else
	i--;
    }
}

int	main(int ac, char **av)
{
  int	i;
  int	*tab;

  tab = generate(1);
  afftab(tab);
  printf("map in --> solved.txt\n");
  writab(tab, "solve.txt");
  if (ac == 2 && atoi(av[1]) >= 17 && atoi(av[1]) <= 81)
    {
      printf("%d clues grid :\n", atoi(av[1]));
      put_res(tab, atoi(av[1]));
    }
  else
    {
      printf("20 clues by default\n");
      put_res(tab, 20);
    }
  afftab(tab);
  printf("map in --> grids.txt\n");
  writab(tab, "grids.txt");
}
