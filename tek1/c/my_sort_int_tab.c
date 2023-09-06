/*
** my_sort_in_tab.c for my_sort_in_tab in /home/baris_f/rendu/Piscine_C_J04
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Oct  6 14:32:09 2015 Florent Baris
** Last update Thu Jan 28 16:13:56 2016 Florent Baris
*/

#include "my.h"

void	cochon(int *tab, int size, int swap)
{
  int	i;

  i = 0;
  if (swap == 0)
    return ;
  while (i < size)
    {
      if (tab[i] > tab[i + 1])
	{
	  my_swap(&tab[i], &tab[i + 1]);
	  swap++;
	  cochon(tab, size, swap);
	}
      swap--;
      i++;
    }
}

void	my_sort_in_tab(int *tab, int size)
{
  cochon(tab, size, 1);
  return ;
}
