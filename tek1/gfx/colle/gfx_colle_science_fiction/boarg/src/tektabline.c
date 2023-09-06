/*
** tektabline.c for lighning in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:14:28 2015 Florent Baris
** Last update Tue Apr 12 00:43:51 2016 Florent Baris
*/

#include "engine.h"

void			tektabline(t_bunny_pixelarray *img, t_bunny_position *tab,
				   unsigned int col, int n)
{
  int			i;
  t_bunny_position	p[2];

  i = -1;
  p[0] = tab[0];
  while (++i < n)
    {
      p[1] = p[0];
      p[0] = tab[i];
      line(img, p[0], p[1], col);
    }
}
