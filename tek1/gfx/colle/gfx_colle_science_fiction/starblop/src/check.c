/*
** check.c for check in /home/baris-f/rendu/gfx/gfx_tekadventure/baris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Apr  1 18:23:53 2016 Florent Baris
** Last update Thu Apr 21 17:03:36 2016 Gaspard Thirion
*/

#include "engine.h"

int	managebut(t_main *_m, int but)
{
  int   dmg;

  if (but == -1)
    return (0);
  if (but == 0)
    {
      dmg = -(_m->player.dmg - 2 + rand() % 5);
      aff_dmg(_m, dmg, 0);
      _m->fight.life += dmg;
    }
  else if (but == 1 && _m->player.spe == 0)
    {
      dmg = -(_m->player.dmg * 3 - 5 + rand() % 11);
      aff_dmg(_m, dmg, 0);
      _m->fight.life += dmg;
      _m->player.spe = 3;
    }
  else if (but == 2 && _m->player.pot > 0)
    {
      aff_dmg(_m, 20, 1);
      _m->player.life += 20;
      (_m->player.life > 100) ? (_m->player.life = 100) : (0);
      _m->player.pot--;
    }
  else if (but == 3)
    _m->fight.blit = NBOOL(_m->fight.blit);
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
  while (++i < _m->map[_m->i].nb_node)
    if (_m->map[_m->i].node[i].pos.x > -1 &&
	pos.x >= _m->map[_m->i].pos.x + _m->map[_m->i].node[i].pos.x
	- _m->map[_m->i].node[i].scale.x
	&& pos.x <= _m->map[_m->i].pos.x + _m->map[_m->i].node[i].pos.x
	+ _m->map[_m->i].node[i].scale.x
	&& pos.y >= _m->map[_m->i].pos.y + _m->map[_m->i].node[i].pos.y
	- _m->map[_m->i].node[i].scale.y
	&& pos.y <= _m->map[_m->i].pos.y + _m->map[_m->i].node[i].pos.y
	+ _m->map[_m->i].node[i].scale.y)
      return (i);
  return (-1);
}

int	inmap(t_main *_m, t_2D pos)
{
  if (pos.x < _m->map[_m->i].pos.x
      || pos.x > _m->map[_m->i].pos.x
      + (int)(_m->map[_m->i].back->scale.x * _m->map[_m->i].back->dim.x)
      || pos.y < _m->map[_m->i].pos.y
      || pos.y > _m->map[_m->i].pos.y
      + (int)(_m->map[_m->i].back->scale.y * _m->map[_m->i].back->dim.y))
    return (0);
  return (1);
}
