/*
** update.c for ejoz in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 22:35:51 2016 Gaspard Thirion
** Last update Fri Apr 22 10:14:52 2016 Florent Baris
*/

#include "engine.h"

void	drawmap(t_main *_m)
{
  fill(_m->mimg, BLACK);
  draw(_m, _m->map[_m->i].back, 0, 0);
  draw_nodes(_m);
  draw_lines(_m);
  draw_player(_m);
  affscroll(_m);
}

int	fight(t_main *_m)
{
  if (_m->fight.init == 0)
    {
      _m->player.idle->scale = set2D(_m->s, 6, 6, 1);
      _m->player.walk->scale = set2D(_m->s, 6, 6, 1);
      _m->player.sens = 0;
      _m->fight.init = 1;
      _m->gui.pos[0].x = _m->s.x / 4;
      _m->gui.pos[0].y = _m->s.y * 3 / 4;
      _m->gui.pos[1].x = _m->s.x - (_m->s.x / 4);
      _m->gui.pos[1].y = _m->s.y - (_m->s.y / 20);
      _m->gui.scale.x = _m->gui.pos[1].x - _m->gui.pos[0].x;
      _m->gui.scale.y = _m->gui.pos[1].y - _m->gui.pos[0].y;
    }
  fill(_m->mimg, WHITE);
  if (draw_fight(_m) == -1)
    return (-1);
  return (0);
}

t_resp		update(void *_v)
{
  t_main	*_m;

  _m = (t_main *)_v;
  _m->clock += 0.4;
  if (bunny_music_get_cursor(_m->mu) >= _m->mu->duration)
    bunny_sound_play(&_m->mu->sound);
  if (_m->map[_m->i].node[_m->player.pnod].type == 2 && _m->player.mov == 0)
    {
      if (fight(_m) == -1)
	return (EXIT_ON_SUCCESS);
    }
  else
    drawmap(_m);
  BLIT;
  bunny_display(_m->mwin);
  return (GO_ON);
}
