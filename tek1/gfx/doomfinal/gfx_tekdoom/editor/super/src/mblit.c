/*
** mblit.c for wolf in /home/fus/rendu/gfx_wolf3d/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Fri Dec 25 18:57:22 2015 Gaspard Thirion
** Last update Fri Jan 15 16:32:12 2016 Gaspard Thirion
*/

#include <tool.h>

void		mblit(t_img *dest, t_img *src, t_col alpha)
{
  t_2D		tmp;
  t_2D		tmp2;
  t_col		*sbuff;
  t_col		col;
  int		idx;

  sbuff = (unsigned int*)src->pixels;
  tmp.y = -1;
  while (++tmp.y < src->clipable.clip_height)
    {
      tmp.x = -1;
      while (++tmp.x <src->clipable.clip_width)
	{
	  idx = src->clipable.clip_width * tmp.y + tmp.x;
	  if ((col = sbuff[idx]) != alpha)
	    {
	      tmp2.x = tmp.x + src->clipable.origin.x;
	      tmp2.y = tmp.y + src->clipable.origin.y;
	      mpixel(dest, tmp2, col);
	    }
	}
    }
}
