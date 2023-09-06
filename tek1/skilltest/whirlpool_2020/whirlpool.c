/*
** whirlpool.c for whirlpool in /home/baris-f/rendu/skilltest/whirlpool_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Jan  4 14:55:36 2016 Florent Baris
** Last update Mon Jan  4 15:40:34 2016 Florent Baris
*/

#include <lapin.h>

t_bunny_position        vect(t_bunny_position a, t_bunny_position b)
{
  t_bunny_position      ret;

  ret.x = b.x - a.x;
  ret.y = b.y - a.y;
  return (ret);
}

void	square(t_bunny_pixelarray *img, t_bunny_position *pos)
{
  t_bunny_position tpos[2];

  tpos[0] = pos[0];
  tpos[1] = pos[1];
  tekline(img, tpos, WHITE);
  tpos[0] = pos[1];
  tpos[1] = pos[2];
  tekline(img, tpos, WHITE);
  tpos[0] = pos[2];
  tpos[1] = pos[3];
  tekline(img, tpos, WHITE);
  tpos[0] = pos[3];
  tpos[1] = pos[0];
  tekline(img, tpos, WHITE);
}

void	whirlpool(t_bunny_pixelarray *pix, const t_bunny_position *pos,
	  double ratio, int depth)
{
  t_bunny_position tpos[5];

  tpos[0] = pos[0];
  tpos[1] = pos[1];
  tpos[2] = pos[2];
  tpos[3] = pos[3];
  if (depth == 0)
    return ;
  square(pix, tpos);
  while (--depth > 0)
    {
      tpos[4] = tpos[0];
      tpos[0].x = tpos[0].x + (vect(tpos[0], tpos[1]).x * ratio);
      tpos[0].y = tpos[0].y + (vect(tpos[0], tpos[1]).y * ratio);
      tpos[1].x = tpos[1].x + (vect(tpos[1], tpos[2]).x * ratio);
      tpos[1].y = tpos[1].y + (vect(tpos[1], tpos[2]).y * ratio);
      tpos[2].x = tpos[2].x + (vect(tpos[2], tpos[3]).x * ratio);
      tpos[2].y = tpos[2].y + (vect(tpos[2], tpos[3]).y * ratio);
      tpos[3].x = tpos[3].x + (vect(tpos[3], tpos[4]).x * ratio);
      tpos[3].y = tpos[3].y + (vect(tpos[3], tpos[4]).y * ratio);
      square(pix, tpos);
    }
}
