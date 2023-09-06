/*
** tekfill.c for fill in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 22:28:08 2015 Florent Baris
** Last update Mon Dec 21 22:28:10 2015 Florent Baris
*/

#include		<lapin.h>
#include		<unistd.h>
#include	        "../my_lap.h"

void			tekfill(t_bunny_pixelarray *img, t_color *col)
{
  unsigned int		*buff;
  int			i;

  i = -1;
  buff = (unsigned int*)img->pixels;
  while (++i < (img->clipable.clip_width * img->clipable.clip_height))
    buff[i] = col->full;
}
