/*
** solver.c for k in /home/fus/taff/dante/parser/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed May 18 22:49:27 2016 Gaspard Thirion
** Last update Thu May 19 23:28:35 2016 Gaspard Thirion
*/

#include "dante.h"

int		getnext(t_maz *maz, int *i)
{
  t_mask	m;
  int		j;

  m = CAN_DOWN - 1;
  while (++m <= CAN_UP)
    if (GET(maz->map[*i], m))
      {
	UNSET(maz->map[*i], m);
	j = *i + ((m == CAN_UP) ? (-maz->x) : (m == CAN_DOWN) ? (maz->x)
		  : (m == CAN_LEFT) ? (-1) : (m == CAN_RIGHT) ? (1) : (0));
	if (!GET(maz->map[j], OK) && !GET(maz->map[j], KO))
	  {
	    *i = j;
	    UNSET(maz->map[*i], ((m == CAN_UP) ? (CAN_DOWN) : (m == CAN_DOWN)
				 ? (CAN_UP) : (m == CAN_LEFT) ? (CAN_RIGHT)
				 : (CAN_LEFT)));
	    SET(maz->map[*i], ((m == CAN_UP) ? (PREV_DOWN) : (m == CAN_DOWN)
			       ? (PREV_UP)
			       : (m == CAN_LEFT) ? (PREV_RIGHT) : (PREV_LEFT)));
	    return (0);
	  }
      }
  return (-1);
}

void		loop(t_maz *maz, int *i)
{
  if (getnext(maz, i) == -1)
    {
      SET(maz->map[*i], KO);
      (*i) += GET(maz->map[*i], PREV_UP) ? (-maz->x)
	: GET(maz->map[*i], PREV_DOWN) ? (maz->x)
	: GET(maz->map[*i], PREV_LEFT) ? (-1)
	: GET(maz->map[*i], PREV_RIGHT) ? (1)
	: (0);
    }
  SET(maz->map[*i], OK);
}

int		solver(t_maz *maz, int v)
{
  int		cur;

  cur = 0;
  SET(maz->map[cur], OK);
  while (42)
    {
      loop(maz, &cur);
      if (cur == 0)
	return (-4);
      else if (cur == maz->size - 1)
	return (0);
      if (v)
	affmaz(maz, 1);
    }
  return (-4);
}
