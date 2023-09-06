/*
** toolbar.c for toolbar in /home/baris-f/rendu/gfx/gfx_tekdoom/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Jan 19 00:24:23 2016 Florent Baris
** Last update Mon Apr 11 11:51:50 2016 Florent Baris
*/

#include "engine.h"

void	draw_box(t_img *img, t_2D *pos, t_col col, int full)
{
  t_2D	cur;
  t_2D	max;
  t_2D	empty[5];

  if (full == 0)
    {
      empty[0] = pos[0];
      empty[1].x = pos[1].x;
      empty[1].y = pos[0].y;
      empty[2] = pos[1];
      empty[3].x = pos[0].x;
      empty[3].y = pos[1].y;
      empty[4] = pos[0];
      tektabline(img, empty, col, 5);
	return ;
    }
  max.x = MAX(pos[0].x, pos[1].x);
  max.y = MAX(pos[0].y, pos[1].y);
  cur.x = (MIN(pos[0].x, pos[1].x)) - 1;
  while (++cur.x <= max.x)
    {
      cur.y = (MIN(pos[0].y, pos[1].y)) - 1;
      while (++cur.y <= max.y)
	tekpixel(img, cur, col);
    }
}
