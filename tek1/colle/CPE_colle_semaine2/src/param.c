/*
** param.c for tree in /home/baris-f/rendu/colle/CPE_colle_semaine1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Apr 27 15:55:30 2016 Florent Baris
** Last update Wed May  4 18:23:24 2016 Florent Baris
*/

#include "p4.h"

int	check_param(t_p4 *p4, t_tmp *tmp)
{
  (void)tmp;
  if (check_nbr(p4->size.x, p4->size.y, p4) == -1)
    return (-1);
  if (check_avatar(p4, p4->p1, p4->p2) == -1)
    return (-1);
  if (check_arb(p4->end, p4) == -1)
    return (-1);
  return (0);
}

int	init_tmp_param(t_p4 *p4, char **av, t_tmp *tmp, int i)
{
  if (av[i][1] == 'w')
    {
      tmp->x = my_getnbr(av[i + 1]);
      if (check_nbr(tmp->x, p4->size.y, p4) != -1)
	p4->size.x = tmp->x;
    }
  if (av[i][1] == 'h')
    tmp->y = my_getnbr(av[i + 1]);
  if (av[i][1] == 'p' && av[i][1] == '1')
    {
      tmp->p1 = av[i + 1][0];
      if (check_avatar(p4, p4->p1, p4->p2) == -1)
	p4->p1 = tmp->p1;
    }
  if (av[i][1] == 'p' && av[i][1] == '2')
    tmp->p2 = av[i + 1][0];
  if (av[i][1] == 'a')
    tmp->end = av[i + 1][0];
  if (av[i][1] == 'i' && av[i][1] == 'a')
    p4->ia = 1;
  return (0);
}

int     param(t_p4 *p4, int ac, char **av)
{
  t_tmp	tmp;
  int   i;

  i = 1;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  if (init_tmp_param(p4, av, &tmp, i) != -1)
	    i++;
	}
      i++;
    }
  return (0);
}
