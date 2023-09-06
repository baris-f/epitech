/*
** tektabgradiant.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Nov 19 00:30:24 2015 Gaspard Thirion
** Last update Sun Dec  6 22:59:54 2015 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include "../my_lap.h"

void			tektabgrad(t_bunny_pixelarray *img,
				   t_bunny_position *tab,
				   unsigned int *color, int n)
{
  int			i;
  t_bunny_position	cur[2];
  unsigned int		*colors;
  unsigned int		tmp[2];
  int			nbcol;

  i = -1;
  while (++i < n - 1)
    {
      tmp[0] = color[i];
      tmp[1] = color[i + 1];
      cur[0].x = tab[i].x;
      cur[0].y = tab[i].y;
      cur[1].x = tab[i + 1].x;
      cur[1].y = tab[i + 1].y;
      nbcol = linelen(cur);
      cur[1].y = cur[0].y + nbcol - 2;
      if ((colors = malloc(sizeof(unsigned int) * nbcol + 1)) == NULL)
	return ;
      setcolors(tmp, nbcol, colors);
      teklinegrad(img, cur, colors);
    }
  free(colors);
}
