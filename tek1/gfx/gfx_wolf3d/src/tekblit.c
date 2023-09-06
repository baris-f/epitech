/*
** tekblit.c for blit in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:15:16 2015 Florent Baris
** Last update Sat Dec 26 17:36:12 2015 Florent Baris
*/

#include "../inc/wolf.h"

void			tekblit(t_bunny_pixelarray *dest, t_bunny_pixelarray *src,
				unsigned int rm)
{
  unsigned int          *dbuff;
  unsigned int          *sbuff;
  t_bunny_position      tmp;
  unsigned int          col;
  int                   i;
  int                   idx;

  dbuff = (unsigned int*)dest->pixels;
  sbuff = (unsigned int*)src->pixels;
  tmp.y = src->clipable.clip_y_position + src->clipable.clip_height;
  i = -1;
  while (--tmp.y > src->clipable.clip_y_position)
    {
      tmp.x = src->clipable.clip_x_position -1;
      while (++tmp.x < src->clipable.clip_width + src->clipable.clip_x_position)
	{
	  col = sbuff[++i];
	  idx = dest->clipable.clip_width * tmp.y + tmp.x;
	  if (idx <= dest->clipable.clip_width * dest->clipable.clip_height
              && idx >= 0 && col != rm)
	    dbuff[idx] = col;
	}
    }
}
