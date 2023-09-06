/*
** path.c for olf in /home/fus/rendu/CPE_2015_lemin/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sat Apr 23 18:15:15 2016 Gaspard Thirion
<<<<<<< HEAD
** Last update Mon Apr 25 21:16:55 2016 lucas duval
=======
** Last update Mon Apr 25 11:21:20 2016 lucas duval
>>>>>>> bb5fa9481b17500ed5ebc3cb498e40a33d530a56
*/

#include "lemin.h"

void		print(t_base *b)
{
  int		i;
  int		j;

  my_printf("\nPATHFINDING : \n");
  i = -1;
  while (++i < b->nb_path)
    {
      my_printf("n°%d len = %d\tpath = ", i, b->ret[i].len);
      j = -1;
      while (++j <= b->ret[i].len)
	my_printf("%d, ", b->ret[i].path[j]);
      my_printf("\n");
    }
  my_printf("\n");
}

int		add(t_base *b, int i, int *path, int a)
{
  int		j;

  if (path[a] != b->end)
    path[++a] = b->end;
  if ((b->ret =
       my__realloc(b->ret, sizeof(t_ret) * (i + 2), sizeof(t_ret) * (i + 1)))
      == NULL
      || (b->ret[i].path = malloc(sizeof(int) * (a + 1))) == NULL)
    return (-1);
  b->ret[i].len = a;
  j = -1;
  while (++j <= a)
    b->ret[i].path[j] = path[j];
  return (0);
}

int		chkprev(t_base *b, int *prev, int cur, int max)
{
  int		i;

  i = -1;
  while (++i < b->node[b->start].nb_link && cur != b->end)
    if (cur == (b->node[b->start].link[i]))
      return (0);
  i = -1;
  while (++i <= max)
    if (cur == prev[i] && cur != b->end)
      return (0);
  return (1);
}

int		loop(t_base *b, int *prev, int *p, int cur)
{
  t_node	*tmp;

  if (chkprev(b, prev, cur, *p))
    prev[++(*p)] = cur;
  if (cur == b->end)
    return (-2);
  tmp = &(b->node[cur]);
  while (!chkprev(b, prev, tmp->link[tmp->mem], *p))
    {
      tmp->mem += 1;
      if (tmp->mem >= tmp->nb_link)
	  return (-1);
    }
  return (tmp->link[tmp->mem]);
}

int		path(t_base *b, int p, int i)
{
  int		*prev;
  int		*path;
  int		a;
  int		r;

  if ((b->ret = malloc(sizeof(t_ret))) == NULL
      || (prev = malloc(sizeof(int) * (b->nb_node + 1))) == NULL
      || (path = malloc(sizeof(int) * (b->nb_node + 1))) == NULL)
    return (-1);
  prev[++p] = (path[0] = b->start);
  while (b->node[b->start].mem < b->node[b->start].nb_link)
    {
      a = 0;
      r = b->node[b->start].link[b->node[b->start].mem];
      while (r != -2 && r != -1)
	  r = loop(b, prev, &p, (path[++a] = r));
      if (r == -2)
	add(b, ++i, path, a);
      b->node[b->start].mem += 1;
    }
  b->nb_path = i + 1;
  free(prev);
  free(path);
  return (0);
}
