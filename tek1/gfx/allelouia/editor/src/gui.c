/*
** gui.c for gui in /home/baris-f/rendu/gfx/gfx_tekadventure/baris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Apr  3 18:52:42 2016 Florent Baris
** Last update Wed Apr 13 16:43:14 2016 Gaspard Thirion
*/

#include "engine.h"

void	draw_button(t_main *_m)
{
  int	i;
  t_2D	tmp[2];

  i = -1;
  while (++i < NB_BUT)
    if (_m->gui.but[i].pos[0].x != -1)
    {
      tmp[0].x = _m->gui.but[i].pos[0].x + _m->gui.pos[0].x;
      tmp[0].y = _m->gui.but[i].pos[0].y + _m->gui.pos[0].y;
      tmp[1].x = _m->gui.but[i].pos[1].x + _m->gui.pos[0].x;
      tmp[1].y = _m->gui.but[i].pos[1].y + _m->gui.pos[0].y;
      if (i - 7 == _m->map.node[_m->map.mov].type)
	draw_box(_m->mimg, tmp, 0xff666666, 1);
      else
	draw_box(_m->mimg, tmp, _m->gui.in, 1);
      draw_box(_m->mimg, tmp, _m->gui.out, 0);
      if (_m->gui.but[i].text != NULL)
	{
	  tmp[0].x += (tmp[1].x - tmp[0].x) / 2 - ((_m->font->scale.x *
   _m->font->size + _m->font->marge.x + 1) * my_strlen(_m->gui.but[i].text)) / 2;
	  tmp[0].y += (tmp[1].y - tmp[0].y) / 2 -
	    (_m->font->scale.y * _m->font->size) / 2;
	  printl(_m->mimg, &(_m->font[0]), tmp[0], "%s", _m->gui.but[i].text);
	}
    }
}

void	draw_guitext(t_main *_m, t_2D tmp)
{
  printl(_m->mimg, &(_m->font[0]), tmp, "X : %d Y : %d",
	 _m->map.node[_m->map.mov].pos.x, _m->map.node[_m->map.mov].pos.y);
  tmp.y += 60;
  tmp.x += 60;
  _m->font->size--;
  printl(_m->mimg, &(_m->font[0]), tmp, "X scale : %d",
	 _m->map.node[_m->map.mov].scale.x);
  tmp.y += 70;
  printl(_m->mimg, &(_m->font[0]), tmp, "Y scale : %d",
	 _m->map.node[_m->map.mov].scale.y);
  tmp.y += 70;
  tmp.x += 8;
  printl(_m->mimg, &(_m->font[0]), tmp, "depth : %d",
	 _m->map.node[_m->map.mov].depth);
  _m->font->size++;
}

void	draw_gui(t_main *_m)
{
  t_2D  tmp;

  tmp.x = _m->gui.pos[0].x + _m->gui.scale.x / 2 -
    (_m->font->scale.x * _m->font->size * 7) / 2;
  tmp.y = _m->gui.pos[0].y + 20;
  draw_box(_m->mimg, _m->gui.pos, _m->gui.in, 1);
  draw_box(_m->mimg, _m->gui.pos, _m->gui.out, 0);
  draw_button(_m);
  printl(_m->mimg, &(_m->font[0]), tmp, "Node %d", _m->map.mov);
  tmp.x = _m->gui.pos[0].x + _m->gui.scale.x / 2 -
    (_m->font->scale.x * _m->font->size * 18) / 2;
  tmp.y += 40;
  draw_guitext(_m, tmp);
  if (_m->gui.butt >= 0 && _m->gui.butt <= 5)
    managebut(_m, _m->gui.butt);
}
