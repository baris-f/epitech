/*
** my_param_to_tab.c for my_param_to_tab in /home/baris_f/rendu/Piscine_C_J09/ex_03
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Oct  8 12:43:50 2015 Florent Baris
** Last update Fri Oct  9 23:38:28 2015 Florent Baris
*/

#include <stdlib.h>

t_stock_par	*my_param_to_tab(int ac, char **av)
{
  int	       	i;
  t_stock_par	*stock;
  t_stock_par	tab[ac - 1];

  i = 0;
  while (i < ac)
    {
      stock = malloc(sizeof(t_stock_par));
      if (stock == NULL)
	return (NULL);
      stock -> size_param = my_strlen(av[i]);
      stock -> str = av[i];
      stock -> copy = my_strdup(av[i]);
      stock -> tab = my_str_to_wordtab(av[i]);
      tab[i] = *stock;
      i++;
    }
  return (tab);
}
