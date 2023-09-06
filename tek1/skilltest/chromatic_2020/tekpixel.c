/*
** tekpixel.c for chromatic in /home/baris-f/rendu/skilltest/chromatic_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb  2 14:10:11 2016 Florent Baris
** Last update Tue Feb  2 15:21:15 2016 Florent Baris
*/

#include <lapin.h>
#include <math.h>

typedef struct          s_line
{
  int   dx;
  int   dy;
  int   xinc;
  int   yinc;
  int   cumul;
}                       t_line;

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

void                    sup(t_bunny_pixelarray *img, t_bunny_position *pos,
			    unsigned int col, t_line v)
{
  int                   i;

  v.cumul = v.dx / 2;
  i = 0;
  while (++i <= v.dx)
    {
      pos[0].x += v.xinc;
      v.cumul += v.dy;
      if (v.cumul >= v.dx)
	{
	  v.cumul -= v.dx;
	  pos[0].y += v.yinc;
	}
      tekpixel(img, pos, col);
    }
}

void                    sub(t_bunny_pixelarray *img, t_bunny_position *pos,
			    unsigned int col, t_line v)
{
  int                   i;

  v.cumul = v.dy / 2;
  i = 0;
  while (++i <= v.dy)
    {
      pos[0].y += v.yinc;
      v.cumul += v.dx;
      if (v.cumul >= v.dy)
	{
	  v.cumul -= v.dy;
	  pos[0].x += v.xinc;
	}
      tekpixel(img, pos, col);
    }
}

void                    tekline(t_bunny_pixelarray *img, t_bunny_position *tab,
				unsigned int col)
{
  t_bunny_position      *pos;
  t_line                vars;

  pos = malloc(sizeof(t_bunny_position) * 2);
  if (pos == NULL)
    return;
  pos[0].x = tab[0].x;
  pos[0].y = tab[0].y;
  pos[1].x = tab[1].x;
  pos[1].y = tab[1].y;
  vars.dx = pos[1].x - pos[0].x;
  vars.dy = pos[1].y - pos[0].y;
  vars.xinc = (vars.dx > 0) ? 1 : -1;
  vars.yinc = (vars.dy > 0) ? 1 : -1;
  vars.dx = ABS(vars.dx);
  vars.dy = ABS(vars.dy);
  tekpixel(img, pos, col);
  if (vars.dx > vars.dy)
    sup(img, pos, col, vars);
  else
    sub(img, pos, col, vars);
  free(pos);
}

void	c64_chromatic(t_bunny_pixelarray *pix, unsigned int *height,
	      unsigned int *color, size_t len)
{
  int	i;
  int	j;
  int	lel;
  t_bunny_position	pos[2];

  i = -1;
  lel = 0;
  pos[0].x = 0;
  pos[1].x = pix->clipable.clip_width;
  while (++i < len)
    {
      j = -1;
      while (++j < height[i])
	{
	  pos[0].y = lel + j;
	  pos[1].y = lel + j;
	  tekline(pix, pos, color[i]);
	}
      lel += j;
    }
}

void    chromatic(t_bunny_pixelarray *pix, unsigned int *height,
		      unsigned int *color, size_t len)
{
  int   i;
  int   j;
  int   lel;
  t_bunny_position      pos[2];

  i = -1;
  lel = 0;
  pos[0].x = 0;
  pos[1].x = pix->clipable.clip_width;
  while (++i < len)
    {
      j = -1;
      while (++j < height[i])
	{
	  pos[0].y = lel + j;
	  pos[1].y = lel + j;
	  tekline(pix, pos, color[i]);
	}
      lel += j;
    }
}
