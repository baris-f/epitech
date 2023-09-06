/*
** tekline.c for tekline in /home/baris_f/rendu/gfx_fdf1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Nov 18 16:10:08 2015 Florent Baris
** Last update Sun Nov 22 22:25:39 2015 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include <lapin_enum.h>
#include "my_lap.h"

void            tekpixel(t_bunny_pixelarray *pix,
                         t_bunny_position *pos,
                         unsigned int color);

int                     my_abs(int num)
{
  return ((num > 0) ? num : -(num));
}

void	while1(t_bunny_pixelarray *pix,
	       t_bunny_position *pos,
	       unsigned int color, t_line *t)
{
  int   i;
  int	cumul;

  i = 1;
  cumul = t->dx / 2;
  while (i <= t->dx)
    {
      pos[0].x += t->xinc;
      cumul += t->dy;
      if (cumul >= t->dx)
	{
	  cumul -= t->dx;
	  pos[0].y += t->yinc;
	}
      tekpixel(pix, &pos[0], color);
      i++;
    }
}

void	while2(t_bunny_pixelarray *pix,
	       t_bunny_position *pos,
	       unsigned int color, t_line *t)
{
  int	i;
  int	cumul;

  i = 1;
  cumul = t->dy / 2;
  while (i <= t->dy)
    {
      pos[0].y += t->yinc;
      cumul += t->dx;
      if (cumul >= t->dy)
	{
	  cumul -= t->dy;
	  pos[0].x += t->xinc;
	}
      tekpixel(pix, &pos[0], color);
      i++;
    }
}

void		tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				unsigned int color)
{
  t_line	*t;

  t = malloc(sizeof(int) * 4);
  t->dx = pos[1].x - pos[0].x;
  t->dy = pos[1].y - pos[0].y;
  t->xinc = (t->dx > 0) ? 1 : -1;
  t->yinc = (t->dy > 0) ? 1 : -1;
  t->dx = my_abs(t->dx);
  t->dy = my_abs(t->dy);
    tekpixel(pix, &pos[0], color);
  if (t->dx > t->dy)
    while1(pix, &pos[0], color, t);
  else
    while2(pix, &pos[0], color, t);
  free(t);
}
