/*
** path.c for olf in /home/fus/rendu/CPE_2015_lemin/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sat Apr 23 18:15:15 2016 Gaspard Thirion
<<<<<<< HEAD
** Last update Mon Apr 25 12:14:27 2016 Gaspard Thirion
=======
** Last update Mon Apr 25 11:21:20 2016 lucas duval
>>>>>>> bb5fa9481b17500ed5ebc3cb498e40a33d530a56
*/

#include "lemin.h"

void		print(t_base *b)
{
  int		i;
  int		j;

  i = -1;
  while (++i < b->nb_path)
    {
      my_printf("n°%d len = %d\tpath = ", i, b->ret[i].len);
      j = -1;
      while (++j <= b->ret[i].len)
	my_printf("%d, ", b->ret[i].path[j]);
      my_printf("\n");
    }
}

int		add(t_base *b, int p, int i, int *prev)
{
  int		j;

  if ((b->ret =
       my__realloc(b->ret, sizeof(t_ret) * (i + 2), sizeof(t_ret) * (i + 1)))
      == NULL
      || (b->ret[i].path = malloc(sizeof(int) * (p + 1))) == NULL)
    return (-1);
  b->ret[i].len = p;
  j = -1;
  while (++j < p)
    b->ret[i].path[j] = prev[j];
  b->ret[i].path[j] = b->end;
  return (0);
}

int		chkprev(int *prev, int cur, int max)
{
  int		i;

  i = -1;
  while (++i < max)
    if (cur == prev[i])
      return (0);
  return (1);
}

int		loop(t_base *b, int *prev, int *p, int i)
{
  t_node	*tmp;

  tmp = &b->node[prev[*p]];
  if (!i)
    {
      if (chkprev(prev, tmp->link[tmp->mem], *p + 1))
	prev[++(*p)] = tmp->link[tmp->mem];
      else
	(tmp->mem)++;
    }
  while (*p >= 0 && (i || tmp->mem >= tmp->nb_link))
    {
      tmp->mem = 0;
      i = 0;
      if (*p - 1 < 0)
	return (0);
      ((tmp = &b->node[prev[--(*p)]])->mem)++;
    }
  return (1);
}

int		path(t_base *b, int lim)
{
  int		*prev;
  int		p;
  t_2D		i;

  if ((b->ret = malloc(sizeof(t_ret) * 10)) == NULL
      ||(prev = malloc(sizeof(int) * b->nb_node)) ==  NULL)
    return (-1);
  prev[p = 0] = b->start;
  i.y = 1;
  i.x = -1;
  while (i.y)
    if (p > lim)
      i.y = loop(b, prev, &p, 1);
    else if (prev[p] == b->end)
      {
	if (add(b, p, ++(i.x), prev) == -1)
	  return (-1);
	i.y = loop(b, prev, &p, 1);
      }
    else
      i.y = loop(b, prev, &p, 0);
  b->nb_path = i.x + 1;
  free(prev);
  print(b);
  return (0);
}
