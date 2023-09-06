/*
** player.c for player in /home/baris-f/rendu/gfx/gfx_tekadventure/final
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Apr 21 12:34:05 2016 Florent Baris
** Last update Thu Apr 21 14:04:12 2016 Florent Baris
*/

#include "engine.h"

void    draw_player(t_main *_m)
{
  _m->player.idle->sens = _m->player.sens;
  _m->player.walk->sens = _m->player.sens;
  move(_m);
  if (_m->player.mov == 1)
    draw(_m, _m->player.walk, _m->player.pos.x, _m->player.pos.y);
  else
    draw(_m, _m->player.idle, _m->player.pos.x, _m->player.pos.y);
}
