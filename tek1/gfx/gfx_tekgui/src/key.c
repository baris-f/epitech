/*
** key.c for key in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Feb  3 21:32:54 2016 Florent Baris
** Last update Sun Feb 28 17:16:24 2016 Florent Baris
*/

#include "tool.h"

t_resp		keys(t_bunny_event_state state, t_bunny_keysym key, void *v)
{
  t_base	*base;
  static int	i = -1;

  base = (t_base*)v;
  (void)base;
  if (key == BKS_ESCAPE && state == GO_UP)
    return (EXIT_ON_SUCCESS);
  else if (key == BKS_BACKSPACE && state == GO_DOWN && i >= 0)
    base->tg->text[i--] = '\0';
  else if (i >= 140 - 1)
    return (GO_ON);
  else if (key >= 0  && key <= 25 && state == GO_DOWN)
    base->tg->text[++i] = key + 97;
  else if (key >= 26  && key <= 35 && state == GO_DOWN)
    base->tg->text[++i] = key + 22;
  else if (key == BKS_RETURN && state == GO_DOWN)
    base->tg->text[++i] = '\n';
  else if (key == BKS_SPACE && state == GO_DOWN)
    base->tg->text[++i] = ' ';
  return (GO_ON);
}

t_resp		mouse_move(const t_2D *relative, void *your_data)
{
  t_base	*base;

  (void)your_data;
  (void)base;
  (void)relative;
  base = (t_base *)your_data;
  if (base->mous.y >= 0)
    {
      if (base->mous.x == 1)
	{
	  base->tg->objs[base->mous.y].pos.x += relative->x;
	  base->tg->objs[base->mous.y].pos.y += relative->y;
	}
      else if (base->mous.x == 2)
	{
	  base->tg->objs[base->mous.y].size.x += relative->x;
	  if (base->tg->objs[base->mous.y].size.x < 20)
	    base->tg->objs[base->mous.y].size.x = 20;
	  base->tg->objs[base->mous.y].size.y += relative->y;
	  if (base->tg->objs[base->mous.y].size.y < 20)
	    base->tg->objs[base->mous.y].size.y = 20;
	}
    }
  return (GO_ON);
}
