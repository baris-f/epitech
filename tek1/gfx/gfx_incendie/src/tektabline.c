/*
** tektabline.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Nov 19 00:30:24 2015 Gaspard Thirion
** Last update Sat Dec  5 20:27:51 2015 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include "../my_lap.h"

void			tektabline(t_bunny_pixelarray *img, t_bunny_position *tab,
				   t_color *col, int n)
{
  int			i;
  t_bunny_position	*p;

  if ((p = malloc(sizeof(t_bunny_position) * 2)) == NULL)
    return;
  i = -1;
  p[0] = tab[0];
  while (++i < n)
    {
      p[1] = p[0];
      p[0] = tab[i];
      tekline(img, p, &col[i - 1]);
    }
  free(p);
}
