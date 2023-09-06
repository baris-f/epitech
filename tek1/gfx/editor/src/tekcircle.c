/*
** tekcircle.c for circle in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:17:34 2015 Florent Baris
** Last update Tue Jan 19 02:56:12 2016 Florent Baris
*/

#include                "wolf.h"

void			tekcircle(t_img *pix, t_2D O, int R, t_col col)
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
      cur.x = O.x + cos(alpha) * R;
      cur.y = O.y + sin(alpha) * R;
      tekpixel(pix, cur, col);
    }
}
