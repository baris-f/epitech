/*
** draw.c for 2048 in /home/baris-f/rendu/colle/CPE_colle_semaine3
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri May 13 14:42:38 2016 Florent Baris
** Last update Fri May 13 15:10:59 2016 Florent Baris
*/

#include "2048.h"

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  buff[idx] = col;
}

int	draw_square(t_base *_m, int i, int idx)
{
  t_bunny_position	pos;
  t_bunny_position	tmp;
  unsigned int		*buf;
  int			j;
  int			k;

  buf = (unsigned int*)_m->numbers->pixels;
  pos.x = 64 * (i % 4);
  pos.y = 64 * (i / 4);
  j = -1;
  tmp.y = pos.y;
  while (++j < 64)
    {
      k = -1;
      tmp.x = pos.x;
      while (++k < 64)
	{
	  tekpixel(_m->img, &tmp, buf[j * 640 + k + idx * 64]);
	  tmp.x++;
	}
      tmp.y++;
    }
  return (0);
}

int	draw_grid(t_base *_m)
{
  int	i;

  i = -1;
  while (++i < 16)
    draw_square(_m, i, _m->grid[i]);
  return (0);
}
