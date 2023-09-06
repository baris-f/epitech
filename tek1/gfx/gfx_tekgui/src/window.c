/*
** window.c for  in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb 16 19:46:25 2016 Florent Baris
** Last update Sun Feb 28 21:50:31 2016 Florent Baris
*/

#include "tool.h"

void	rectangle(t_img *img, t_2D *pos, t_2D *size, t_col color)
{
  t_2D	tpos;

  tpos.x = pos->x - 1;
  while (++tpos.x < pos->x + size->x)
    {
      tpos.y = pos->y - 1;
      while (++tpos.y < pos->y + size->y)
	{
	  tekpixel(img, tpos, color);
	}
    }
}

void            affx(t_img *img, t_2D *pos, t_img *font, t_col col)
{
  int           x;
  unsigned int  *buff;
  t_2D          tpos;
  char		c;

  if (font == 0)
    return ;
  c = 127;
  buff = (unsigned int*)font->pixels;
  tpos.x = pos->x - 1;
  x = c * 5;
  while (++tpos.x < pos->x + 10)
    {
      tpos.y = pos->y - 1;
      while (++tpos.y < pos->y + 14)
	if (buff[x + (tpos.x - pos->x) / 2 + (tpos.y - pos->y)
		 / 2 * font->clipable.clip_width] && 0xff000000 > 0)
	  tekpixel(img, tpos, col);
    }
}

void	border(t_2D *pos, t_2D *size, int border_size, t_theme *theme)
{
  t_2D  tpos;

  tpos.x = pos->x - border_size - 1;
  while (++tpos.x < pos->x + size->x + border_size)
    {
      tpos.y = pos->y - 18;
      while (++tpos.y < pos->y + size->y + border_size)
	{
	  tekpixel(theme->win_img, tpos, theme->frame_col);
	}
    }
  tpos.x = pos->x + size->x - 12;
  tpos.y = pos->y - 16;
  if (theme->frame_col == 0xfffffff || theme->frame_col == 0xffeeeeee)
    affx(theme->win_img, &tpos, theme->font_img, WHITE);
  else
    affx(theme->win_img, &tpos, theme->font_img, BLACK);
}

void	window(t_objs *but, t_theme *theme)
{

  /* &tpos, &but->size, but->border_size */
  if (but->border == TRUE)
    border(&but->pos, &but->size, but->border_size, theme);
  rectangle(theme->win_img, &but->pos, &but->size, theme->obj_col);
}
