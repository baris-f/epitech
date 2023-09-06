/*
** gfx_fdf1.c for gfx_fdf1 in /home/baris_f/rendu/gfx_fdf1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Nov 18 15:43:26 2015 Florent Baris
** Last update Wed Nov 25 17:43:24 2015 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include <lapin_enum.h>
#include <math.h>
#include <stdlib.h>
#include "my_lap.h"

int     my_getnbr(const char *str);

/* void	whileun(t_bunny_position *cur, t_bunny_ini_scope *scope, int height) */
/* { */
/*   int	i; */
/*   int	j; */

/*   i = -1; */
/*   while (++i < 19) */
/*     { */
/*       j = -1; */
/*       while (++j < 19) */
/* 	{ */
/* 	  cur[0] = cur[1]; */
/* 	  tekllproject(&cur[1], j * scale, my_getnbr(bunny_ini_get_field(ini, scope, "matrix", j + i * height)) * scale, -i * scale); */
/* 	  cur[1].x += 50; */
/* 	  cur[1].y += 500; */
/* 	  if (j > 0) */
/* 	    tekline(pass->img, cur, color); */
/* 	} */
/*     } */
/* } */

/* void    whiledeux(t_bunny_position *cur, t_bunny_ini_scope *scope, int height) */
/* { */
/*   int   i; */
/*   int   j; */

/*   i = -1; */
/*   while (++i < 19) */
/*     { */
/*       j = -1; */
/*       while (++j < 19) */
/*         { */
/* 	  cur[0] = cur[1]; */
/*           tekllproject(&cur[1], i * scale, my_getnbr(bunny_ini_get_field(ini, scope, "matrix", j + i * height)) * scale, -j * scale); */
/*           cur[1].x += 50; */
/*           cur[1].y += 500; */
/*           if (j > 0) */
/*             tekline(pass->img, cur, color); */
/*         } */
/*     } */
/* } */

void	grid(t_pass *pass, t_bunny_ini *ini, unsigned int color)
{
  t_bunny_position *cur;
  int	x;
  int	z;
  t_bunny_ini_scope     *scope;
  int                   height;
  int			scale;

  scale = 20;
  scope = bunny_ini_first(ini);
  scope = bunny_ini_next(ini, scope);
  height = my_getnbr(bunny_ini_get_field(ini, scope, "height", 0));
  /* width = my_getnbr(bunny_ini_get_field(ini, scope, "width", 0)); */
  if (ini == NULL)
    return ;
  cur = malloc(2 * sizeof(t_bunny_position));
  x = -1;
  cur[1].x = 500;
  cur[1].y = 500;
  while (++x < 19)
    {
      z = -1;
      while (++z < 19)
  	{
  	  cur[0] = cur[1];
  	  /* tekllproject(&cur[1], z * scale, my_getnbr(bunny_ini_get_field(ini, scope, "matrix", x + z * height)) * scale, x * scale); */
	  tekllproject(&cur[1], z * scale, x * scale, my_getnbr(bunny_ini_get_field(ini, scope, "matrix", x + z * height)) * scale);
  	  cur[1].x += 50;
  	  cur[1].y += 500;
  	  if (z > 0)
  	    tekline(pass->img, cur, color);
  	}
    }
  z = -1;
  while (++z < 19)
    {
      x = -1;
      while (++x < 19)
  	{
  	  cur[0] = cur[1];
  	  /* tekllproject(&cur[1], z * scale, my_getnbr(bunny_ini_get_field(ini, scope, "matrix", x + z * height)) * scale, x * scale); */
	  tekllproject(&cur[1], z * scale, x * scale, my_getnbr(bunny_ini_get_field(ini, scope, "matrix", x + z * height)) * scale);
      cur[1].x += 50;
      cur[1].y += 500;
      if (x > 0)
  	tekline(pass->img, cur, color);
  	}
    }
  free(cur);
}
