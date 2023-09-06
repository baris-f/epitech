/*
** tekmouse.c for tekmouse in /home/baris-f/rendu/gfx/gfx_tekdoom/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Jan 14 14:04:49 2016 Florent Baris
** Last update Tue Jan 19 18:42:52 2016 Florent Baris
*/

#include "../inc/wolf.h"

t_bunny_response	mouse(t_bunny_event_state		state,
			      t_bunny_mousebutton		button,
			      void				*your_data)
{
  t_base	*pass;
  t_2D		*tmp;

  pass = (t_base *)your_data;
  if (button == BMB_LEFT && state == GO_DOWN && pass->edit.pixel == 0)
    {
      tmp = (t_2D *)bunny_get_mouse_position();
      pass->edit.lpos[0].x = tmp->x;
      pass->edit.lpos[0].y = tmp->y;
      pass->edit.pixel = 1;
    }
  else if (button == BMB_LEFT && state == GO_UP)
    pass->edit.pixel = 0;
  else if (button == BMB_RIGHT && state == GO_DOWN && pass->edit.ligne == 0)
    {
      tmp = (t_2D *)bunny_get_mouse_position();
      pass->edit.lpos[0].x = tmp->x;
      pass->edit.lpos[0].y = tmp->y;
      pass->edit.ligne = 1;
    }
  else if (button == BMB_RIGHT && state == GO_UP)
    {
      if (pass->edit.menu.cur == 0)
	lineinmap(pass, pass->edit.lpos, pass->edit.map, pass->edit.col);
      else if (pass->edit.menu.cur == 1)
	draw_boxinmap(pass, pass->edit.lpos, pass->edit.col, 0, pass->edit.map);
      else if (pass->edit.menu.cur == 2)
	draw_boxinmap(pass, pass->edit.lpos, pass->edit.col, 1, pass->edit.map);
      else if (pass->edit.menu.cur == 3)
	circleinmap(pass, pass->edit.lpos, pass->edit.map, pass->edit.col);
      pass->edit.ligne = 0;
    }
return (GO_ON);
}

t_bunny_response	mouse_move(const t_bunny_position          *relative,
			   void                            *your_data)

{
  t_base	*pass;
  t_2D		*tmp;

  pass = (t_base *)your_data;
  tmp = (t_2D *)bunny_get_mouse_position();
  pass->edit.lpos[1].x = tmp->x;
  pass->edit.lpos[1].y = tmp->y;
  (void)relative;
  return (GO_ON);
}
