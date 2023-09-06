/*
** main.c for djo in /home/fus/rendu/cpe/CPE_2015_lemin
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Mar 31 15:32:49 2016 Gaspard Thirion
** Last update Mon Apr 25 21:16:40 2016 lucas duval
*/

#include "lemin.h"
int	main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
  t_base        base;

  if (get_line(&base))
    return (42);
  if (base.nb_node == 1 || base.nb_node == 0)
    {
      my_printf("Erreur no room\n");
      return (42);
    }
  if (path(&base, -1, -1) == -1)
    return (42);
  final(&base);
  return (0);
}

void	print_debug(t_base *base)
{
  int	j;
  int	i;

  j = -1;
  my_printf("Start : %d\nEnd : %d", base->start, base->end);
  printf("\n\n\n\n");
  while (++j < base->nb_node)
    {
      i = -1;
      my_printf("index: %d | nom : %s coord: x: %d - y: %d\n{ ", j,
		base->node[j].name, base->node[j].pos.x, base->node[j].pos.y);
      while (++i < base->node[j].nb_link)
	my_printf("%d ", base->node[j].link[i]);
      my_printf("}\n");
    }
}
