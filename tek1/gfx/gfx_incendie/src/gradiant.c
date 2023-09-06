/*
** gradiant.c for gradiant in /home/baris-f/rendu/gfx_incendie
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Dec  5 22:47:19 2015 Florent Baris
** Last update Sun Dec  6 22:39:28 2015 Florent Baris
*/

 #include <lapin.h>
 #include <unistd.h>
 #include "../my_lap.h"

t_abgr		toabgr(unsigned int color)
{
  t_abgr	ret;

  ret.a = (color & 0xFF000000);
  ret.b = (color & 0xFF0000);
  ret.g = (color & 0xFF00);
  ret.r = (color & 0xFF);
  return (ret);
}

unsigned int	tohex(t_abgr color)
{
  unsigned int	ret;

  ret = 0;
  ret += color.a & 0xFF000000;
  ret += color.b & 0xFF0000;
  ret += color.g & 0xFF00;
  ret += color.r & 0xFF;
  return (ret);
}

void		setcolors(unsigned int *col, int nb, unsigned int *colors)
{
  t_abgr	first;
  t_abgr	last;
  t_abgr	cur;
  int		i;
  int		dr;
  int		dg;
  int		db;

  i = -1;
  first = toabgr(col[0]);
  last = toabgr(col[1]);
  cur = last;
  db = (last.b - first.b) / nb;
  dg = (last.g - first.g) / nb;
  dr = (last.r - first.r) / nb;
  while (++i < nb)
    {
      colors[nb - i - 1] = tohex(cur);
      cur.b += db;
      cur.g += dg;
      cur.r += dr;
    }
}
