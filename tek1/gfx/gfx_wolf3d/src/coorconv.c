/*
** coorconv.c for coorconv in /home/baris-f/tesrt/tmp
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 30 10:44:09 2015 Florent Baris
** Last update Mon Jan 11 15:48:11 2016 Florent Baris
*/

#include "../inc/wolf.h"

void	polcar(t_bunny_position *out, int ang, int len)
{
  float	angg;

  angg = (ang * M_PI) / 180;
  if (angg < 0)
    out->x = (int)(-cos(angg) * len);
  else
    out->x = (int)(cos(angg) * len);
  if (angg < 0)
    out->y = (int)(sin(angg) * len);
  else
    out->y = (int)(-sin(angg) * len);
}

void	carpol(t_bunny_position pos, float *ang, float *len)
{
  *len = sqrt(pow(pos.x, 2) + pow(pos.y, 2));
  if (pos.x > 0)
    *ang = -atan(pos.x / pos.y);
  else
    *ang = -atan((pos.x / pos.y) + M_PI);
}
