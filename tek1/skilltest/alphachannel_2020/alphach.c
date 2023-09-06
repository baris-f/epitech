/*
** alphach.c for alphach in /home/baris-f/rendu/alphachannel_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Dec 15 14:05:51 2015 Florent Baris
** Last update Mon Jan  4 16:14:24 2016 Florent Baris
*/

#include                <lapin.h>
#include                <unistd.h>
#include		"my_lap.h"

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  if (idx <= img->clipable.clip_width * img->clipable.clip_height
      && idx >= 0)
    buff[idx] = col;
}

void                    tekpixela(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;
  float			alpha;
  unsigned int		tmpcol;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  alpha = ((col & 0xFF000000) >> 24);
  if (!(idx <= img->clipable.clip_width * img->clipable.clip_height
       && idx >= 0))
     return;
  if (alpha != 255)
    {
      alpha = alpha / 255;
      tmpcol = 0;
      tmpcol += (unsigned int)(((buff[idx] & 0xFF0000) >> 16) * (1 - alpha)
			       + ((col & 0xFF0000) >> 16) * alpha) << 16;
      tmpcol += (unsigned int)(((buff[idx] & 0xFF00) >> 8) * (1 - alpha)
			       + ((col & 0xFF00) >> 8) * alpha) << 8;
      tmpcol += ((buff[idx] & 0xFF)) * (1 - alpha) + ((col & 0xFF)) * alpha;
      buff[idx] = tmpcol;
    }
 else
    buff[idx] = col;
}

void	square(t_bunny_pixelarray *pix, t_bunny_square *squ, unsigned int color, int alpha)
{
  int	i;
  int	j;
  t_bunny_position pos[1];

  i = -1;
  while (++i < squ->width)
    {
      j = -1;
      while (++j < squ->height)
	{
	  pos->x = squ->x + i;
	  pos->y = squ->y + j;
	  if (alpha == 1)
	    tekpixela(pix, pos, color);
	  else
	    tekpixel(pix, pos, color);
	}
    }
}
