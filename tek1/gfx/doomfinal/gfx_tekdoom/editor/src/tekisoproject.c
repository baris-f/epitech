/*
** tekisoproject.c for iso in /home/baris-f/rendu/gfx_fdf2/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 22:21:19 2015 Florent Baris
** Last update Mon Dec 21 22:21:20 2015 Florent Baris
*/

#include		<lapin.h>
#include		<unistd.h>
#include		<math.h>
#include	        "../my_lap.h"
#include		"../my.h"

void                    tekisoproject(t_bunny_position *out, int x, int y,
				       int z)
{
  out[0].x = sin(M_PI / 6.f) * (double)x - sin(M_PI / 6.f) * (double)y;
  out[0].y = cos(M_PI / 3.f) * (double)x + cos(M_PI / 3.f) * (double)y - z;
}

void			tekinioproject(t_bunny_position *out, t_bunny_position in,
				      t_ini *ini)
{
  int			z;
  int			idx;

  idx = in.x + (ini->dim.y - in.y) * ini->dim.x;
  if ((bunny_ini_scope_get_field(ini->scope, "data", idx)) == NULL)
    return;
  z = ini->scale.z * my_getnbr((char*)bunny_ini_scope_get_field(ini->scope,
								"data", idx));
  in.x = out->x * ini->scale.x;
  in.y = out->y * ini->scale.y;
  out->x = (in.x * cos((M_PI / 4.5) - ini->ang) + in.y * cos(ini->ang));
  out->y = -(in.x * -sin((M_PI / 4.5) - ini->ang) + in.y * sin(ini->ang) + z);
  out->x += ini->org.x;
  out->y += ini->org.y;
}
