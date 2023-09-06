/*
** main.c for main in /home/baris-f/rendu/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Dec 26 17:27:16 2015 Florent Baris
** Last update Wed Jan 13 14:32:45 2016 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include <stdio.h>
#include "../inc/wolf.h"

t_bunny_response        tekkey(t_bunny_event_state state, t_bunny_keysym key,
			       void *_void)
{
  t_pass *pass;

  pass = (t_pass*)_void;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (key == BKS_RIGHT && state == GO_DOWN && pass->nb < 6)
    pass->nb++;
  else if (key == BKS_LEFT && state == GO_DOWN && pass->nb > 0)
    pass->nb--;
  else if (key == BKS_R && state == GO_DOWN)
    pass->rand = rand() | BLACK;
  return (GO_ON);
}

t_bunny_response	update(void *_void)
{
  t_pass		*pass;
  t_pos			pos[1];

  pos->x = IMG_WIDTH / 2;
  pos->y = IMG_HEIGHT / 2;
  pass = (t_pass*)_void;
  tekfill(pass->img, 0xFFEEEEEE);
  pass->fill = 1;
  triangle(pass, pos, 1, 500);
  pass->fill = 0;
    mort(pass, pos, 1, 1000);
  if (pass->col == 0xFFFFFFFF)
    pass->way = 1;
  else if (pass->col == 0xFF000000)
    pass->way = 0;
  if (pass->way == 1)
    pass->col -= 0x00111111;
  else
    pass->col += 0x00111111;
  bunny_blit(&(pass->win->buffer), &(pass->img->clipable), &pass->pos[0]);
  bunny_display(pass->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_pass		pass[1];
  int			x;
  int			y;

  if (ac != 1)
    return (write(1, "Usage: ./mort\n", 18) * 0 - 1);
  x = (ac != 4) ? IMG_WIDTH : my_getnbr(av[1]);
  y = (ac != 4) ? IMG_HEIGHT : my_getnbr(av[2]);
  if ((pass->win = bunny_start(x, y, 0, "SpiderWeb")) == NULL)
    return (0);
  if ((pass->img = bunny_new_pixelarray(x, y)) == NULL)
    return (0);
  pass->nb = 0;
  pass->col = 0xFFFFFFFF;
  pass->rand = rand() | BLACK;
  pass->pos->x = 0;
  pass->pos->y = 0;
  pass->way = 0;
  bunny_set_loop_main_function(update);
  bunny_set_key_response(tekkey);
  pass->ini->init = 0;
  bunny_loop(pass->win, 150, pass);
  bunny_delete_clipable(&pass->img->clipable);
  bunny_stop(pass->win);
  return (0);
}
