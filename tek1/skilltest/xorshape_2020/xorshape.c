/*
** xorshape.c for xorshape in /home/baris-f/rendu/xorshape_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 30 09:12:58 2015 Florent Baris
** Last update Mon Nov 30 10:00:31 2015 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include <math.h>

typedef struct
s_bunny_shape
{
  int x;
  int y;
  float  radius;
  unsigned int  border_color;
  unsigned int fill_color;
} t_bunny_shape;

void    my_set_pixel(t_bunny_pixelarray *pix, t_bunny_position pos, unsigned int color)
{
  unsigned int *pixel;

  pixel = pix->pixels;
  pixel[(pix->clipable.clip_width) * pos.y + pos.x] = color ^ pixel[(pix->clipable.clip_width) * pos.y + pos.x];
}

void                    my_circle(t_bunny_pixelarray *pix, t_bunny_position O, float R, float p, unsigned int color)
{
  t_bunny_position      cur;
  float                 alpha;

  alpha = 0.0;
  p = p / 180 * M_PI;
  while (alpha < 2 * M_PI)
    {
      alpha += p;
      cur.x = O.x + cos(alpha) * R;
      cur.y = O.y + sin(alpha) * R;
      my_set_pixel(pix, cur, color);
    }
}

void	xor_shape(t_bunny_pixelarray	  *pix,
		  t_bunny_shape	  *shape,
		  size_t	  nshape)
{
  t_bunny_position	pos;
  int		i;
  float		tmpR;

  i = -1;
  while (++i < nshape)
    {
      pos.x = shape[i].x;
      pos.y = shape[i].y;
      tmpR = shape[i].radius;
      my_circle(pix, pos, shape[i].radius, 0.1, shape[i].border_color);
      while (tmpR > 0)
	{
	  tmpR -= 0.1;
	  my_circle(pix, pos, tmpR, 0.1, shape[i].fill_color);
	}
    }
}
