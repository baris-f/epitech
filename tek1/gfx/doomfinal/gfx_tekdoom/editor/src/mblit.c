/*
** mblit.c for wolf in /home/fus/rendu/gfx_wolf3d/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Fri Dec 25 18:57:22 2015 Gaspard Thirion
** Last update Mon Jan 25 13:35:20 2016 Florent Baris
*/

#include <wolf.h>

void		mblit(t_img *dest, t_img *src, t_col alpha)
{
  t_2D		tmp;
  t_col		*sbuff;
  t_col		*dbuff;
  t_col		col;
  int		idx;

  (void)alpha;
  sbuff = (unsigned int*)src->pixels;
  dbuff = (unsigned int*)dest->pixels;
  tmp.y = -1;
  while (++tmp.y < src->clipable.clip_height)
    {
      tmp.x = -1;
      while (++tmp.x < src->clipable.clip_width)
	{
	  idx = src->clipable.clip_width * tmp.y + tmp.x;
	  col = sbuff[idx];
	  dbuff[tmp.y * src->clipable.clip_width + tmp.x] = col;
	}
    }
}
