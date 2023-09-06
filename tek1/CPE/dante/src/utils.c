/*
** mrand.c for  in /home/fus/taff/dante/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue May  3 21:29:37 2016 Gaspard Thirion
** Last update Thu May 26 03:15:10 2016 Gaspard Thirion
*/

#include "dante.h"

void		verbose(t_maz *maz)
{
  int		j;

  write(1, "\n", 1);
  j = -1;
  while (++j < TIME);
  j = -1;
  while (++j < maz->x)
    write(1, "#", 1);
}

int		affmaz(t_maz *maz, int opt)
{
  int		i;

  i = -1;
  while (++i < maz->size)
    {
      if (i != 0 && i % maz->x == 0)
	write(1, "\n", 1);
      if (opt)
	write(1,  GET(maz->map[i], LOCK) ? ("I") : (GET(maz->map[i], KO)) ?
	      ("X") : (GET(maz->map[i], OK)) ? ("o") :
	      (GET(maz->map[i], FREE)) ? (".") :(" "), 1);
      else
 	write(1, (GET(maz->map[i], OK) && GET(maz->map[i], KO) == 0)
	      ? ("o") : (GET(maz->map[i], FREE)) ? ("*") : ("X"), 1);
    }
  if (opt)
    verbose(maz);
  write(1, "\n", 1);
  return (0);
}

void		clean(t_maz *maz, int i, int v)
{
  while (i != 0)
    {
      SET(maz->map[i], OK);
      UNSET(maz->map[i], KO);
      UNSET(maz->map[i], LOCK);
      i += GET(maz->map[i], PREV_UP) ? (-maz->x)
	: GET(maz->map[i], PREV_DOWN) ? (maz->x)
	: GET(maz->map[i], PREV_LEFT) ? (-1)
	: GET(maz->map[i], PREV_RIGHT) ? (1)
	: (0);
      if (v)
	affmaz(maz, 1);
    }
  SET(maz->map[i], OK);
  UNSET(maz->map[i], KO);
}

void		addnode(t_ast *node, int k, int idx, int sofar)
{
  int	i;

  i = -1;
  while (node[++i].k != -1)
    if (node[i].i == idx)
	return;
  node[i].k = k;
  node[i].i = idx;
  node[i].sofar = sofar + 1;
}
