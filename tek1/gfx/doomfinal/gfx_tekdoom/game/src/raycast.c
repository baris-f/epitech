/*
** raycast.c for dmm in /home/fus/tmp/2plaquage/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Jan 19 22:11:08 2016 Gaspard Thirion
** Last update Mon Jan 25 11:05:59 2016 Gaspard Thirion
*/

#include "tool.h"

int		is_wall(t_base *base, int x, int y, t_col *col)
{
  t_col		*buff;
  t_col		tmpcol;

  buff = (t_col*)base->prs[1].img->pixels;
  if (x < 0 || y < 0
      || x >= base->prs[1].img->clipable.clip_width
      || y >= base->prs[1].img->clipable.clip_height)
    {
      *col = RED;
    return (2);
    }
  tmpcol = buff[x + y * base->prs[1].img->clipable.clip_width];
  if (tmpcol == (t_col)DF_GR_COL)
    {
      *col = PINK;
      return (0);
    }
  *col = tmpcol;
  return (1);
}

t_f2D		chk_hori(t_base *base, t_f3D pos, float ang, t_col *col)
{
  t_f2D		tmp;
  t_f2D		delta;
  int		ret;

  if (ang <= 0 || (ang >= M_PI && ang <= DOUBLE))
    {
      tmp.y = (int)(pos.y / UNIT) * UNIT + UNIT;
      delta.y = UNIT;
    }
  else
    {
      tmp.y = (int)(pos.y / UNIT) * UNIT;
      delta.y = -UNIT;
    }
  tmp.x = pos.x + (pos.y - tmp.y) / tan(ang);
  delta.x = -delta.y / tan(ang);
  while ((ret = is_wall(base, tmp.x, tmp.y +
			(((ang <= 0 || (ang >= M_PI && ang <= DOUBLE)))
			 ? (0) : (delta.y)) , col)) == 0)
    {
      tmp.x += delta.x;
      tmp.y += delta.y;
    }
  (ret == 2) ? (tmp.x = 100000) : (0);
  (ret == 2) ? (tmp.y = 100000) : (0);
  return (tmp);
}

t_f2D		chk_verti(t_base *base, t_f3D pos, float ang, t_col *col)
{
  t_f2D		tmp;
  t_f2D		delta;
  int		ret;

  if (ang < MID || ang > DWN_PI)
    {
      tmp.x = (int)(pos.x / UNIT) * UNIT + UNIT;
      delta.x = UNIT;
    }
  else
    {
      tmp.x = (int)(pos.x / UNIT) * UNIT;
      delta.x = -UNIT;
    }
  tmp.y = pos.y + (pos.x - tmp.x) * tan(ang);
  delta.y = -delta.x * tan(ang);
  while ((ret = is_wall(base, tmp.x + ((ang < MID || ang > DWN_PI)
				       ? (0) : (delta.x)), tmp.y, col)) == 0)
    {
      tmp.x += delta.x;
      tmp.y += delta.y;
    }
  (ret == 2) ? (tmp.x = 100000) : (0);
  (ret == 2) ? (tmp.y = 100000) : (0);
  return (tmp);
}
