/*
** tekpixel.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:15:01 2015 Gaspard Thirion
** Last update Sat Dec  5 12:08:39 2015 Florent Baris
*/

#include		<lapin.h>
#include		<unistd.h>
#include	        "../my_lap.h"

void			tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 t_color *col)
{
  unsigned int		*buff;
  int			idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  if (idx <= img->clipable.clip_width * img->clipable.clip_height
      && idx >= 0)
    buff[idx] = col->full;
}
