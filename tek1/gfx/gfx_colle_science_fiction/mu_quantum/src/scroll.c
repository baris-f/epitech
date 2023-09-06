/*
1;2802;0c** scroll.c for tekadv in /home/baris-f/rendu/gfx/gfx_tekadventure/final
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Apr 21 13:34:40 2016 Florent Baris
** Last update Fri Apr 22 09:56:46 2016 Florent Baris
*/

#include "engine.h"

int	inscroll(t_main *_m)
{
  t_2D	tmp[2];
  int	i;

  i = -1;
  tmp[0] = set2D(_m->gui.scroll[0], 10, 10, 0);
  while (++i < 4)
    {
      tmp[1] = set2D(tmp[0], 130, 40, 0);
      if (_m->mouse[0].x >= _m->map[_m->i].pos.x + tmp[0].x
	        && _m->mouse[0].x <= _m->map[_m->i].pos.x + tmp[1].x
	        && _m->mouse[0].y >= _m->map[_m->i].pos.y + tmp[0].y
	  && _m->mouse[0].y <= _m->map[_m->i].pos.y + tmp[1].y)
	return (i);
      tmp[0] = set2D(tmp[0], 0, 45, 0);
    }
  return (-1);
}

void	affscroll(t_main *_m)
{
  t_2D	tmp[2];
  int	i;

  if (_m->gui.scroll[0].x > -1)
    {
      _m->gui.scroll[1] = set2D(_m->gui.scroll[0], _m->gui.ssize.x, _m->gui.ssize.y, 0);
      draw_box(_m->mimg, _m->gui.scroll, _m->gui.in, 1);
      draw_box(_m->mimg, _m->gui.scroll, _m->gui.out, 0);
      tmp[0] = set2D(_m->gui.scroll[0], 10, 10, 0);
      i = -1;
      while (++i < 4)
	{
	  tmp[1] = set2D(tmp[0], 130, 40, 0);
	  draw_box(_m->mimg, tmp, _m->gui.out, 0);
	  if (inscroll(_m) == i)
	    draw_box(_m->mimg, tmp, _m->gui.out, 1);
	  if (i == 0)
	    printl(_m->mimg, _m->font, set2D(tmp[0], 20, 10, 0), "ALLER");
	  else if (i == 1)
	    printl(_m->mimg, _m->font, set2D(tmp[0], 20, 10, 0), "POT %d", _m->player.pot);
	  else
	    printl(_m->mimg, _m->font, set2D(tmp[0], 20, 10, 0), "RIEN");
	  tmp[0] = set2D(tmp[0], 0, 45, 0);
	}
    }
}
