/*
** init.c for init in /home/baris-f/rendu/gfx/gfx_tekadventure/baris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Apr 10 18:54:20 2016 Florent Baris
** Last update Wed Apr 20 22:31:40 2016 Gaspard Thirion
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

void	typebut(t_main *_m)
{
  init_but1(_m, 7, 20, _m->gui.scale.y - 220);
  init_but2(_m, 7, _m->gui.scale.x / 2 - 20, 50);
  _m->gui.but[7].text = my_strdup("MOVEMENT");
  init_but1(_m, 8, _m->gui.scale.x / 2, _m->gui.scale.y - 220);
  init_but2(_m, 8, _m->gui.scale.x / 2 - 20, 50);
  _m->gui.but[8].text = my_strdup("TOWN");
  init_but1(_m, 9, 20, _m->gui.scale.y - 170);
  init_but2(_m, 9, _m->gui.scale.x / 2 - 20, 50);
  _m->gui.but[9].text = my_strdup("FIGHT");
  init_but1(_m, 10, _m->gui.scale.x / 2, _m->gui.scale.y - 170);
  init_but2(_m, 10, _m->gui.scale.x / 2 - 20, 50);
  _m->gui.but[10].text = my_strdup("SHOP");
  init_but1(_m, 13, 20, _m->gui.scale.y - 320);
  init_but2(_m, 13, _m->gui.scale.x - 40, 80);
  _m->gui.but[13].text = my_strdup("SET/UNSET FULL");

}

void	setbut(t_main *_m)
{
  init_but1(_m, 0, 20, 100);
  init_but2(_m, 0, 70, 50);
  _m->gui.but[0].text = my_strdup("-");
  init_but1(_m, 1, _m->gui.scale.x - 90, 100);
  init_but2(_m, 1, 70, 50);
  _m->gui.but[1].text = my_strdup("+");
  init_but1(_m, 2, 20, 170);
  init_but2(_m, 2, 70, 50);
  _m->gui.but[2].text = my_strdup("-");
  init_but1(_m, 3, _m->gui.scale.x - 90, 170);
  init_but2(_m, 3, 70, 50);
  _m->gui.but[3].text = my_strdup("+");
  init_but1(_m, 4, 20, 240);
  init_but2(_m, 4, 70, 50);
  _m->gui.but[4].text = my_strdup("-");
  init_but1(_m, 5, _m->gui.scale.x - 90, 240);
  init_but2(_m, 5, 70, 50);
  _m->gui.but[5].text = my_strdup("+");
  init_but1(_m, 6, 20, _m->gui.scale.y - 100);
  init_but2(_m, 6, _m->gui.scale.x - 40, 80);
  _m->gui.but[6].text = my_strdup("DELETE");
  typebut(_m);
}

void    setgui(t_main *_m)
{
  int	i;
  int	j;

  _m->gui.pos[0].x = WIN_W - (WIN_W / 4);
  _m->gui.pos[0].y = WIN_H / 20;
  _m->gui.pos[1].x = WIN_W - (WIN_W / 40);
  _m->gui.pos[1].y = WIN_H - (WIN_H / 20);
  _m->gui.scale.x = _m->gui.pos[1].x - _m->gui.pos[0].x;
  _m->gui.scale.y = _m->gui.pos[1].y - _m->gui.pos[0].y;
  _m->gui.in = 0xffdddddd;
  _m->gui.out = 0xff999999;
  i = -1;
  while (++i < NB_NODE)
    {
      j = -1;
      _m->map.node[i].act_text = 0;
      _m->map.node[i].pos.x = -1;
      _m->map.node[i].scale.x = 10;
      _m->map.node[i].scale.y = 10;
      _m->map.node[i].type = 0;
      _m->map.node[i].depth = 50;
      _m->map.node[i].full = 1;
      while (++j < NB_NODE)
	_m->map.node[i].link[j] = -1;
    }
  setbut(_m);
}
