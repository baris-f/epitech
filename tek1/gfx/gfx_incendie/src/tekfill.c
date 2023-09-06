/*
** tekfill.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:15:15 2015 Gaspard Thirion
** Last update Sun Nov 22 20:20:54 2015 Gaspard Thirion
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
