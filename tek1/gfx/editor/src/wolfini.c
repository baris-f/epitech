/*
** wolfini.c for wolfini in /home/baris-f/rendu/gfx_wolf3d/src
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Dec 30 13:48:22 2015 Florent Baris
** Last update Thu Jan 14 13:51:36 2016 Florent Baris
*/

#include "../inc/wolf.h"

void	square(int x, int y, unsigned int col, t_pass *pass)
{
  int	i;
  int	j;
  int	mx;
  int	my;
  t_pos pos;

  i = -1;
  mx = 250 / pass->ini->dim.x;
  my = 250 / pass->ini->dim.y;
  while (++i < mx)
    {
      j = -1;
      while (++j < my)
	{
	  pos.x = x * mx + i;
	  pos.y = y * my + j;
	  tekpixel(pass->img, &pos, col);
	}
    }
}

void	map(t_pass *pass)
{
  int	i;

  i = -1;
  while (++i < pass->ini->dim.x * pass->ini->dim.y)
    if (my_getnbr(bunny_ini_scope_get_field(pass->ini->scope,
					    "data", i)) == 0)
      square(i % pass->ini->dim.x,
	     i / pass->ini->dim.x
	     , 0xFF222222, pass);
    else
      square(i % pass->ini->dim.x,
	     i / pass->ini->dim.x
	     , 0xFF000000, pass);
}

void	whatside(t_pos dpos, int *posx, int *posy, int side)
{
  if (side == 1)
    {
      *posx += dpos.x;
      *posy += dpos.y;
    }
  else if (side == 2)
    {
      *posx -= dpos.x;
      *posy -= dpos.y;
    }
  else if (side == 3)
    {
      *posx += dpos.y;
      *posy -= dpos.x;
    }
  else if (side == 4)
    {
      *posx -= dpos.y;
      *posy += dpos.x;
    }
}

int	whereami(t_pass *pass, int side)
{
  int	posx;
  int	posy;
  float x;
  float y;
  int	ret;
  t_pos         dpos;

  polcar(&dpos, pass->player->ang, 5);
  posx = pass->player->pos.x;
  posy = pass->player->pos.y;
  whatside(dpos, &posx, &posy, side);
  x = (float)posx / (float)pass->ini->scale;
  y = (float)posy / (float)pass->ini->scale;
  if (x <= 0 || y <= 0 || x >= pass->ini->dim.x || y >= pass->ini->dim.y)
    return (1);
  else
    ret = my_getnbr(bunny_ini_scope_get_field(pass->ini->scope, "data",
					    (int)x + (int)y * pass->ini->dim.x));
  if (ret == 1)
    return (1);
  return (0);
}

int	wolfini(t_pass *pass)
{
  if ((pass->ini->file = bunny_load_ini(pass->ini->name)) == NULL)
    return (1);
  if ((pass->ini->scope = bunny_ini_first(pass->ini->file)) == NULL)
    return (1);
  if ((pass->ini->scope = bunny_ini_next(pass->ini->file, pass->ini->scope))
      == NULL)
    return (1);
  pass->ini->scale = my_getnbr(bunny_ini_scope_get_field(pass->ini->scope,
							 "scale", 0)) * 10;
  pass->ini->dim.x = my_getnbr(bunny_ini_scope_get_field(pass->ini->scope,
							 "dim", 0));
  pass->ini->dim.y = my_getnbr(bunny_ini_scope_get_field(pass->ini->scope,
							 "dim", 1));
  if (pass->ini->init == 0)
    {
      pass->player->pos.x = my_getnbr(bunny_ini_scope_get_field(
	    pass->ini->scope, "start", 0)) * pass->ini->scale / 2;
      pass->player->pos.y = my_getnbr(bunny_ini_scope_get_field(
	    pass->ini->scope, "start", 1)) * pass->ini->scale / 2;
      pass->player->ang = 0;
      pass->player->len = 5;
      pass->ini->init = 1;
  }
  return (0);
}
