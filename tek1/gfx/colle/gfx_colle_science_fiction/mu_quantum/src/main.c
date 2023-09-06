/*
** main.c for sjof in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 15 22:01:46 2016 Gaspard Thirion
** Last update Tue May 17 15:05:15 2016 Florent Baris
*/

#include "engine.h"

t_bunny_response                key(t_bunny_event_state state,
				    t_bunny_keysym key,
				    void *data)
{
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int                             init(t_main *_m)
{
  int   i;

  if ((_m->mwin = bunny_start(1420, 800, 0, "colle1")) == NULL)
    return (-1);
  if ((_m->mimg = bunny_new_pixelarray(1420, 800)) == NULL)
    return (-1);
  if ((_m->fond = bunny_load_pixelarray("decor.png")) == NULL)
    return (-1);
  if ((_m->scott = bunny_load_pixelarray("scott.png")) == NULL)
    return (-1);
  _m->spos.x = 1420 - 407;
  _m->spos.y = 800 - 343;
  bunny_set_key_response(&key);
  return (0);
}

t_resp		clean(t_main *_m)
{
  bunny_stop(_m->mwin);
  bunny_delete_clipable(&(_m->mimg->clipable));
  bunny_delete_sound(&_m->mu->sound);
  return (EXIT_ON_SUCCESS);
}

int		main(int ac, char **av)
{
  t_main	_m;

  if (init(&_m) == -1 || (_m.mu = bunny_load_music("quantumleap.ogg")) == NULL)
    return (-1);
  bunny_set_loop_main_function(&update);
  _m.mpos.x = 0;
  _m.mpos.y = 0;
  bunny_sound_play(&_m.mu->sound);
  bunny_loop(_m.mwin, 255, &_m);
  clean(&_m);
  return (0);
}
