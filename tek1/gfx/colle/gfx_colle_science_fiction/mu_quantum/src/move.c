/*
** move.c for tekadv in /home/baris-f/rendu/gfx/gfx_tekadventure/final
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Apr 19 19:25:52 2016 Florent Baris
** Last update Fri Apr 22 00:27:51 2016 Gaspard Thirion
*/

#include "engine.h"

/* t_2D	getnextnod(t_main *_m) */
/* { */
  /* t_2D       size; */
  /* t_2D       goal; */
  /* int		i; */

  /* i = -1; */
  /* size.x = _m->player.idle->dim.x * _m->player.idle->scale.x; */
  /* size.y = _m->player.idle->dim.y * _m->player.idle->scale.y; */
  /* goal.x = _m->map[_m->i].node[_m->player.nod].pos.x - size.x / 2; */
  /* goal.y = _m->map[_m->i].node[_m->player.nod].pos.y - size.y * 2 / 3; */
/* } */

void	move(t_main *_m)
{
  int	mov;
  if (_m->path[0] - 1> 0 && _m->player.pnod == _m->path[_m->path[0]])
    {
      _m->path[0]--;
      _m->player.nod = _m->path[_m->path[0]];
    }
  if (_m->player.nod != _m->player.pnod && _m->player.tocent == 0)
    {
      if ((mov = (movin(_m, _m->map[_m->i].node[_m->player.pnod].pos))) == 0)
	_m->player.tocent = 1;
      _m->player.mov = mov;
      return ;
    }
  if (_m->player.nod == _m->player.pnod
      && innode(_m, _m->mouse[1]) == _m->player.pnod)
    {
      mov = movin(_m, _m->mouse[1]);
      _m->player.tocent = 0;
    }
  else
    {
      if (_m->map[_m->i].node[_m->player.pnod].link[_m->player.nod] != -1)
	mov = movout(_m);
      else
	mov = 0;
    }
  if (_m->player.nod != _m->player.pnod
      && _m->map[_m->i].node[_m->player.pnod].link[_m->player.nod] != -1
      && mov == 0)
    _m->player.pnod = _m->player.nod;
  _m->player.mov = mov;
}

int	movin(t_main *_m, t_2D pos)
{
  t_2D	goal;
  t_2D	s;

  goal.x = pos.x -
    (_m->player.idle->dim.x * _m->player.idle->scale.x) / 2;
  goal.y = pos.y -
    (_m->player.idle->dim.y * _m->player.idle->scale.y) * 2 / 3;
  s.x = ((_m->player.pos.x - goal.x > 0) ? (-1) : (1));
  s.y = ((_m->player.pos.y - goal.y > 0) ? (-1) : (1));
  _m->player.sens = (s.x == -1) ? (0) : (s.x);
  if (_m->player.pos.x != goal.x || _m->player.pos.y != goal.y)
    {
      if (_m->player.pos.y != goal.y)
	_m->player.pos.y += s.y;
      if (_m->player.pos.x != goal.x)
	_m->player.pos.x += s.x;
      return (1);
    }
  return (0);
}

void	init_move(t_main *_m, t_2D *goal, t_2D *d, t_2D *s)
{
  goal->x = _m->map[_m->i].node[_m->player.nod].pos.x -
    (_m->player.idle->dim.x * _m->player.idle->scale.x) / 2;
  goal->y = _m->map[_m->i].node[_m->player.nod].pos.y -
    (_m->player.idle->dim.y * _m->player.idle->scale.y) * 2 / 3;
  s->x = ((_m->player.pos.x - goal->x > 0) ? (-1) : (1));
  s->y = ((_m->player.pos.y - goal->y > 0) ? (-1) : (1));
  d->x = _m->player.pos.x - goal->x;
  d->x = ABS(d->x);
  d->y = _m->player.pos.y - goal->y;
  d->y = ABS(d->y);
  _m->player.sens = (s->x == -1) ? (0) : (s->x);
}

int	walking(t_main *_m, t_2D goal, t_2D s)
{
  if (_m->player.pos.x == goal.x)
    {
      if(_m->player.pos.y != goal.y)
	{
	  if (ABS(_m->player.pos.y - goal.y) == 1)
	    _m->player.pos.y += s.y;
	  else
	    _m->player.pos.y += 2 * s.y;
	  return (1);
	}
      else
	return (0);
    }
  else if (_m->player.pos.y == goal.y)
    {
      if(_m->player.pos.x != goal.x)
	{
	  if (ABS(_m->player.pos.x - goal.x) == 1)
	    _m->player.pos.y += s.x;
	  else
	    _m->player.pos.x += 2 * s.x;
	  return (1);
	}
      else
	return (0);
    }
  return (0);
}

int	movout(t_main *_m)
{
  t_2D		goal;
  t_2D		d;
  t_2D		s;
  float		cof;

  init_move(_m, &goal, &d, &s);
  if (_m->player.pos.x == goal.x || _m->player.pos.y == goal.y)
    return (walking(_m, goal, s));
  cof = (float)(_m->player.pos.x - goal.x) / (float)(_m->player.pos.y - goal.y);
  if (d.x <= (int)(ABS(cof) * 2))
    _m->player.pos.x += s.x;
  else if (_m->player.pos.x != goal.x)
    _m->player.pos.x += ABS(cof) * 2 * s.x;
  cof = (float)1 / cof;
  if (d.y <= (int)(ABS(cof) * 2))
    _m->player.pos.y += s.y;
  else if (_m->player.pos.y != goal.y)
    _m->player.pos.y += ABS(cof) * 2 * s.y;
  return (1);
}
