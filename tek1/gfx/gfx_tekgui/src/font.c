/*
** font.c for font in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb 16 16:19:11 2016 Florent Baris
** Last update Sun Feb 28 21:51:43 2016 Florent Baris
*/

#include "tool.h"

void		tekletter(char c, t_2D *pos, int size, t_theme *theme)
{
  int		x;
  unsigned int	*buff;
  t_2D		tpos;

  if (size < 1)
    size = 1;
  buff = (unsigned int*)theme->font_img->pixels;
  tpos.x = pos->x - 1;
  x = c * 5;
  while (++tpos.x < pos->x + 5 * size)
    {
      tpos.y = pos->y - 1;
      while (++tpos.y < pos->y + 7 * size)
	if (buff[x + (tpos.x - pos->x) / size + (tpos.y - pos->y)
		 / size * theme->font_img->clipable.clip_width] && 0xff000000 > 0)
	  tekpixel(theme->win_img, tpos, theme->font_col);
    }
}

void	tektext(char *str, t_2D *pos, int size, t_theme *theme)
{
  int	i;
  t_2D	tpos;

  i = -1;
  if (theme->font_img == 0)
    return ;
  tpos.x = pos->x;
  tpos.y = pos->y;
  while (str[++i])
    {
      if (str[i] == '\n')
	{
	  tpos.x = pos->x;
	  tpos.y += 8 * size;
	}
      else
	{
	  tekletter(str[i], &tpos, size, theme);
	  tpos.x += 6 * size;
	}
    }
}
