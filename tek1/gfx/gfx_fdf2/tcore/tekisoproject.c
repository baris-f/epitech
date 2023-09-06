/*
** tekisoproject.c for tekisoproject in /home/baris-f/rendu/gfx_fdf2/tcore
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 12:55:44 2015 Florent Baris
** Last update Mon Dec 21 22:21:09 2015 Florent Baris
*/

#include                <lapin.h>
#include                <unistd.h>
#include                <math.h>

void                    tekisoproject(t_bunny_position *out, int x, int y,
				      int z)
{
  out[0].x = sin(M_PI / 6.f) * (double)x - sin(M_PI / 6.f) * (double)y;
  out[0].y = cos(M_PI / 3.f) * (double)x + cos(M_PI / 3.f) * (double)y - z;
}
