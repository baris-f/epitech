/*
** draw.c for comb in /home/baris-f/rendu/gfx/gfx_tekadventure/bascombat
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Apr 11 22:06:11 2016 Florent Baris
** Last update Fri Apr 22 09:49:11 2016 Florent Baris
*/

#include "engine.h"

void	init_fight(t_main *_m)
{
  float max;
  t_2D	psize;

  psize.x = _m->player.idle->dim.x * _m->player.idle->scale.x;
  psize.y = _m->player.idle->dim.y * _m->player.idle->scale.y;
  /* max = MAX((float)_m->s.x / _m->fight.back->clipable.clip_width, */
  /* 	    (float)_m->s.y / _m->fight.back->clipable.clip_height); */
  /* _m->fight.back->clipable.scale.x = max; */
  /* _m->fight.back->clipable.scale.y = max; */
  max = MIN((_m->s.x / 4) / psize.x,
	    (_m->s.x / 4) / psize.y);
  _m->player.scale.x = max;
  _m->player.scale.y = max;
  _m->player.size.x = max * psize.x;
  _m->player.size.y = max * psize.y;
  _m->fight.size = _m->player.size;
}

void	draw_guys(t_main *_m)
{
  t_2D	pos;

  pos.x = _m->s.x / 8;
  pos.y = _m->s.y / 3;
  _m->player.pos = pos;
  if (_m->player.a == 0)
    draw(_m, _m->player.idle, pos.x, pos.y);
  else
    draw(_m, _m->player.atk, pos.x, pos.y);
  pos.x += _m->sh.x;
  _m->fight.pos = pos;
  _m->fight.idle->sens = 0;
  _m->fight.atk->sens = 0;
  if (_m->fight.turn % 2 != 0)
    draw(_m, _m->fight.idle, pos.x, pos.y);
  else
    {
      _m->player.a = 0;
      draw(_m, _m->fight.atk, pos.x, pos.y);
    }
}

void	aff_dmg(t_main *_m, int dmgg, int playerr)
{
  static t_2D pos = {-1, -1};
  static int dmg = 0;
  static int player = 0;

  _m->fight.affdmg = 1;
  _m->font[0].size += 2;
  if (pos.x == -1)
    {
      dmg = dmgg;
      player = playerr;
      if (player)
	{
	  pos.x = _m->player.pos.x + _m->player.size.x / 2;
	  pos.y = _m->player.pos.y + _m->player.size.y / 10;
	}
      else
	{
	  pos.x = _m->fight.pos.x + _m->fight.size.x / 2;
	  pos.y = _m->fight.pos.y + _m->fight.size.y / 10;
	}
    }
  if (player)
    _m->font->col = ((dmg > 0) ? (GREEN) :(RED)) - 0x07000000
      * (_m->player.pos.y + _m->player.size.y / 10 - pos.y);
  else
    _m->font->col = ((dmg > 0) ? (GREEN) :(RED)) - 0x07000000
      * (_m->fight.pos.y + _m->fight.size.y / 10 - pos.y);
  printl(_m->mimg, _m->font, pos, "%d", dmg);
  _m->font->col = BLACK;
  pos.y--;
  if ((player && pos.y < _m->player.pos.y + _m->player.size.y / 10 - 30)
      || (!player && pos.y < _m->fight.pos.y + _m->fight.size.y / 10 - 30))
    {
      pos.x = -1;
      _m->fight.affdmg = 0;
      _m->fight.turn++;
      if (_m->fight.turn % 2 != 0)
	{
	  if (_m->player.spe > 0)
	    _m->player.spe--;
	}
      if (_m->fight.life <= 0)
	_m->fight.end = 2;
      if (_m->player.life <= 0)
	_m->fight.end = 1;
    }
  _m->font[0].size -= 2;
}

void	manage_fight(t_main *_m)
{
  int	dmg;

  if (_m->fight.turn % 2 == 0 && _m->fight.affdmg == 0)
    {
      dmg = -(_m->fight.dmg - 2 + rand() % 5);
      aff_dmg(_m, dmg, 1);
      _m->player.life += dmg;
    }
}

void	aff_end(t_main *_m)
{
  t_2D	tmp;

  _m->font[0].size += 2;
  tmp.x = _m->sh.x - ((_m->font[0].scale.x *
       _m->font[0].size + _m->font[0].marge.x + 1) * 8) / 2;
  tmp.y = _m->sh.y -
    (_m->font[0].scale.y * _m->font[0].size) / 2;
  if (_m->fight.end == 1)
    printl(_m->mimg, _m->font, tmp, "YOU LOST");
  else
    printl(_m->mimg, _m->font, tmp, "YOU WON");
  _m->font[0].size -= 2;
}

int	draw_fight(t_main *_m)
{
  if (_m->fight.end > 0)
    {
      if (_m->fight.tend == -1)
	_m->fight.tend = (int)_m->clock;
      if (_m->fight.tend > -1 && (int)_m->clock - 30 > _m->fight.tend)
	{
	  _m->map[_m->i].node[_m->player.pnod].type = 0;
	  _m->fight.tend = -1;
	  _m->fight.init = 0;
	  _m->player.idle->scale = set2D(_m->s, 2, 2, 1);
	  _m->player.walk->scale = set2D(_m->s, 2, 2, 1);
	  _m->player.size.x = _m->player.idle->dim.x * _m->player.idle->scale.x;
	  _m->player.size.y = _m->player.idle->dim.y * _m->player.idle->scale.y;
	  _m->player.pos.x = _m->map[_m->i].node[_m->player.pnod].pos.x - _m->player.size.x / 2;
	  _m->player.pos.y = _m->map[_m->i].node[_m->player.pnod].pos.y - _m->player.size.y * 2 / 3;
	  _m->fight.turn = 1;
	  _m->fight.affdmg = 0;
	  _m->player.spe = 0;
	  _m->fight.life = 100 - rand() % 30;
	  _m->fight.end = 0;
	}
      if (_m->fight.end == 1)
	return (-1);
      aff_end(_m);
      return (0);
    }
  (_m->player.life < 0) ? (_m->player.life = 0) : (0);
  (_m->fight.life < 0) ? (_m->fight.life = 0) : (0);
  init_fight(_m);
  draw_guys(_m);
  draw_gui(_m);
  manage_fight(_m);
  if (_m->fight.affdmg == 1)
    aff_dmg(_m, 0, 0);
  return (0);
}
