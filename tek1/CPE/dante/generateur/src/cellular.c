/*
** materea.c for  in /home/fus/taff/dante/mazgen/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue May 17 12:30:45 2016 Gaspard Thirion
** Last update Thu May 19 18:52:14 2016 Gaspard Thirion
*/

#include "dante.h"

void		initgrid(t_maz *maz, int *tmp, int init)
{
  int		i;

  i = -1;
  if (init)
    while (++i < maz->size)
      {
	if (mrand(0, 100, 0) < INITIAL_CHANCE)
	  maz->tab[i] = 'P';
	tmp[i] = maz->tab[i];
      }
  else
    while (++i < maz->size)
      maz->tab[i] = tmp[i];
}

int		countcell(t_maz *maz, int cell)
{
  int		k;
  int		x;
  int		y;

  k = 0;
  y = cell / maz->x - 2;
  while (++y < cell / maz->x + 2)
    {
      x = cell - maz->x * (cell / maz->x) - 2;
      while (++x < cell - maz->x * (cell / maz->x) + 2)
	if (x + y * maz->x != cell
	   && (x < 0 || x >= maz->x || y < 0 || y >= maz->y
	       || maz->tab[x + y * maz->x] == '*'))
	  k++;
    }
  return (k);
}

void		finishgrid(t_maz *maz)
{
  int		i;

  i = 0;
  while (maz->tab[i] && maz->tab[i] != 'P')
    {
      maz->tab[i] = 'P';
      maz->tab[i + 1] = 'P';
      i += 1;
      i += maz->x;
    }
  i = maz->size - 1;
  while (maz->tab[i] && maz->tab[i] != 'P')
    {
      maz->tab[i] = 'P';
      maz->tab[i - 1] = 'P';
      i -= 1;
      i -= maz->x;
    }
}

int		cellular(t_maz *maz)
{
  int		*tmp;
  int		i;
  int		n;
  int		cnt;

  if ((tmp = malloc(sizeof(int) * maz->size)) == NULL)
    return (-1);
  initgrid(maz, tmp, 1);
  n = -1;
  while (++n < NB_TURN)
    {
      i = -1;
      while (++i < maz->size)
	{
	  cnt = countcell(maz, i);
	  if (maz->tab[i] == '*')
	    tmp[i] = (cnt < KILL_LIM) ? ('P') : ('*');
	  else if (maz->tab[i] == 'P')
	    tmp[i] = (cnt > BIRTH_LIM) ? ('*') : ('P');
	}
      initgrid(maz, tmp, 0);
    }
  finishgrid(maz);
  return (0);
}
