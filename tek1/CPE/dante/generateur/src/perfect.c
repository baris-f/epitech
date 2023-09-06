/*
** perfect.c for  in /home/fus/taff/dante/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue May  3 22:07:28 2016 Gaspard Thirion
** Last update Fri Jun  3 12:22:19 2016 Florent Baris
*/

#include "dante.h"

int		empty(t_maz *maz, int stat)
{
  int           i;
  int           nb;

  i = -1;
  nb = 0;
  while (++i < maz->size)
    if (maz->tab[i] == '*')
      nb++;
  if ((int)((float)nb / (float)maz->size * (float)100) > stat)
    {
      i = -1;
      while (++i < maz->size)
	maz->tab[i] = '*';
      perfect(maz);
    }
  return (0);
}

int		finalize(t_maz *maz, int f)
{
  int		i;
  int		k;

  /* maz->seed++; */
  k = 0;
  i = -1;
  empty(maz, PRCT);
  while (!f &&
	 ++i < maz->size)
    if (maz->tab[i] == 'I')
      k++;
  if (f
      && ((k = initmaz(maz)) < 0 || (k = perfect(maz)) < 0))
    return (k);
  return (0);
}

int		check(int prev, int cell, t_maz *maz)
{
  if (maz->tab[cell] != '*')
    return (0);
  if (cell - maz->x != prev && cell - maz->x >= 0
      && maz->tab[cell - maz->x] != '*')
    return (0);
  if (cell + maz->x != prev && cell + maz->x < maz->size
      && maz->tab[cell + maz->x] != '*')
    return (0);
  if (cell - 1 != prev && cell - 1 >= 0 && cell % maz->x != 0
      && maz->tab[cell - 1] != '*')
    return (0);
  if (cell + 1 != prev && cell + 1 < maz->size && (cell + 1) % maz->x != 0
      && maz->tab[cell + 1] != '*')
    return (0);
  return (1);
}

int		next(int cur, t_maz *maz)
{
  int		can[4];
  int		i;

  i = -1;
  if (cur - maz->x >= 0 && check(cur, cur - maz->x, maz))
    can[++i] = cur - maz->x;
  if (cur + maz->x < maz->size && check(cur, cur + maz->x, maz))
    can[++i] = cur + maz->x;
  if (cur - 1 >= 0 && cur % maz->x != 0
      && check(cur, cur - 1, maz))
    can[++i] = cur - 1;
  if (cur + 1 < maz->size && (cur + 1) % maz->x != 0
      && check(cur, cur + 1, maz))
    can[++i] = cur + 1;
  if (i == -1)
    return (-1);
  return (can[mrand(0, 100, 0) % (i + 1)]);
}

int		perfect(t_maz *maz)
{
  int		cur;
  int		p;
  int		r;

  cur = 0;
  p = 0;
  if (maz->x < 4 || maz->y < 4)
    return (write(1, "nope\n", 5) * 0 - 1);
  while (cur != maz->size - 1)
    {
      if (p < 0)
	return (finalize(maz, 0));
      maz->tab[cur] = 'P';
      if ((r = next(cur, maz)) == -1)
	{
	  maz->tab[cur] = 'I';
	  cur = maz->prev[p];
	  --p;
	}
      else
	{
	  maz->prev[++p] = cur;
	  cur = r;
	}
    }
  return (finalize(maz, 0));
}
