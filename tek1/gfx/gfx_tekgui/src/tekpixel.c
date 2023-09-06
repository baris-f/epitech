/*
** tekpixel.c for tekpixel in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:14:42 2015 Florent Baris
** Last update Wed Feb  3 21:38:05 2016 Florent Baris
*/

#include "tool.h"

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position pos,
				  unsigned int col)
{
  unsigned int          *buff;
  int                   idx;
  float                 alpha;
  unsigned int          tmpcol;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos.y + pos.x;
  alpha = ((col & 0xFF000000) >> 24);
  if (pos.x < 0 || pos.y < 0
      || pos.x > img->clipable.clip_width
      || pos.y > img->clipable.clip_height)
    return;
  if (alpha != 255)
    {
      alpha = alpha / 255;
      tmpcol = 0;
      tmpcol += (unsigned int)(((buff[idx] & 0xFF0000) >> 16) * (1 - alpha)
			       + ((col & 0xFF0000) >> 16) * alpha) << 16;
      tmpcol += (unsigned int)(((buff[idx] & 0xFF00) >> 8) * (1 - alpha)
			       + ((col & 0xFF00) >> 8) * alpha) << 8;
      tmpcol += ((buff[idx] & 0xFF)) * (1 - alpha) + ((col & 0xFF)) * alpha;
      buff[idx] = tmpcol;
    }
  else
    buff[idx] = col;
}
