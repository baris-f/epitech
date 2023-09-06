/*
** tekfill.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:15:15 2015 Gaspard Thirion
** Last update Thu Jan 14 18:56:31 2016 Gaspard Thirion
*/

#include "tool.h"

void		clear(t_img *img, t_col col)
{
  t_col		*buff;
  int		i;

  i = -1;
  buff = (t_col*)img->pixels;
  while (++i < (img->clipable.clip_width * img->clipable.clip_height))
    buff[i] = col;
}
