/*
** fillmap.c for fillmap in /home/baris-f/rendu/gfx/gfx_tekdoom/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Jan 19 00:21:43 2016 Florent Baris
** Last update Tue Jan 19 00:23:12 2016 Florent Baris
*/

#include "../inc/wolf.h"

void    square(t_base *pass, t_2D pos, t_col col)
{
  t_2D  cur;

  cur.y = pos.y;
  while (++cur.y <= pos.y + pass->edit.scale)
    {
      cur.x = pos.x;
      if (cur.y > 0 - pass->edit.scale && cur.y < WIN_H)
	while (++cur.x <= pos.x + pass->edit.scale)
	  if (cur.x > 0 - pass->edit.scale && cur.x < WIN_W)
	    tekpixel(pass->img, cur, col);
    }
}

void            fillmap(t_base *pass, t_img *map)
{
  int           i;
  int           width;
  int           height;
  int           whalf;
  int           hhalf;
  unsigned int  *buff;
  t_2D          pos;

  buff = (t_col *)map->pixels;
  width = map->clipable.clip_width;
  height = map->clipable.clip_height;
  whalf = width * pass->edit.scale / 2;
  hhalf = height * pass->edit.scale / 2;
  i = -1;
  while (++i < width * height)
    {
      pos.x = (pass->edit.center.x - whalf) + (i % width) * pass->edit.scale;
      pos.y = (pass->edit.center.y - hhalf) + (i / width) * pass->edit.scale;
      square(pass, pos, buff[i]);
    }
}
