/*
** astar.c for sdùs in /home/fus/taff/tmp/dante/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu May 26 01:01:30 2016 Gaspard Thirion
** Last update Thu May 26 03:27:01 2016 Gaspard Thirion
*/

#include "dante.h"

void		initast(t_ast *node, int max, int aff)
{
  int           i;

  i = -1;
  while (++i < max)
    if (aff && node[i].k != -1)
      my_printf("node[%d] : k = %d, i = %d\n", i, node[i].k, node[i].i);
    else
      {
	node[i].i = -1;
	node[i].k = -1;
      }
}

void	parsenode(t_maz *maz, int cur, t_ast *node, int sofar)
{
  int	i;
  int	dir;
  int	x;
  int	y;

  i = -1;
  while (++i < 4)
    {
      dir = 0;
      dir = (i == 3) ? (-maz->x) : (i == 0) ? (maz->x) : (i == 2) ? (-1) : (1);
      if (GET(maz->map[cur], CAN_DOWN + i)
    	  && !GET(maz->map[cur + dir], KO)
    	  && !GET(maz->map[cur + dir], LOCK))
	{
	  y = (cur + dir) / (maz->x);
	  x = cur + dir - y * maz->x;
	  y -= (maz->y - 1);
	  x -= (maz->x - 1);
	  addnode(node, ABS(x) + ABS(y), cur + dir, sofar);
	  SET(maz->map[cur + dir], LOCK);
	  SET(maz->map[cur + dir], 3 - i + PREV_DOWN);
	}
    }
}

int	getbestnode(t_ast *node, int max, int *sofar)
{
  int	i;
  int	min;
  int	imin;

  min = max;
  imin = 0;
  i = -1;
  while (++i < max)
    if (node[i].k == max - 1)
      return (max - 1);
    else if (node[i].k != -1 && node[i].k + node[i].sofar< min)
      {
	min = node[i].k + node[i].sofar;
	imin = i;
      }
  min = node[imin].i;
  *sofar = node[imin].sofar;
  node[imin].k = -1;
  return (min);
}

int	solver(t_maz *maz, int v)
{
  int	cur;
  int	sofar;
  t_ast	*node;

  if ((node = malloc(sizeof(t_ast) * maz->size)) == NULL)
    return (-1);
  initast(node, maz->size, 0);
  sofar = 0;
  cur = 0;
  while (cur < maz->size - 1)
    {
      SET(maz->map[cur], KO);
      UNSET(maz->map[cur], LOCK);
      parsenode(maz, cur, node, sofar);
      if ((cur = getbestnode(node, maz->size, &sofar)) <= 0)
      	return (-4);
      if (VVERB)
	initast(node, maz->size, 1);
      (v) ? (affmaz(maz, 1)) : (0);
    }
  clean(maz, maz->size - 1, v);
  free(node);
  return (0);
}
