/*
** init.c for init in /home/baris-f/rendu/gfx/gfx_tekadventure/baris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Apr 10 18:54:20 2016 Florent Baris
** Last update Thu Apr 21 22:45:34 2016 Florent Baris
*/

#include "engine.h"

void    init_but1(t_main *_m, int but, int x, int y)
{
  _m->gui.but[but].pos[0].x = x;
  _m->gui.but[but].pos[0].y = y;
}

void    init_but2(t_main *_m, int but, int x, int y)
{
  _m->gui.but[but].pos[1].x = _m->gui.but[but].pos[0].x + x;
  _m->gui.but[but].pos[1].y = _m->gui.but[but].pos[0].y + y;
}

void	setbut(t_main *_m)
{
  init_but1(_m, 0, 20, 20);
  init_but2(_m, 0, _m->gui.scale.x / 2 - 20, _m->gui.scale.y / 2 - 30);
  _m->gui.but[0].text = my_strdup("ATTACK");
  init_but1(_m, 1,  _m->gui.scale.x / 2 + 20, 20);
  init_but2(_m, 1, _m->gui.scale.x / 2 - 40, _m->gui.scale.y / 2 - 30);
  _m->gui.but[1].text = my_strdup("SPECIAL");
  init_but1(_m, 2, 20, _m->gui.scale.y / 2 + 10);
  init_but2(_m, 2, _m->gui.scale.x / 2 - 20, _m->gui.scale.y / 2 - 30);
  _m->gui.but[2].text = my_strdup("USE POTION");
  init_but1(_m, 3,  _m->gui.scale.x / 2 + 20, _m->gui.scale.y / 2 + 10);
  init_but2(_m, 3, _m->gui.scale.x / 2 - 40, _m->gui.scale.y / 2 - 30);
  _m->gui.but[3].text = my_strdup("FAST MODE");
}

void    setgui(t_main *_m)
{
  int	i;

  _m->fight.back = new_sprite(_m, "floor");
  _m->gui.pos[0].x = _m->s.x / 4;
  _m->gui.pos[0].y = _m->s.y * 3 / 4;
  _m->gui.pos[1].x = _m->s.x - (_m->s.x / 4);
  _m->gui.pos[1].y = _m->s.y - (_m->s.y / 20);
  _m->gui.scale.x = _m->gui.pos[1].x - _m->gui.pos[0].x;
  _m->gui.scale.y = _m->gui.pos[1].y - _m->gui.pos[0].y;
  _m->gui.pos[0].x = _m->s.x / 4;
  _m->gui.scroll[0] = set2D(_m->s, -1, -1, 1);
  _m->gui.ssize = set2D(_m->s, 150, 200, 1);
  _m->gui.scroll[1] = set2D(_m->gui.scroll[0], _m->gui.ssize.x, _m->gui.ssize.y, 0);
  _m->gui.pos[1].x = _m->s.x - (_m->s.x / 4);
  _m->gui.pos[1].y = _m->s.y - (_m->s.y / 20);
  _m->gui.scale.x = _m->gui.pos[1].x - _m->gui.pos[0].x;
  _m->gui.scale.y = _m->gui.pos[1].y - _m->gui.pos[0].y;
  _m->gui.in = 0xffdddddd;
  _m->gui.out = 0xff999999;
  _m->fight.turn = 1;
  _m->fight.end = 0;
  _m->fight.blit = 1;
  _m->fight.affdmg = 0;
  _m->fight.init = 0;
  _m->player.spe = 0;
  _m->player.tocent = 1;
  i = -1;
  while (++i < NB_BUT)
    {
      _m->gui.but[i].pos[0].x = -1;
      _m->gui.but[i].text = NULL;
    }
  setbut(_m);
  init_fight(_m);
}
