/*
** tekline.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:15:36 2015 Gaspard Thirion
** Last update Sun Dec  6 22:43:58 2015 Florent Baris
*/

#include		<lapin.h>
#include		<unistd.h>
#include	        "../my_lap.h"

void            my_set_pixel(t_bunny_pixelarray *pix,
			     t_bunny_position pos, unsigned int color)
{
  unsigned int  *pixel;
  int           width;

  pixel = (unsigned int*)pix->pixels;
  width = pix->clipable.clip_width;
  pixel[pos.y * width + pos.x] = color;
}

void			supg(t_bunny_pixelarray *img, t_bunny_position *pos,
			    unsigned int *col, t_line *v)
{
  int			i;

  v->cumul = v->dx / 2;
  i = 0;
  while (++i <= v->dx)
    {
      pos[0].x += v->xinc;
      v->cumul += v->dy;
      if (v->cumul >= v->dx)
	{
	  v->cumul -= v->dx;
	  pos[0].y += v->yinc;
	}
      my_set_pixel(img, pos[0], col[(v->len)++]);
    }
}

void			subg(t_bunny_pixelarray *img, t_bunny_position *pos,
			    unsigned int *col, t_line *v)
{
  int			i;

  v->cumul = v->dy / 2;
  i = 0;
  while (++i <= v->dy)
    {
      pos[0].y += v->yinc;
      v->cumul += v->dx;
      if (v->cumul >= v->dy)
	{
	  v->cumul -= v->dy;
	  pos[0].x += v->xinc;
	}
      my_set_pixel(img, pos[0], col[(v->len)++]);
    }
}

void			teklinegrad(t_bunny_pixelarray *img, t_bunny_position *tab,
				unsigned int *col)
{
  t_line		*vars;
  t_bunny_position	*pos;

    if ((vars = malloc(sizeof(t_bunny_position) * 2)) == NULL)
    return;
  if ((pos = malloc(sizeof(t_bunny_position) * 2)) == NULL)
    return;
  vars->len = 0;
  pos[0].x = tab[0].x;
  pos[0].y = tab[0].y;
  pos[1].x = tab[1].x;
  pos[1].y = tab[1].y;
  vars->dx = pos[1].x - pos[0].x;
  vars->dy = pos[1].y - pos[0].y;
  vars->xinc = (vars->dx > 0) ? 1 : -1;
  vars->yinc = (vars->dy > 0) ? 1 : -1;
  vars->dx = ABS(vars->dx);
  vars->dy = ABS(vars->dy);
  my_set_pixel(img, pos[0], col[(vars->len)++]);
  if (vars->dx > vars->dy)
      supg(img, pos, col, vars);
  else
      subg(img, pos, col, vars);
  free(pos);
  free(vars);
}
