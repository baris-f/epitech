/*
** check.c for check in /home/baris-f/rendu/gfx/gfx_tekadventure/baris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Apr  1 18:23:53 2016 Florent Baris
** Last update Tue Apr 19 15:00:08 2016 Gaspard Thirion
*/

#include "engine.h"

int	managebut(t_main *_m, int but)
{
  if (_m->map.mov == -1 || but == -1)
    return (0);
  if (but == 0 &&  _m->map.node[_m->map.mov].scale.x > 1)
    _m->map.node[_m->map.mov].scale.x--;
  else if (but == 1)
    _m->map.node[_m->map.mov].scale.x++;
  else if (but == 2 &&  _m->map.node[_m->map.mov].scale.y > 1)
    _m->map.node[_m->map.mov].scale.y--;
  else if (but == 3)
    _m->map.node[_m->map.mov].scale.y++;
  else if (but == 4 && _m->map.node[_m->map.mov].depth > 0)
    _m->map.node[_m->map.mov].depth--;
  else if (but == 5 && _m->map.node[_m->map.mov].depth < 100)
    _m->map.node[_m->map.mov].depth++;
  else if (but == 6)
    delete_node(_m, _m->map.mov);
  else if (but >= 7 && but <= 10)
    _m->map.node[_m->map.mov].type = but - 7;
  else if (but == 13)
    _m->map.node[_m->map.mov].full = NBOOL(_m->map.node[_m->map.mov].full);
  return (0);
}

int	inbut(t_main *_m, t_2D pos)
{
  int   i;

  i = -1;
  while (++i < NB_BUT)
    if (_m->gui.but[i].pos[0].x > -1 &&
	pos.x >= _m->gui.pos[0].x + _m->gui.but[i].pos[0].x
	&& pos.x <= _m->gui.pos[0].x + _m->gui.but[i].pos[1].x
	&& pos.y >= _m->gui.pos[0].y + _m->gui.but[i].pos[0].y
	&& pos.y <= _m->gui.pos[0].y + _m->gui.but[i].pos[1].y)
      {
	_m->gui.butt = i;
	return (0);
      }
  return (-1);
}

int	innode(t_main *_m, t_2D pos)
{
  int	i;

  i = -1;
  while (++i < NB_NODE)
    if (_m->map.node[i].pos.x > -1 &&
	pos.x >= _m->map.pos.x + _m->map.node[i].pos.x
	- _m->map.node[i].scale.x
	&& pos.x <= _m->map.pos.x + _m->map.node[i].pos.x
	+ _m->map.node[i].scale.x
	&& pos.y >= _m->map.pos.y + _m->map.node[i].pos.y
	- _m->map.node[i].scale.y
	&& pos.y <= _m->map.pos.y + _m->map.node[i].pos.y
	+ _m->map.node[i].scale.y)
      return (i);
  return (-1);
}

int	inmap(t_main *_m, t_2D pos)
{
  if (pos.x < _m->map.pos.x
      || pos.x > _m->map.pos.x
      + (int)(_m->map.img->scale.x * _m->map.img->dim.x)
      || pos.y < _m->map.pos.y
      || pos.y > _m->map.pos.y
      + (int)(_m->map.img->scale.y * _m->map.img->dim.y))
    return (0);
  return (1);
}
