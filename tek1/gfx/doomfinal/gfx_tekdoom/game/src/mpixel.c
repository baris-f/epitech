/*
** tekpixel.c for tekpixel in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:14:42 2015 Florent Baris
** Last update Sat Jan 16 22:06:39 2016 Gaspard Thirion
*/

#include "tool.h"

void		mpixel(t_img *img, t_2D pos, t_col col)
{
  t_col		*buff;
  int		idx;
  float		alpha;
  t_col		tmpcol;

  buff = (t_col*)img->pixels;
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
      tmpcol += (t_col)(((buff[idx] & 0xFF0000) >> 16) * (1 - alpha)
			       + ((col & 0xFF0000) >> 16) * alpha) << 16;
      tmpcol += (t_col)(((buff[idx] & 0xFF00) >> 8) * (1 - alpha)
			       + ((col & 0xFF00) >> 8) * alpha) << 8;
      tmpcol += ((buff[idx] & 0xFF)) * (1 - alpha) + ((col & 0xFF)) * alpha;
      buff[idx] = tmpcol;
    }
  else
    buff[idx] = col;
}
