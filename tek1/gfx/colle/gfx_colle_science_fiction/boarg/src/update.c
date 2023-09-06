/*
** update.c for ejoz in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 22:35:51 2016 Gaspard Thirion
** Last update Fri May 20 11:00:07 2016 Florent Baris
*/

#include "engine.h"

void	extend (t_main *_m)
{
  int	i;

  i = -1;
  while (++i < 8)
    {
      if (i == 0 || i == 5)
	{
	  _m->cpos[i].x--;
	  _m->cpos[i].y--;
	}
      else if (i == 1 || i == 6)
	{
	  _m->cpos[i].x--;
	  _m->cpos[i].y++;
	}
      else if (i == 2 || i == 7)
	{
	  _m->cpos[i].x++;
	  _m->cpos[i].y++;
	}
      else if (i == 3 || i == 4)
	{
	  _m->cpos[i].x++;
	  _m->cpos[i].y--;
	}
    }
}

void	rotate(t_main *_m)
{
    int	i;

  i = -1;
  while (++i < 7)
    {
      if (i == 5 || i == 6)
	{
	  _m->cpos[i].x++;
	  if (_m->sens)
	    _m->cpos[i].y--;
	  else
	    _m->cpos[i].y++;
	}
      else if (i == 2 || i == 3)
	{
	  _m->cpos[i].x--;
	  if (_m->sens)
	    _m->cpos[i].y++;
	  else
	    _m->cpos[i].y--;
	}
    }
}

void	cube(t_main *_m)
{
  int	i;

  i = -1;
  while (++i < 7)
    line(_m->mimg, _m->cpos[i], _m->cpos[i + 1], GREEN);
  line(_m->mimg, _m->cpos[0], _m->cpos[5], GREEN);
  line(_m->mimg, _m->cpos[1], _m->cpos[6], GREEN);
  line(_m->mimg, _m->cpos[2], _m->cpos[7], GREEN);
  line(_m->mimg, _m->cpos[0], _m->cpos[3], GREEN);
  line(_m->mimg, _m->cpos[4], _m->cpos[7], GREEN);
}

t_resp		update(void *_v)
{
  t_main	*_m;

  _m = (t_main *)_v;
  _m->clock += 0.4;
  if (bunny_music_get_cursor(_m->mu) >= _m->mu->duration)
    bunny_sound_play(&_m->mu->sound);
  fill(_m->mimg, BLACK);
  if (_m->cpos[5].x > 1420 / 2 && _m->pass)
    {
      _m->pass = 0;
      (_m->sens == 1) ? (_m->sens = 0) : (_m->sens = 1);
    }
  if (_m->cpos[5].x >= _m->cpos[4].x)
    {
      _m->cpos[5].x = _m->cpos[0].x;
      _m->cpos[6].x = _m->cpos[0].x;
      _m->cpos[3].x = _m->cpos[4].x;
      _m->cpos[2].x = _m->cpos[4].x;
      _m->pass = 1;
    }
  if (_m->clock > 60 && _m->clock < 100)
    extend(_m);
  else if (_m->clock > 100)
    rotate(_m);
  if (_m->clock > 55)
    cube(_m);
  blit(_m->mimg, _m->fond, _m->mpos);
  if (_m->col != 0x3000000)
    {
      fill(_m->mimg, _m->col);
	_m->col -= 0x04000000;
    }
  bunny_blit(&(_m->mwin->buffer), &(_m->mimg->clipable), &(_m->mpos));
  bunny_display(_m->mwin);
  return (GO_ON);
}
