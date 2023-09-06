/*
** tekcircle.c for circle in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:17:34 2015 Florent Baris
** Last update Mon Dec 21 22:00:45 2015 Florent Baris
*/

#include                <lapin.h>
#include                <unistd.h>
#include		<math.h>
#include                "../my_lap.h"
#include                "../my.h"

void			tekcircle(t_bunny_pixelarray *pix, t_bunny_position O,
				  int *R,
				  unsigned int col)
{
  t_bunny_position      cur;
  float                 alpha;
  float			p;

  alpha = 0.0;
  p = 0.05;
  p = p / 180 * M_PI;
  while (alpha < 2 * M_PI)
    {
      alpha += p;
      cur.x = O.x + cos(alpha) * R[1];
      cur.y = O.y + sin(alpha) * R[2];
      tekpixel(pix, &cur, col);
    }
}

void	ovales(t_bunny_pixelarray *pix, t_bunny_position *pos, int *radius)
{
  radius[2] = radius[0];
  radius[1] = radius[0];
  tekcircle(pix, pos[0], radius, RED);
  while (--radius[4] > 4)
    {
      radius[1] = (int)((float)radius[1] * (float)radius[4] / 10);
      tekcircle(pix, pos[0], radius, RED);
    }
  radius[1] = radius[0];
  radius[4] = 9;
  while (--radius[4] > 4)
    {
      radius[2] = (int)((float)radius[2] * (float)(radius[4]) / 10);
      tekcircle(pix, pos[0], radius, RED);
    }
}
