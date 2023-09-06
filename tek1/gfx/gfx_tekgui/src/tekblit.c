/*
** tekblit.c for blit in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:15:16 2015 Florent Baris
** Last update Sun Feb 28 16:23:47 2016 Florent Baris
*/

#include "tool.h"

void            tekblit(t_img *dest, t_img *src, t_2D *pos, t_2D *size)
{
  t_2D          tmp;
  t_2D          tmp2;
  t_f2D		rat;
  t_col         *sbuff;
  t_col         col;
  int           idx;

  sbuff = (unsigned int*)src->pixels;
  tmp.y = -1;
  rat.x = (float)src->clipable.clip_width / (float)size->x;
  rat.y = (float)src->clipable.clip_height / (float)size->y;
  while (++tmp.y < src->clipable.clip_height)
    {
      tmp.x = -1;
      while (++tmp.x < src->clipable.clip_width)
	{
	  idx = src->clipable.clip_width * tmp.y + tmp.x;
	  col = sbuff[idx];
	  tmp2.x = (int)((float)tmp.x / rat.x + (float)pos->x);
	  tmp2.y = (int)((float)tmp.y / rat.y + (float)pos->y);
	  tekpixel(dest, tmp2, col);
	}
    }
}
