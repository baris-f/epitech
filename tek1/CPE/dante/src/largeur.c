/*
** largeur.c for  in /home/fus/taff/dante/parser
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu May 19 01:16:29 2016 Gaspard Thirion
** Last update Thu May 26 03:27:57 2016 Gaspard Thirion
*/

#include "dante.h"

void		loop(t_maz *maz, int *list, int (*cur), int (*nxt))
{
  if (GET(CUR, CAN_DOWN) && !GET(maz->map[list[(*cur)] + maz->x], KO))
    {
      list[++(*nxt)] = list[(*cur)] + maz->x;
      SET(maz->map[list[*nxt]], PREV_UP);
      SET(maz->map[list[*nxt]], KO);
    }
  if (GET(CUR, CAN_RIGHT) && !GET(maz->map[list[(*cur)] + 1], KO))
    {
      list[++(*nxt)] = list[(*cur)] + 1;
      SET(maz->map[list[*nxt]], PREV_LEFT);
      SET(maz->map[list[*nxt]], KO);
    }
  if (GET(CUR, CAN_LEFT) && !GET(maz->map[list[(*cur)] - 1], KO))
    {
      list[++(*nxt)] = list[(*cur)] - 1;
      SET(maz->map[list[*nxt]], PREV_RIGHT);
      SET(maz->map[list[*nxt]], KO);
    }
  if (GET(CUR, CAN_UP) && !GET(maz->map[list[(*cur)] - maz->x], KO))
    {
      list[++(*nxt)] = list[(*cur)] - maz->x;
      SET(maz->map[list[*nxt]], PREV_DOWN);
      SET(maz->map[list[*nxt]], KO);
    }
}

int	solver(t_maz *maz, int v)
{
  int	*list;
  int	i;
  int	cur;
  int	nxt;

  if ((list = malloc(sizeof(int) * maz->size)) == NULL)
    return (-1);
  i = 0;
  list[i] = 0;
  while (++i < maz->size)
    list[i] = -1;
  cur = -1;
  nxt = 0;
  while (list[++cur] != maz->size - 1)
    {
      if (cur >= maz->size)
	return (-4);
      SET(maz->map[list[cur]], KO);
      if (v)
	affmaz(maz, 1);
      loop(maz, list, &cur, &nxt);
    }
  clean(maz, maz->size - 1, v);
  free(list);
  return (0);
}
