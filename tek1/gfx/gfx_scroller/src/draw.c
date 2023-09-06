/*
** draw.c for draw in /home/baris-f/rendu/gfx/gfx_scroller
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Mar 20 14:43:09 2016 Florent Baris
** Last update Sun Mar 20 17:18:11 2016 Florent Baris
*/

#include "tool.h"

void	aff(t_base *base, t_img *img, t_2D pos)
{
  int   i;
  int   j;
  t_col	*buff;

  i = -1;
  buff = (t_col *)img->pixels;
  /* printf("(%d, %d)\n", img->clipable.clip_width, img->clipable.clip_height); */
  while (++i < img->clipable.clip_width)
    {
      pos.x++;
      j = -1;
      while (++j < img->clipable.clip_height)
	{
	  pos.y++;
	  tekpixel(base->img, pos, buff[j * img->clipable.clip_width + i]);
	}
      pos.y -= img->clipable.clip_height;
    }
}

void		draw(t_base *base, t_img *img, t_2D *pos)
{
  t_2D	tpos;

  if (pos->x <= -img->clipable.clip_width)
    pos->x += img->clipable.clip_width;
  tpos.x = pos->x;
  tpos.y = pos->y;
  aff(base, img, tpos);
  while (tpos.x < WIN_W)
    {
      tpos.x += img->clipable.clip_width;
      aff(base, img, tpos);
    }
}

void	anim(t_base *base, t_img *img, t_2D *pos, int nbimg)
{
  t_2D	tpos;
  int   i;
  int   j;
  t_col *buff;

  if (pos->x <= -img->clipable.clip_width / nbimg)
    pos->x = WIN_W + img->clipable.clip_width / nbimg;
  tpos.x = pos->x;
  tpos.y = pos->y;
  i = -1;
  buff = (t_col *)img->pixels;
  while (++i < img->clipable.clip_width / nbimg * 2)
    {
      tpos.x++;
      j = -1;
      while (++j < img->clipable.clip_height * 2)
	{
	  tpos.y++;
	  if (buff[(j + 0) * img->clipable.clip_width + i] != 0xffffffff)
	    tekpixel(base->img, tpos, buff[(j + 0) / 2 * img->clipable.clip_width + i / 2 + (base->afire / 2) * img->clipable.clip_width / nbimg]);
	}
      tpos.y -= img->clipable.clip_height * 2;
    }
}
