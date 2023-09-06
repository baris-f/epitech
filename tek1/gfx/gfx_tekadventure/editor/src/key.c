/*
** control.c for sfi in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 22:53:00 2016 Gaspard Thirion
** Last update Wed Apr 20 23:29:50 2016 Gaspard Thirion
*/

#include "engine.h"

void		sw(t_state state, t_key key, t_main *_m)
{
  t_node	*nod;

  nod = &_m->map.node[_m->map.mov];
  if (key == _m->keys[1] && state == GO_UP)
    (nod->act_text)--;
  else if (key == _m->keys[2] && state == GO_UP)
    (nod->act_text)++;
  if (nod->act_text < 0)
    nod->act_text = _m->nb_text;
  else if (nod->act_text > _m->nb_text)
    nod->act_text = 0;
}

t_resp		keyboard(t_state state, t_key key, void *_v)
{
  t_main	*_m;

  _m = (t_main*)_v;
  if (key == _m->keys[0] && state == GO_UP)
    return (EXIT_ON_SUCCESS);
  else if (key == BKS_UP && state == GO_DOWN)
    _m->map.pos.y -= 3;
  else if (key == BKS_DOWN && state == GO_DOWN)
    _m->map.pos.y += 3;
  else if (key == BKS_LEFT && state == GO_DOWN)
    _m->map.pos.x -= 3;
  else if (key == BKS_RIGHT && state == GO_DOWN)
    _m->map.pos.x += 3;
  _m->map.img->pos = _m->map.pos;
  if (_m->map.mov != -1)
    sw(state, key, _m);
  return (GO_ON);
}
