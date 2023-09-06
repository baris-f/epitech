/*
** control.c for sfi in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 22:53:00 2016 Gaspard Thirion
** Last update Sun Apr 10 12:30:22 2016 Gaspard Thirion
*/

#include "engine.h"

t_resp		keyboard(t_state state, t_key key, void *_v)
{
  t_main	*_m;

  _m = (t_main*)_v;
  if (key == _m->keys[0] && state == GO_UP)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_resp		click(t_state state, t_click button, void *_v)
{
  t_main	*_m;

  _m = (t_main*)_v;
  if (button == 0 && state == GO_UP)
    _m->mpos.x = _m->mpos.x;
  return (GO_ON);
}
