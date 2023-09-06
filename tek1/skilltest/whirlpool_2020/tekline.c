/*
** tekline.c for line in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 22:12:02 2015 Florent Baris
** Last update Mon Jan  4 15:44:53 2016 Florent Baris
*/

#include "lapin.h"

# define ABS(Value) ((Value < 0) ? (Value * -1) : (Value))

typedef struct		s_line
{
  int   dx;
  int   dy;
  int   xinc;
  int   yinc;
  int   cumul;
}			t_line;

void			sup(t_bunny_pixelarray *img, t_bunny_position *pos,
			    unsigned int col, t_line v)
{
  int			i;

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

void			sub(t_bunny_pixelarray *img, t_bunny_position *pos,
			    unsigned int col, t_line v)
{
  int			i;

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

void			tekline(t_bunny_pixelarray *img, t_bunny_position *tab,
				unsigned int col)
{
  t_bunny_position	*pos;
  t_line		vars;

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
