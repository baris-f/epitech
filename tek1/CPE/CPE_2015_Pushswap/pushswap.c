/*
** pushswap.c for pushswap in /home/baris_f/rendu/CPE_year_Pushswap
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov  2 18:41:58 2015 Florent Baris
** Last update Sun Nov 22 19:19:03 2015 Florent Baris
*/

#include <stdlib.h>

void    swap(int *tab)
{
  int  tmp;

  my_putstr("sa ");
  tmp = tab[0];
  tab[0] = tab[1];
  tab[1] = tmp;
}

void    rotate(int *tab, int ac, int aff)
{
  int   i;
  int   j;
  int   tmp;

  if (aff == 1)
    my_putstr("ra");
  i = -1;
  while (++i < ac - 1);
  tmp = tab[0];
  j = -1;
  while (++j < i)
    tab[j] = tab[j + 1];
  tab[i - 1] = tmp;
}

void	bubble(int ac, int *l_a)
{
  int	i;
  int	swop;

  swop = 1;
  while (swop == 1)
    {
      i = 0;
      swop = 0;
      while (i < ac - 2)
	{
	  if (l_a[0] > l_a[1] && i != ac - 1)
	    {
	      swop = 1;
	      swap(l_a);
	    }
	  rotate(l_a, ac, 1);
	  my_putchar(' ');
	  i++;
	}
      rotate(l_a, ac, 1);
      if (swop == 1)
	my_putchar(' ');
    }
}

int	check(int ac, int *l_a)
{
  int   i;

  i = -1;
  while (++i < ac - 2)
    {
      if (l_a[0] > l_a[1] && i != ac - 1)
	return (1);
      rotate(l_a, ac, 0);
    }
  return (0);
}

int	main(int ac, char **av)
{
  int	*l_a;
  int	i;
  int	swop;

  if ((l_a = malloc(sizeof(int) * (ac - 1))) == NULL)
    return (0);
  i = -1;
  while (++i < ac)
    l_a[i - 1] = my_getnbr(av[i]);
  if (check(ac, l_a))
    bubble(ac, l_a);
  free(l_a);
  my_putchar('\n');
  return (0);
}
