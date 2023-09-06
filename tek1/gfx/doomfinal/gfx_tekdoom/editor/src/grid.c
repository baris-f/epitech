/*
** grid.c for grid in /home/baris-f/rendu/gfx/gfx_tekdoom/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Jan 14 16:51:28 2016 Florent Baris
** Last update Tue Jan 19 00:22:40 2016 Florent Baris
*/

#include "../inc/wolf.h"

void    grid(t_base *pass)
{
  int   whalf;
  int   hhalf;
  t_2D	max;
  t_2D  p;

  whalf = pass->edit.map->clipable.clip_width * pass->edit.scale / 2;
  hhalf = pass->edit.map->clipable.clip_height * pass->edit.scale / 2;
  p.x = pass->edit.center.x - whalf - pass->edit.scale;
  while ((p.x += pass->edit.scale) <= pass->edit.center.x + whalf)
    {
      (WIN_HH - hhalf - (WIN_HH - pass->edit.center.y) > 0) ?
	(p.y = WIN_HH - hhalf - (WIN_HH - pass->edit.center.y)) : (p.y = -1);
      (WIN_HH + hhalf - (WIN_HH - pass->edit.center.y) < WIN_H - 1) ?
	(max.y = WIN_HH + hhalf - (WIN_HH - pass->edit.center.y)) :
	(max.y = WIN_H - 1);
      if (p.x < WIN_W - 1)
	while (++p.y <= max.y)
	  tekpixel(pass->img, p, BLACK);
    }
  p.y = pass->edit.center.y - hhalf - pass->edit.scale;
  while ((p.y += pass->edit.scale) <= pass->edit.center.y + hhalf)
    {
      (WIN_WH - whalf - (WIN_WH - pass->edit.center.x) > 0) ?
	(p.x = WIN_WH - whalf - (WIN_WH - pass->edit.center.x) - 1) : (p.x = -1);
      (WIN_WH + whalf - (WIN_WH - pass->edit.center.x) < WIN_W - 1) ?
	(max.x = WIN_WH + whalf - (WIN_WH - pass->edit.center.x)) :
	(max.x = WIN_W - 1);
      if (p.y < WIN_H - 1)
	while (++p.x <= max.x)
	  tekpixel(pass->img, p, BLACK);
    }
}
