/*
** click.c for click in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 16:39:43 2016 Florent Baris
** Last update Sun Feb 28 23:22:29 2016 Florent Baris
*/

#include "tool.h"

int	posinthis(t_2D *tpos, t_2D pos, t_2D size, int bsize)
{
  if ((tpos->x > pos.x - bsize && tpos->x < pos.x + 16 &&
       tpos->y > pos.y - 18 && tpos->y < pos.y))
    return (3);
  else if ((tpos->x > pos.x + size.x - 16 && tpos->x < pos.x + size.x + bsize &&
	    tpos->y > pos.y - 18 && tpos->y < pos.y))
    return (2);
  else if ((tpos->x > pos.x - bsize && tpos->x < pos.x + size.x  + bsize &&
	    tpos->y > pos.y - 18 && tpos->y < pos.y + size.y + bsize) &&
	   !(tpos->x > pos.x && tpos->x < pos.x + size.x &&
	     tpos->y > pos.y && tpos->y < pos.y + size.y))
    return (1);
  else if (tpos->x > pos.x && tpos->x < pos.x + size.x &&
	  tpos->y > pos.y && tpos->y < pos.y + size.y)
    return (0);
  return (-1);
}

void	cl3(t_base *base, t_bunny_event_state state, int i, t_2D *idx)
{
  int   posin;
  t_2D  tpos;

  tpos.x = (int)bunny_get_mouse_position()->x;
  tpos.y = (int)bunny_get_mouse_position()->y;
  posin = posinthis(&tpos, base->tg->objs[i].pos, base->tg->objs[i].size,
		    base->tg->objs[i].border_size);
  if (posin >= 1 && idx->y <= base->tg->objs[i].depth &&
      base->tg->objs[i].visible == TRUE)
    {
      idx->x = i;
      idx->y = base->tg->objs[i].depth;
      (state == GO_DOWN && posin == 2) ? (base->tg->objs[idx->x].visible =
FALSE) : ((posin == 3 && state == GO_DOWN) ? (base->mous.x = 2) : (0));
    }
  else if (posin == 0 && idx->y <= base->tg->objs[i].depth && state == GO_DOWN
   && base->tg->objs[i].visible == TRUE && base->tg->objs[i].type == 'b')
    {
      (void)base->tg->objs[i].func;
      base->tg->objs[i].tick = TRUE;
    }
  else if (idx->y <= base->tg->objs[i].depth && state == GO_UP &&
	   base->tg->objs[i].visible == TRUE && base->tg->objs[i].type == 'b')
    base->tg->objs[i].tick = FALSE;
}

void	cl2(t_base *base, t_2D *tpos, t_bunny_event_state state, t_2D *idx)
{
  int   i;

  i = -1;
  while (++i < base->tg->nb.y)
    {
      if (base->tg->objs[i].type == 'k')
	{
	  if (posinthis(tpos, base->tg->objs[i].pos, base->tg->objs[i].size,
			base->tg->objs[i].border_size) == 0 && state == GO_DOWN)
	    base->tg->objs[i].tick = !base->tg->objs[i].tick;

	}
      if (base->tg->objs[i].border == TRUE)
	cl3(base, state, i, idx);
    }
}

t_resp		click(t_bunny_event_state               state,
		      t_bunny_mousebutton               button,
		      void                              *your_data)
{
  t_base        *base;
  t_2D          tpos;
  t_2D          idx;

  base = (t_base *)your_data;
  if (button == BMB_LEFT && state == GO_DOWN)
    base->mous.x = 1;
  else if (button == BMB_LEFT && state == GO_UP)
    base->mous.x = 0;
  tpos.x = (int)bunny_get_mouse_position()->x;
  tpos.y = (int)bunny_get_mouse_position()->y;
  idx.x = -1;
  idx.y = -1;
  cl2(base, &tpos, state, &idx);
  if (button == BMB_LEFT && state == GO_DOWN)
    base->mous.y = idx.x;
  else if (button == BMB_LEFT && state == GO_UP)
    base->mous.y = 0;
  return (GO_ON);
}
