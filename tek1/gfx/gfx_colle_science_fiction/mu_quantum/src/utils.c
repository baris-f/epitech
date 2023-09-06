/*
** tekfill.c for fdf in /home/fus/rendu/gfx_fdf1/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Nov 18 22:15:15 2015 Gaspard Thirion
** Last update Fri Apr 22 01:59:48 2016 Florent Baris
*/

#include "engine.h"

t_col           getpixel(t_img *img, t_2D pos)
{
  unsigned int  *buff;

  buff = (unsigned int*)img->pixels;
  if (pos.x < 0 || pos.y < 0
      || pos.x > img->clipable.buffer.width
      || pos.y > img->clipable.buffer.height)
    return (0xffb469ff);
  return (buff[pos.x + pos.y * img->clipable.buffer.width]);
}

void            mpixel(t_img *img, t_2D pos, t_col col)
{
  t_col         *buff;
  int           idx;
  float         alpha;
  t_col         tmpcol;

  buff = (t_col*)img->pixels;
  idx = img->clipable.buffer.width * pos.y + pos.x;
  alpha = ((col & 0xFF000000) >> 24);
  if (pos.x < 0 || pos.y < 0
      || pos.x >= img->clipable.buffer.width
      || pos.y >= img->clipable.buffer.height)
    return;
  if (alpha != 255)
    {
      alpha = alpha / 255;
      tmpcol = 0;
      tmpcol += (t_col)(((buff[idx] & 0xFF0000) >> 16) * (1 - alpha)
			+ ((col & 0xFF0000) >> 16) * alpha) << 16;
      tmpcol += (t_col)(((buff[idx] & 0xFF00) >> 8) * (1 - alpha)
			+ ((col & 0xFF00) >> 8) * alpha) << 8;
      tmpcol += ((buff[idx] & 0xFF)) * (1 - alpha) + ((col & 0xFF)) * alpha;
      buff[idx] = tmpcol;
    }
  else
    buff[idx] = col;
}

void            blit(t_img *dest, t_img *src, t_2D start)
{
  t_2D		tmp;
  t_2D		tmp2;
  t_2D		fin;
  t_col		col;

  fin.x = src->clipable.clip_width * src->clipable.scale.x + start.x;
  fin.y = src->clipable.clip_height * src->clipable.scale.y + start.y;
  tmp.y = start.y - 1;
  while (++(tmp.y) < fin.y)
    {
      tmp.x = start.x - 1;
      while (++(tmp.x) < fin.x)
	{
	  tmp2.x = (tmp.x - start.x)
	    / src->clipable. scale.x + src->clipable.clip_x_position;
	  tmp2.y = (tmp.y - start.y)
	    / src->clipable.scale.y + src->clipable.clip_y_position;
	  if ((col = getpixel(src, tmp2)) != 0xffb469ff)
	    mpixel(dest, tmp, col);
	}
    }
}

void            invblit(t_img *dest, t_img *src, t_2D start)
{
  t_2D		tmp;
  t_2D		tmp2;
  t_2D		fin;
  t_col		col;

  fin.x = src->clipable.clip_width * src->clipable.scale.x + start.x;
  fin.y = src->clipable.clip_height * src->clipable.scale.y + start.y;
  tmp.y = start.y - 1;
  while (++(tmp.y) < fin.y)
    {
      tmp.x = start.x - 1;
      while (++(tmp.x) < fin.x)
	{
	  tmp2.x = src->clipable.clip_width - (tmp.x - start.x)
	    / src->clipable.scale.x + src->clipable.clip_x_position;
	  tmp2.y = (tmp.y - start.y)
	    / src->clipable.scale.y + src->clipable.clip_y_position;
	  if ((col = getpixel(src, tmp2)) != 0xffb469ff)
	    mpixel(dest, tmp, col);
	}
    }
}

void		fill(t_img *img, t_col col)
{
  t_2D		tmp;

  if (!img)
    return;
  tmp.y = -1;
  while (++(tmp.y) < img->clipable.buffer.height)
    {
      tmp.x = -1;
      while (++(tmp.x) < img->clipable.buffer.width)
	mpixel(img, tmp, col);
    }
}
