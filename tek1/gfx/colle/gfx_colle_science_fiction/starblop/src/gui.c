/*
** gui.c for gui in /home/baris-f/rendu/gfx/gfx_tekadventure/baris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Apr  3 18:52:42 2016 Florent Baris
** Last update Fri Apr 22 09:43:36 2016 Florent Baris
*/

#include "engine.h"

void    draw_life(t_main *_m)
{
  t_2D  life[2];

  _m->font[0].size--;
  life[0] = set2D(life[0], _m->s.x / 40 + _m->fight.lb->clipable.clip_width / 9, _m->s.y / 15, 1);
  life[1] = set2D(life[0], (_m->fight.lb->clipable.clip_width - _m->fight.lb->clipable.clip_width / 6)
		  * _m->fight.lb->clipable.scale.x * (float)((float)_m->player.life / 100), 35, 0);
  draw_box(_m->mimg, life, (_m->player.life < 50) ? ((_m->player.life < 25) ? (0xff0000ff) : (0xff008cff)) : (0xff00ff00), 1);
  life[0] = set2D(life[0], _m->s.x / 50, _m->s.y / 22, 1);
  blit(_m->mimg, _m->fight.lb, life[0]);
  printl(_m->mimg, _m->font, set2D(life[0], _m->fight.lb->clipable.clip_width, _m->fight.lb->clipable.clip_height, 0), "%d/100    %d",
	 _m->player.life, _m->player.lvl);
  life[0] = set2D(life[0], _m->s.x - _m->s.x / 20 - (_m->fight.lb->clipable.clip_width
  - _m->fight.lb->clipable.clip_width / 6) * _m->fight.lb->clipable.scale.x
		  * _m->fight.life / 100, _m->s.y / 17, 1);
  life[1].x = _m->s.x - _m->s.x / 20;
  life[1].y = life[0].y + 45;
  draw_box(_m->mimg, life, (_m->fight.life < 50) ? ((_m->fight.life < 25) ? (0xff0000ff) : (0xff008cff)) : (0xff00ff00), 1);
  life[0] = set2D(life[0], _m->s.x - _m->s.x / 40 - _m->fight.lb->clipable.scale.x
		  * _m->fight.lb->clipable.clip_width, _m->s.y / 20, 1);
  invblit(_m->mimg, _m->fight.lb, life[0]);
  printl(_m->mimg, _m->font, set2D(life[0], _m->fight.lb->clipable.clip_width / 6, _m->fight.lb->clipable.clip_height, 0), "%d    %d/100",
	 _m->fight.lvl, _m->fight.life);
  _m->font[0].size++;
}

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
      if ((i == 1 && _m->player.spe > 0) || (i == 2 && _m->player.pot == 0) || _m->fight.turn % 2 == 0)
	draw_box(_m->mimg, tmp, 0xff777777, 1);
      else
	draw_box(_m->mimg, tmp, _m->gui.in, 1);
      draw_box(_m->mimg, tmp, _m->gui.out, 0);
      if (_m->gui.but[i].text != NULL)
	{
	  if (i == 0 || i == 1)
	    	  tmp[0].x += (tmp[1].x - tmp[0].x) / 2 - ((_m->font[0].scale.x *
_m->font[0].size + _m->font[0].marge.x + 1) * (my_strlen(_m->gui.but[i].text) + 7 + i)) / 2;
	  else
	  tmp[0].x += (tmp[1].x - tmp[0].x) / 2 - ((_m->font[0].scale.x *
   _m->font[0].size + _m->font[0].marge.x + 1) * my_strlen(_m->gui.but[i].text)) / 2;
	  tmp[0].y += (tmp[1].y - tmp[0].y) / 2 -
	    (_m->font[0].scale.y * _m->font[0].size) / 2;
	  if (i == 0)
	    printl(_m->mimg, _m->font, tmp[0], "%d-%d %s", _m->player.dmg - 2,
		   _m->player.dmg + 2, _m->gui.but[i].text);
	  else if (i == 1 && _m->player.spe > 0)
	    printl(_m->mimg, _m->font, tmp[0], "%d-%d %s (%d)", _m->player.dmg * 3 - 5,
		   _m->player.dmg * 3 + 5, _m->gui.but[i].text, _m->player.spe);
	  else if (i == 1)
	    printl(_m->mimg, _m->font, tmp[0], "%d-%d %s", _m->player.dmg * 3 - 5,
		   _m->player.dmg * 3 + 5, _m->gui.but[i].text);
	  else if (i == 2 && _m->player.pot > 0)
	    printl(_m->mimg, _m->font, tmp[0], "%s %d", _m->gui.but[i].text, _m->player.pot);
	  else
	    printl(_m->mimg, _m->font, tmp[0], "%s", _m->gui.but[i].text);
	}
    }
}


void	draw_gui(t_main *_m)
{
  t_2D  tmp;

  draw_life(_m);
  _m->font[0].size += 2;
  tmp.x = _m->sh.x + 60 +(_m->mouse[0].x - _m->s.x) / 10;
  tmp.y = _m->sh.y;
  printl(_m->mimg, _m->font, tmp, "SOL");
  tmp.y += _m->sh.y * 3 / 4;
  tmp.x += -400 + (_m->mouse[0].x - _m->s.x) / 5;
  printl(_m->mimg, _m->font, tmp, "BUSH            BUSH             BUSH");
  _m->font[0].size -= 2;
  tmp.x = _m->gui.pos[0].x + _m->gui.scale.x / 2 -
    (_m->font[0].scale.x * _m->font[0].size * 7) / 2;
  tmp.y = _m->gui.pos[0].y + 20;
  draw_box(_m->mimg, _m->gui.pos,
	   (_m->fight.turn % 2 != 0) ? (_m->gui.in) : (_m->gui.out), 1);
  draw_box(_m->mimg, _m->gui.pos, _m->gui.out, 0);
  draw_button(_m);
  tmp.x = _m->gui.pos[0].x + _m->gui.scale.x / 2 -
    (_m->font[0].scale.x * _m->font[0].size * 18) / 2;
  tmp.y += 40;
  _m->font[0].size += 2;
  tmp.x = _m->s.x / 2 - ((_m->font[0].scale.x *
			_m->font[0].size + _m->font[0].marge.x + 1)) / 2;
  tmp.y = _m->s.y / 20;
  printl(_m->mimg, _m->font, tmp, "%d", (_m->fight.turn + ((_m->fight.turn) % 2)) / 2);
  _m->font[0].size -= 2;
}
