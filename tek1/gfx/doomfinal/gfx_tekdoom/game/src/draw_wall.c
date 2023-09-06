/*
** draw_wall.c for doom in /home/fus/tmp/2plaquage/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Jan 19 23:26:46 2016 Gaspard Thirion
** Last update Tue Jan 26 09:06:35 2016 Corentin Grandmaire
*/

#include "tool.h"

void		draw_wall(t_base *base, t_f2D info, t_col col, float height)
{
  t_col		tmpcol;
  t_2D		tmp;
  t_2D		borne;

  borne.x = WIN_HH - height;
  borne.y = WIN_HH ;
  tmpcol = SKY_COL;
  tmp.x = info.x;
  tmp.y = -1;
  while (++(tmp.y) < WIN_H)
    {
      mpixel(base->img, tmp, tmpcol);
      if (tmp.y > borne.y)
	tmpcol = GRND_COL;
      else if (tmp.y > borne.x)
	tmpcol = col;
    }
}

void		text_wall(t_base *base, t_f2D info, t_col col, float height, float dist)
{
  t_col		*buff;
  t_col		tmpcol;
  t_img		*img;
  t_2D		tmp;
  t_2D		borne;
  int		i;
  t_col		col2;

  i = -1;
  while (++i < NB_TEXT)
    if (base->prs[i].ref == col)
      img = base->prs[i].img;
  if (img == NULL)
    img = base->prs[6].img;
  buff = (t_col*)img->pixels;
  info.y = (int)(info.y * 1000) % 1000 / 1000.0 * img->clipable.clip_width;
  borne.y = WIN_HH + height / 2 + base->play.pos.z;
  borne.x = WIN_HH - height / 2 + base->play.pos.z;
  tmp.x = info.x;
  tmp.y = borne.x - 1;
  while (++(tmp.y) < borne.y)
    {
      tmpcol = buff[(int)(info.y) + (int)((tmp.y - borne.x) / height
					  * img->clipable.clip_height)
		    * img->clipable.clip_width];
      tmpcol -= 0x00010101 * (int)(dist * 4);
      if ((tmpcol % 256) > 235 || ((tmpcol / (256 * 256)) % 256) > 235 ||
	  (tmpcol / 256) % 256 > 235 || tmpcol < 0xff050505)
	tmpcol = BLACK;
      mpixel(base->img, tmp, tmpcol);
    }
  col2 = -1219999672;
  tmp.y = WIN_H + 1;
  while (--(tmp.y) >= borne.y)
    {
      if (tmp.y % 5 == 1)
        col2 -= 0xff010101;
      mpixel(base->img, tmp, col2);
    }
}
