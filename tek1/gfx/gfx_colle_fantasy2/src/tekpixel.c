/*
** tekpixel.c for tekpixel in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:14:42 2015 Florent Baris
** Last update Sat Dec 26 17:36:59 2015 Florent Baris
*/

#include "../inc/wolf.h"

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  if (idx <= img->clipable.clip_width * img->clipable.clip_height
      && idx >= 0)
    buff[idx] = col;
}
