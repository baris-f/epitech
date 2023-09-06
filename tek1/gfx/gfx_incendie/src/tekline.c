/*
** tekline.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:15:36 2015 Gaspard Thirion
** Last update Sun Dec  6 00:08:19 2015 Florent Baris
*/

#include		<lapin.h>
#include		<unistd.h>
#include	        "../my_lap.h"

void			sup(t_bunny_pixelarray *img, t_bunny_position *pos,
			    t_color *col, t_line v)
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
			    t_color *col, t_line v)
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
				t_color *col)
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
