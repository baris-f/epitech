/*
** main.c for main in /home/baris-f/rendu/gfx_fdf2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 21:57:24 2015 Florent Baris
** Last update Mon Dec 21 22:17:37 2015 Florent Baris
*/

#include <lapin_enum.h>
#include <math.h>
#include <lapin.h>
#include <unistd.h>

#include "my_lap.h"

t_bunny_response	update(void *_void)
{
  t_pass		*pass;

  pass = (t_pass*)_void;
  if (pass->fill)
    tekfill(pass->img, pass->col);
  bunny_blit(&(pass->win->buffer), &(pass->img->clipable), &pass->pos[0]);
  bunny_display(pass->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_pass		pass[1];
  int			x;
  int			y;

  if (ac != 2)
    return (0);
  x = (ac < 3) ? 1280 : my_getnbr(av[1]);
  y = (ac < 3) ? 720 : my_getnbr(av[2]);
  pass->win = bunny_start(x, y, 0, "update");
  pass->img = bunny_new_pixelarray(x, y);
  pass->pos->x = 0;
  pass->pos->y = 0;
  bunny_set_loop_main_function(update);
  bunny_set_key_response(tekkey);
  pass->col[0].full = BLACK;
  pass->fill = 0;
  tekfill(pass->img, pass->col);
  fdf2(pass->img, av);
  bunny_loop(pass->win, 255, pass);
  bunny_delete_clipable(&pass->img->clipable);
  bunny_stop(pass->win);
  return (0);
}
