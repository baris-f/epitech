/*
** tekpixel.c for chromatic in /home/baris-f/rendu/skilltest/chromatic_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb  2 14:10:11 2016 Florent Baris
** Last update Mon Apr 18 14:35:32 2016 Florent Baris
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

typedef struct s_bunny_broken_point
{
  double x;
  double y;
  double x_speed;
  double y_speed;
}	t_bunny_broken_point;

typedef struct s_bunny_mystic_point
{
  double  x;
  double  y;
  double  x_speed;
  double  y_speed;
  t_color  color;
  t_color  color_speed;
}  t_bunny_mystic_point;

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
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
      tekpixel(img, *pos, col);
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
      tekpixel(img, *pos, col);
    }
}

void                    tekline(t_bunny_pixelarray *img, t_bunny_position *tab,
				unsigned int *color)
{
  t_bunny_position      *pos;
  t_line                vars;
  unsigned int		col;

  col = color[0];
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
  tekpixel(img, *pos, col);
  if (vars.dx > vars.dy)
    sup(img, pos, col, vars);
  else
    sub(img, pos, col, vars);
  free(pos);
}

void broken_lines(t_bunny_pixelarray *pix,
	     t_bunny_broken_point *pts,
	     size_t len)
{
  return ;
}

void mystify_your_mind(t_bunny_pixelarray *pix,
		  t_bunny_mystic_point  *pts,
		         size_t	len)
{
  return ;
}
