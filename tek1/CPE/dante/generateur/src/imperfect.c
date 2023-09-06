/*
** imperfect.c for dante in /home/baris-f/rendu/CPE/dante/generateur
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun May 22 16:48:29 2016 Florent Baris
** Last update Fri May 27 12:07:38 2016 Florent Baris
*/

#include "dante.h"

int		iempty(t_maz *maz, int stat)
{
  int		i;
  int		nb;

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
      imperfect(maz);
    }
  return (0);
}

int		ifinalize(t_maz *maz, int f)
{
  int		i;
  int		k;

  maz->seed++;
  k = 0;
  i = -1;
  iempty(maz, PRCT);
  while (!f &&
	 ++i < maz->size)
    if (maz->tab[i] == 'I')
      k++;
  if (f
      && ((k = initmaz(maz)) < 0 || (k = imperfect(maz)) < 0))
    return (k);
  return (0);
}

int		icheck(int prev, int cell, t_maz *maz, int dir)
{
  if (maz->tab[cell] != '*')
    return (0);
  if (cell - maz->x != prev && cell - maz->x >= 0
      && maz->tab[cell - maz->x] != '*')
    if (dir == 2 || dir == 0)
      return (0);
  if (cell + maz->x != prev && cell + maz->x < maz->size
      && maz->tab[cell + maz->x] != '*')
    if (dir == 2 || dir == 0)
      return (0);
  if (cell - 1 != prev && cell - 1 >= 0 && cell % maz->x != 0
      && maz->tab[cell - 1] != '*')
    if (dir == 1 || dir == 3)
      return (0);
  if (cell + 1 != prev && cell + 1 < maz->size && (cell + 1) % maz->x != 0
      && maz->tab[cell + 1] != '*')
    if (dir == 1 || dir == 3)
      return (0);
  return (1);
}

int		inext(int cur, t_maz *maz)
{
  int		can[4];
  int		i;

  i = -1;
  if (cur - maz->x >= 0 && icheck(cur, cur - maz->x, maz, 3))
    can[++i] = cur - maz->x;
  if (cur + maz->x < maz->size && icheck(cur, cur + maz->x, maz, 1))
    can[++i] = cur + maz->x;
  if (cur - 1 >= 0 && cur % maz->x != 0
      && icheck(cur, cur - 1, maz, 2))
    can[++i] = cur - 1;
  if (cur + 1 < maz->size && (cur + 1) % maz->x != 0
      && icheck(cur, cur + 1, maz, 0))
    can[++i] = cur + 1;
  if (i == -1)
    return (-1);
  return (can[mrand(0, 100, 0) % (i + 1)]);
}

int		imperfect(t_maz *maz)
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
	return (ifinalize(maz, 0));
      maz->tab[cur] = 'P';
      if ((r = inext(cur, maz)) == -1)
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
  return (ifinalize(maz, 0));
}
