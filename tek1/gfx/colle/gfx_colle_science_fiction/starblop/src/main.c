/*
** main.c for flo in /home/baris-f/rendu/gfx/colle/gfx_colle_science_fiction/boarg
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri May 20 09:16:47 2016 Florent Baris
** Last update Fri May 20 11:54:39 2016 Florent Baris
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
int                             init(t_main *_m)
{
  int   i;

  if ((_m->mwin = bunny_start(1420, 800, 0, "colle4")) == NULL)
    return (-1);
  if ((_m->mimg = bunny_new_pixelarray(1420, 800)) == NULL)
    return (-1);
  if ((_m->fond = bunny_load_pixelarray("intrepid.png")) == NULL)
    return (-1);
  _m->col = 0xff000000;
  _m->clock = 0;
  _m->mimg->clipable.buffer.height = 800 - 1;
  _m->mimg->clipable.buffer.width = 1420 - 1;
  i = -1;
  _m->idx = _m->fond->clipable.clip_width - 10;
  while (++i < 50)
    {
      _m->star[i].x = rand() % 1420;
      _m->star[i].y = rand() % 800;
      _m->star[i].x_speed = -1;
    }
  _m->dpos.x = _m->fond->clipable.clip_width;
  _m->dpos.y = _m->fond->clipable.clip_height;
  _m->spos.x = - _m->fond->clipable.clip_width;
  _m->spos.y = 400 - _m->fond->clipable.clip_height / 2;
  _m->fpos = set2D(_m->spos, 0, 0, 0);
  _m->sens = 1;
  _m->pass = 1;
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

  if (init(&_m) == -1 || (_m.mu = bunny_load_music("voyager.ogg")) == NULL)
    return (-1);
  bunny_set_loop_main_function(&update);
  _m.mpos.x = 0;
  _m.mpos.y = 0;
  bunny_sound_play(&_m.mu->sound);
  bunny_loop(_m.mwin, 255, &_m);
  clean(&_m);
  return (0);
}
