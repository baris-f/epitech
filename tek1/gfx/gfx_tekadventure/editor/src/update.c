/*
** update.c for ejoz in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 22:35:51 2016 Gaspard Thirion
** Last update Wed Apr 20 23:42:24 2016 Gaspard Thirion
*/

#include "engine.h"

t_resp		update(void *_v)
{
  t_main	*_m;

  _m = (t_main *)_v;
  fill(_m->mimg, WHITE);
  draw(_m, _m->map.img);
  draw_nodes(_m);
  draw_lines(_m);
  if (_m->map.mov != -1)
    draw_gui(_m);
  bunny_blit(&(_m->mwin->buffer), &(_m->mimg->clipable), &(_m->mpos));
  bunny_display(_m->mwin);
  return (GO_ON);
}
