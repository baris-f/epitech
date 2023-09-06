/*
** tektabline.c for lighning in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:14:28 2015 Florent Baris
** Last update Mon Dec 21 21:14:31 2015 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include "../my_lap.h"

void			tektabline(t_bunny_pixelarray *img, t_bunny_position *tab,
				   unsigned int col, int n)
{
  int			i;
  t_bunny_position	*p;

  if ((p = bunny_malloc(sizeof(t_bunny_position) * 2)) == NULL)
    return;
  i = -1;
  p[0] = tab[0];
  while (++i < n)
    {
      p[1] = p[0];
      p[0] = tab[i];
      tekline(img, p, col);
    }
}
