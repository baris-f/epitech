/*
** generator.c for generator in /home/baris-f/rendu/sudoki-bi
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Feb 27 11:07:09 2016 Florent Baris
** Last update Sat Feb 27 16:49:37 2016 Florent Baris
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void	afftab(int *tab);

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

int	fill(int *tab, int x, int y)
{
  int	i, j;
  int	nb;

  srand(time(NULL));
  nb = rand() % (10 - 2 + 1) + 1;
  i = 9 * y - 1;
  j = -1;
  while (++i <= y * 9 + x)
    {
      if (nb == tab[i])
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
	      if ((y % 3) - 1 == 0)
		return (-2);
	      else
		return (-1);
	    }
	  if (testcol(nb, x, y, tab) || testsq(nb, x, y, tab))
	    {
	      nb = rand() % (10 - 2 + 1) + 1;
	      i = 9 * y - 1;
	    }
	}
    }
  /* i--; */
  /* tab[i] = nb; */
  /* afftab(tab); */
  /* usleep(10000); */
  /* printf("\n"); */
  /* tab[i] = 0; */
  return (nb);
}

void	memsetint(int *tab, int size, int nb)
{
  int	i;

  i = -1;
  while (++i < size)
    tab[i] = nb;
}

int	*generate(int dens)
{
  int	y, x;
  int	*tab;

  if ((tab = malloc(sizeof(int) * 81)) == NULL)
    return (0);
  memsetint(tab, 81, 0);
  y = -1;
  while (++y < 9)
    {
      x = -1;
      while (++x < 9)
	{
	  if ((tab[x + 9 * y] = fill(tab, x, y)) < 0)
	    {
	      if (tab[x + 9 * y] == -2)
		{
		  x = -1;
		  while (++x < 9)
		    {
		      tab[9 * y + x] = 0;
		    }
		  x = -1;
		}
	      else if (tab[x + 9 * y] == -1)
		{
		  memsetint(tab, 81, 0);
		  y = -1;
		  x = 9;
		}
	    }
	}
    }
  return (tab);
}

void	afftab(int *tab)
{
  int	i;

  i = -1;
  while (++i < 81)
    {
      if (i % 9 == 0 && i != 0)
	printf("\n");
      printf("%d ", tab[i]);
    }
  printf("\n");
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
  printf("\n");
  if (ac == 2 && atoi(av[1]) >= 17 && atoi(av[1]) <= 81)
    {
      printf("%d clues grid :\n", atoi(av[1]));
      put_res(tab, atoi(av[1]));
    }
  else
    {
      printf("error 20 clues by default\n");
      put_res(tab, 20);
    }
  afftab(tab);
}
