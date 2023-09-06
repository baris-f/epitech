/*
** movement.c for doom in /home/fus/tmp/plaquage/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sun Jan 17 20:54:11 2016 Gaspard Thirion
** Last update Tue Jan 26 09:48:35 2016 Florent Baris
*/

#include "tool.h"

int		move(t_base *base, float n, int ang)
{
  t_f2D		tmp;
  t_col		*buff;
  int		width;
  int		i;
  int		sw;

  i = -1;
  sw = 0;
  width = base->prs[1].img->clipable.clip_width;
  tmp.x = base->play.pos.x + (cos(-(base->play.ang.x + D_R(ang)) + M_PI) * n);
  tmp.y = base->play.pos.y + (sin(-(base->play.ang.x + D_R(ang)) + M_PI) * n);
  buff = (t_col*)base->prs[1].img->pixels;
  if (buff[(int)(tmp.x + HIT) + (int)(tmp.y + HIT) * width] == (t_col)BLACK ||
      buff[(int)(tmp.x + HIT) + (int)(tmp.y - HIT) * width] == (t_col)BLACK ||
      buff[(int)(tmp.x - HIT) + (int)(tmp.y + HIT) * width] == (t_col)BLACK ||
      buff[(int)(tmp.x - HIT) + (int)(tmp.y - HIT) * width] == (t_col)BLACK)
    {
      base->play.pos.x = 2;
      base->play.pos.y = 2;
      base->play.ang.x = M_PI * 1.5;
      base->play.ang.y = M_PI / 2;
      bunny_delete_clipable(&(base->prs[1].img->clipable));
      while (++i < NB_TEXT)
	if (base->prs[i].map == base->prs[1].map + 1 && i != 1)
	  {
	    base->prs[1].img = base->prs[i].img;
	    ++(base->prs[1].map);
	    sw = 1;
	    return (1);
	  }
      if (sw == 0)
	return (0);
    }
  if (buff[(int)(tmp.x + HIT) + (int)(tmp.y + HIT) * width] == (t_col)DF_GR_COL &&
      buff[(int)(tmp.x + HIT) + (int)(tmp.y - HIT) * width] == (t_col)DF_GR_COL &&
      buff[(int)(tmp.x - HIT) + (int)(tmp.y + HIT) * width] == (t_col)DF_GR_COL &&
      buff[(int)(tmp.x - HIT) + (int)(tmp.y - HIT) * width] == (t_col)DF_GR_COL)
    {
      base->play.pos.x = tmp.x;
      base->play.pos.y = tmp.y;
    }
  return (1);
}
