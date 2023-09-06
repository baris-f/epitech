/*
** stretch.c for stretch in /home/baris-f/rendu/gfx_fdf2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Dec 18 13:55:56 2015 Florent Baris
** Last update Fri Dec 18 15:35:08 2015 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>

void	stretch(t_bunny_pixelarray *pix, const t_bunny_pixelarray *ori)
{
  unsigned int		*bufori;
  unsigned int          *bufpix;
  int			x;
  int			y;
  float			r1;

  r1 = ori->clipable.clip_width / pix->clipable.clip_width;
  printf("r1 : %f\n", r1);
  bufori = (unsigned int*)ori->pixels;
  bufpix = (unsigned int*)pix->pixels;
  y = -1;
  while (++y < pix->clipable.clip_height)
    {
      x = -1;
      while (++x < pix->clipable.clip_width)
	{
	    bufpix[x + y * pix->clipable.clip_width] = bufori[(int)(x + y * pix->clipable.clip_width * r1)];
	}
    }
}
