/*
** control.c for sfi in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Mar 21 22:53:00 2016 Gaspard Thirion
** Last update Wed Apr 20 22:45:15 2016 Gaspard Thirion
*/

#include "engine.h"

int	new_node(t_main *_m)
{
  int	i;

  i = -1;
  while (++i < NB_NODE - 1)
    if (_m->map.node[i].pos.x == -1)
      {
	_m->map.node[i].scale.x = 10;
	_m->map.node[i].scale.y = 10;
	_m->map.node[i].type = 0;
	_m->map.node[i].depth = 50;
	_m->map.node[i].full = 1;
	return (i);
      }
  return (NB_NODE - 1);
}

void	left_click(t_main *_m, t_2D *tmp, t_bunny_event_state state,
		   t_bunny_mousebutton button)
{
  int	cur;

  if (button == BMB_LEFT && state == GO_DOWN)
    {
      if (inbut(_m, tmp[0]) != -1);
      else if ((cur = innode(_m, tmp[0])) >= 0)
	{
	  _m->mouse[2].x = 2;
	  _m->map.mov = cur;
	}
      else if (inmap(_m, tmp[0]))
	{
	  _m->mouse[2].x = 1;
	  _m->map.nb_node = new_node(_m);
	  _m->map.mov = _m->map.nb_node;
	  _m->map.node[_m->map.nb_node].pos.x = tmp->x - _m->map.pos.x;
	  _m->map.node[_m->map.nb_node].pos.y = tmp->y - _m->map.pos.y;
	}
    }
  else if (button == BMB_LEFT && state == GO_UP)
    {
      _m->gui.butt = -1;
      _m->mouse[2].x = 0;
    }
  managebut(_m, _m->gui.butt);
}

void    right_click(t_main *_m, t_2D *tmp, t_bunny_event_state state,
		    t_bunny_mousebutton button)
{
  int	cur;

  if (button == BMB_RIGHT && state == GO_DOWN)
    {
      _m->mouse[2].y = 1;
      if ((cur = innode(_m, tmp[0])) >= 0)
	{
	  _m->map.curlin.x = 1;
	  _m->map.curlin.y = cur;
	}
    }
  else if (button == BMB_RIGHT && state == GO_UP)
    {
      _m->map.curlin.x = 0;
      _m->mouse[2].y = 0;
      if (innode(_m, tmp[0]) >= 0)
	addlink(_m, _m->map.curlin.y, innode(_m, tmp[0]));
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
  _m->mouse[1].x = tmp->x;
  _m->mouse[1].y = tmp->y;
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
  if (_m->mouse[2].x == 1 && inmap(_m, tmp[0]))
    {
      _m->map.node[_m->map.nb_node].pos.x = tmp->x - _m->map.pos.x;
      _m->map.node[_m->map.nb_node].pos.y = tmp->y - _m->map.pos.y;
    }
  else if (_m->mouse[2].x == 2 && inmap(_m, tmp[0]))
    {
      _m->map.node[_m->map.mov].pos.x = tmp->x - _m->map.pos.x;
      _m->map.node[_m->map.mov].pos.y = tmp->y - _m->map.pos.y;
    }
  (void)relative;
  return (GO_ON);
}
