/*
** tekfill.c for fill in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 22:28:08 2015 Florent Baris
** Last update Sun Jan  3 23:37:24 2016 Florent Baris
*/

#include "../inc/wolf.h"

void			tekfill(t_bunny_pixelarray *img, unsigned int col)
{
  unsigned int		*buff;
  int			i;
  int			max;

  i = -1;
  max = (img->clipable.clip_width * img->clipable.clip_height);
  buff = (unsigned int*)img->pixels;
  while (++i < max)
    buff[i] = col;
}

void			tekfillhalf(t_bunny_pixelarray *img, unsigned int col,
				    int side)
{
  unsigned int		*buff;
  int			i;
  int			max;

  i = -1;
  max = (img->clipable.clip_width * img->clipable.clip_height);
  buff = (unsigned int*)img->pixels;
  if (side == 1)
    while (++i < max / 2)
      buff[i] = col;
  else
    {
      i = max / 2;
      while (++i < max)
	buff[i] = col;
    }
}
