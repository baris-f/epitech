/*
** control.c for sfi in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 22:53:00 2016 Gaspard Thirion
** Last update Fri Apr 22 09:59:29 2016 Florent Baris
*/

#include "engine.h"

void	left_click(t_main *_m, t_2D *tmp, t_bunny_event_state state,
		   t_bunny_mousebutton button)
{
  int	cur;

  if (button == BMB_LEFT && state == GO_DOWN)
    {
      _m->mouse[1].x = tmp->x;
      _m->mouse[1].y = tmp->y;
      cur = inscroll(_m);
      if (cur == 0)
	{
	if (innode(_m, _m->gui.scroll[0]) >= 0 && _m->player.mov == 0)
	  {
	    path(_m, _m->player.pnod, innode(_m, tmp[0]));
	    _m->mouse[1] = _m->gui.scroll[0];
	  }
	}
      else if (cur == 1)
	{
	  _m->player.life += 20;
	  (_m->player.life > 100) ? (_m->player.life = 100) : (0);
	  _m->player.pot--;
	}
      _m->gui.scroll[0].x = -1;
      if (_m->map[_m->i].node[_m->player.pnod].type == 2 && _m->player.mov == 0)
	{
	  cur = inbut(_m, tmp[0]);
	  if (cur == 0 || cur == 1)
	    _m->player.a = 1;
	}
      if (inmap(_m, tmp[0]) && innode(_m, tmp[0]) >= 0 && _m->player.mov == 0)
	path(_m, _m->player.pnod, innode(_m, tmp[0]));
    }
  else if (button == BMB_LEFT && state == GO_UP)
    {
      _m->gui.butt = -1;
    }
  if (_m->fight.turn % 2 != 0 && _m->fight.affdmg == 0)
    managebut(_m, _m->gui.butt);
}

void    right_click(t_main *_m, t_2D *tmp, t_bunny_event_state state,
		    t_bunny_mousebutton button)
{
  if (button == BMB_RIGHT && state == GO_DOWN)
    {
      if (innode(_m, tmp[0]) >= 0)
	{
	  _m->gui.scroll[0] = tmp[0];
	}
    }
  else if (button == BMB_RIGHT && state == GO_UP)
    {

    }
}

t_bunny_response        mouse(t_bunny_event_state               state,
			      t_bunny_mousebutton               button,
			      void                              *your_data)
{
  t_main        *_m;
  t_2D		tmp[1];

  _m = (t_main*)your_data;
  tmp->x = bunny_get_mouse_position()->x;
  tmp->y = bunny_get_mouse_position()->y;
  /* _m->mouse[1].x = tmp->x; */
  /* _m->mouse[1].y = tmp->y; */
  left_click(_m, tmp, state, button);
  right_click(_m, tmp, state, button);
  return (GO_ON);
}

t_bunny_response        mouse_move(const t_bunny_position *relative,
				   void *your_data)
{
  t_main        *_m;
  t_2D		tmp[1];

  _m = (t_main*)your_data;
  tmp->x = bunny_get_mouse_position()->x;
  tmp->y = bunny_get_mouse_position()->y;
  _m->mouse[0].x = tmp->x;
  _m->mouse[0].y = tmp->y;
  (void)relative;
  return (GO_ON);
}
