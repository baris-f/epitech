/*
** tekllproject.c for tekllproject in /home/baris_f/rendu/gfx_fdf1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Nov 18 18:01:20 2015 Florent Baris
** Last update Wed Jan  6 14:20:15 2016 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include <lapin_enum.h>
#include <math.h>

void	tekllproject(t_bunny_position *out,
		  int x,
		  int y,
		  int z)
{
  float	alpha;

  alpha = M_PI/4;
  out->x = (double)x * cos(M_PI/4.5f - alpha) + (double)y * cos(alpha);
  out->y = -(z + (double)x * sin(M_PI/4.5f - alpha) + (double)y * sin(alpha));
  /* out->x = x+ -1 * cos(alpha) * y; */
  /* out->y = y; */
}
