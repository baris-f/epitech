/*
** update.c for fdf in /home/fus/rendu/gfx_fdf1
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:14:29 2015 Gaspard Thirion
** Last update Wed Dec  9 14:27:04 2015 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
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

  x = (ac < 3) ? 500 : my_getnbr(av[1]);
  y = (ac < 3) ? 500 : my_getnbr(av[2]);
  pass->win = bunny_start(x, y, 0, "update");
  pass->img = bunny_new_pixelarray(x, y);
  pass->pos->x = 0;
  pass->pos->y = 0;
  bunny_set_loop_main_function(update);
  bunny_set_key_response(tekkey);
  bunny_set_move_response((t_bunny_move)tekmove);
  bunny_set_click_response(tekclick);
  pass->col[0].full = 0x666666;
  pass->fill = 0;
  tekfill(pass->img, pass->col);
  bunny_loop(pass->win, 255, pass);
  my_putchar('\n');
  bunny_delete_clipable(&pass->img->clipable);
  bunny_stop(pass->win);
  return (0);
}
