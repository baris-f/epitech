/*
** main.c for flo in /home/baris-f/rendu/gfx/colle/gfx_colle_science_fiction/boarg
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri May 20 09:16:47 2016 Florent Baris
** Last update Fri May 20 11:01:19 2016 Florent Baris
*/

#include "engine.h"

t_bunny_response                key(t_bunny_event_state state,
				    t_bunny_keysym key,
				    void *data)
{
  (void)data;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void	cinit(t_main *_m)
{
  _m->cpos[0] = set2D(_m->cpos[0], -50, -50, 0);
  _m->cpos[5] = set2D(_m->cpos[5], -50, -50, 0);
  _m->cpos[1] = set2D(_m->cpos[1], -50, 50, 0);
  _m->cpos[6] = set2D(_m->cpos[6], -50, 50, 0);
  _m->cpos[2] = set2D(_m->cpos[2], 50, 50, 0);
  _m->cpos[7] = set2D(_m->cpos[7], 50, 50, 0);
  _m->cpos[3] = set2D(_m->cpos[3], 50, -50, 0);
  _m->cpos[4] = set2D(_m->cpos[4], 50, -50, 0);
}

int                             init(t_main *_m)
{
  int   i;

  if ((_m->mwin = bunny_start(1420, 800, 0, "colle1")) == NULL)
    return (-1);
  if ((_m->mimg = bunny_new_pixelarray(1420, 800)) == NULL)
    return (-1);
  if ((_m->fond = bunny_load_pixelarray("enterprise_d.png")) == NULL)
    return (-1);
  _m->col = 0xff000000;
  _m->clock = 0;
  _m->mimg->clipable.buffer.height = 800 - 1;
  _m->mimg->clipable.buffer.width = 1420 - 1;
  i = -1;
  _m->sens = 1;
  _m->pass = 1;
  while (++i < 8 * 5)
    {
      _m->cpos[i].x = 1420 / 2;
      _m->cpos[i].y = 800 / 2;
    }
  cinit(_m);
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

int		main()
{
  t_main	_m;

  if (init(&_m) == -1 || (_m.mu = bunny_load_music("borg.ogg")) == NULL)
    return (-1);
  bunny_set_loop_main_function(&update);
  _m.mpos.x = 0;
  _m.mpos.y = 0;
  bunny_sound_play(&_m.mu->sound);
  bunny_loop(_m.mwin, 255, &_m);
  clean(&_m);
  return (0);
}
