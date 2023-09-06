/*
** gfx_fdf2.c for fdf2 in /home/baris-f/rendu/gfx_fdf2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Dec 20 19:10:33 2015 Florent Baris
** Last update Mon Dec 21 22:14:00 2015 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include <lapin_enum.h>
#include <math.h>
#include "my_lap.h"

void	pixel(t_bunny_pixelarray *pix, char **av, int scopepos)
{
  t_bunny_ini_scope     *scope;
  t_bunny_ini           *ini;
  t_bunny_position	pos[1];

  ini = bunny_load_ini(av[1]);
  scope = bunny_ini_first(ini);
  while (--scopepos >= 0)
    scope = bunny_ini_next(ini, scope);
  tekisoproject(&pos[0], my_getnbr(bunny_ini_scope_get_field(scope, "data", 0)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 1)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 2)));
  tekpixel(pix, pos, RED);
}

void    line(t_bunny_pixelarray *pix, char **av, int scopepos)
{
  t_bunny_ini_scope     *scope;
  t_bunny_ini           *ini;
  t_bunny_position      pos[2];

  ini = bunny_load_ini(av[1]);
  scope = bunny_ini_first(ini);
  while (--scopepos >= 0)
    scope = bunny_ini_next(ini, scope);
  tekisoproject(&pos[0], my_getnbr(bunny_ini_scope_get_field(scope, "data", 0)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 1)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 2)));
  tekisoproject(&pos[1], my_getnbr(bunny_ini_scope_get_field(scope, "data", 3)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 4)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 5)));
  tekline(pix, pos, RED);
}

void    polygon(t_bunny_pixelarray *pix, char **av, int scopepos)
{
  t_bunny_ini_scope     *scope;
  t_bunny_ini           *ini;
  t_bunny_position      pos[4];

  ini = bunny_load_ini(av[1]);
  scope = bunny_ini_first(ini);
  while (--scopepos >= 0)
    scope = bunny_ini_next(ini, scope);
  tekisoproject(&pos[0], my_getnbr(bunny_ini_scope_get_field(scope, "data", 0)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 1)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 2)));
  tekisoproject(&pos[3], my_getnbr(bunny_ini_scope_get_field(scope, "data", 0)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 1)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 2)));
  tekisoproject(&pos[1], my_getnbr(bunny_ini_scope_get_field(scope, "data", 3)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 4)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 5)));
  tekisoproject(&pos[2], my_getnbr(bunny_ini_scope_get_field(scope, "data", 6)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 7)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 8)));
  tektabline(pix, pos, RED, 4);
  tekpixel(pix, pos, RED);
}

void    sphere(t_bunny_pixelarray *pix, char **av, int scopepos)
{
  t_bunny_ini_scope     *scope;
  t_bunny_ini           *ini;
  t_bunny_position      pos[1];
  int			radius[4];

  radius[4] = 9;
  ini = bunny_load_ini(av[1]);
  scope = bunny_ini_first(ini);
  while (--scopepos >= 0)
    scope = bunny_ini_next(ini, scope);
  tekisoproject(&pos[0], my_getnbr(bunny_ini_scope_get_field(scope, "data", 0)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 1)),
		my_getnbr(bunny_ini_scope_get_field(scope, "data", 2)));
  radius[0] = my_getnbr(bunny_ini_scope_get_field(scope, "data", 3));
  ovales(pix, pos, radius);
}

void			fdf2(t_bunny_pixelarray *pix, char **av)
{
  t_bunny_ini_scope     *scope;
  t_bunny_ini		*ini;
  int			i;
  char			*shape;

  i = 0;
  ini = bunny_load_ini(av[1]);
  if (ini == NULL)
    return ;
  scope = bunny_ini_first(ini);
  scope = bunny_ini_next(ini, scope);
  while (scope != NULL)
    {
      i++;
      shape = (char *)bunny_ini_scope_get_field(scope, "shape", 0);
      if (my_strcmp(shape, "pixel") == 0)
	pixel(pix, av, i);
      else if (my_strcmp(shape, "line") == 0)
	line(pix, av, i);
      else if (my_strcmp(shape, "polygon") == 0)
	polygon(pix, av, i);
      else if (my_strcmp(shape, "sphere") == 0)
	sphere(pix, av, i);
      scope = bunny_ini_next(ini, scope);
    }
}
