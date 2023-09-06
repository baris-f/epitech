/*
** main.c for main in /home/baris-f/rendu/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Dec 26 17:27:16 2015 Florent Baris
** Last update Wed Jan  6 10:45:43 2016 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include "../inc/wolf.h"

void	tekkey2(t_bunny_keysym key, t_pass *pass, t_pos dpos)
{
  if (key == BKS_S && whereami(pass, 2) == 0)
   {
     pass->player->pos.x -= dpos.x;
     pass->player->pos.y -= dpos.y;
   }
 else if (key == BKS_Q && whereami(pass, 3) == 0)
   {
     pass->player->pos.x += dpos.y;
     pass->player->pos.y -= dpos.x;
   }
 else if (key == BKS_D && whereami(pass, 4) == 0)
   {
     pass->player->pos.x -= dpos.y;
     pass->player->pos.y += dpos.x;
   }
}

t_bunny_response        tekkey(t_bunny_event_state state, t_bunny_keysym key,
			       void *_void)
{
  t_pass        *pass;
  t_pos		dpos;

  polcar(&dpos, pass->player->ang, 5);
  pass = (t_pass*)_void;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (key == BKS_RIGHT)
    pass->player->ang -= 2;
  else if (key == BKS_LEFT)
    pass->player->ang += 2;
  else if (key == BKS_Z && whereami(pass, 1) == 0)
    {
      pass->player->pos.x += dpos.x;
      pass->player->pos.y += dpos.y;
    }
  else
    tekkey2(key, pass, dpos);
  return (GO_ON);
}

t_bunny_response	update(void *_void)
{
  t_pass		*pass;

  pass = (t_pass*)_void;
  tekfillhalf(pass->img, BLUE, 1);
  tekfillhalf(pass->img, 0xFF003366, 2);
  raycast(pass);
  map(pass);
  if (pass->player->ang < 0)
    pass->player->ang = 359;
  proj(pass);
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
    return (write(1, "Usage: ./wolf map\n", 18) * 0 - 1);
  x = (ac != 4) ? IMG_WIDTH : my_getnbr(av[1]);
  y = (ac != 4) ? IMG_HEIGHT : my_getnbr(av[2]);
  if ((pass->win = bunny_start(x, y, 0, "Wolf3D")) == NULL)
    return (0);
  if ((pass->img = bunny_new_pixelarray(x, y)) == NULL)
    return (0);
  pass->pos->x = 0;
  pass->pos->y = 0;
  bunny_set_loop_main_function(update);
  bunny_set_key_response(tekkey);
  pass->ini->name = av[1];
  pass->fill = 0;
  pass->ini->init = 0;
  if (wolfini(pass) == 1)
    return (write(1, "load ini failed\n", 16));
  bunny_loop(pass->win, 150, pass);
  bunny_delete_clipable(&pass->img->clipable);
  bunny_stop(pass->win);
  return (0);
}
