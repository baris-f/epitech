/*
** tekllproject.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:15:51 2015 Gaspard Thirion
** Last update Sat Dec  5 12:07:18 2015 Florent Baris
*/

#include		<lapin.h>
#include		<unistd.h>
#include		<math.h>
#include	        "../my_lap.h"

void			tekisoproject(t_bunny_position *out, t_bunny_position in,
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
