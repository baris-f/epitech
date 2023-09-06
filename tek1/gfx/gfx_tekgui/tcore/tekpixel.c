/*
** tekpixel.c for tekpixel in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 18:14:11 2016 Florent Baris
** Last update Sun Feb 28 22:08:40 2016 Florent Baris
*/

#include <lapin.h>

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 t_color *color)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  if (idx <= img->clipable.clip_width * img->clipable.clip_height
      && idx >= 0)
    buff[idx] = color->full;
}
