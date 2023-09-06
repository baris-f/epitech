/*
** font.c for font in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb 16 16:19:11 2016 Florent Baris
** Last update Sat Mar 19 17:37:09 2016 Florent Baris
*/

#include "tool.h"

void		tekletter(char c, t_2D *pos, int size, t_base *base)
{
  int		x;
  int		y;
  unsigned int	*buff;
  t_2D		tpos;

  if (size < 1)
    size = 1;
  if (base->font == NULL)
    return ;
  buff = (unsigned int*)base->font->pixels;
  tpos.x = pos->x - 1;
  if (c >= 'A' && c <= 'Z')
    c += 32;
  if (isalph(c))
    c = c - 64;
  else if (c == 32)
    c = 0;
  x = c * 32 % 320;
  y = c * 32 / 320 * 32;
  while (++tpos.x < pos->x + 32 * size)
    {
      tpos.y = pos->y - 1;
      while (++tpos.y < pos->y + 32 * size)
	if (buff[x + (tpos.x - pos->x) / size + (y + (tpos.y - pos->y)
						 / size) * base->font->clipable.clip_width] != 0xff000000)
	  tekpixel(base->img, tpos, buff[x + (tpos.x - pos->x) / size + (y + (tpos.y - pos->y) / size) * base->font->clipable.clip_width]);
    }
}

void	tektext(t_base *base, char *str, t_2D *pos, int size)
{
  int	i;
  t_2D	tpos;

  i = -1;
  if (base->font == NULL)
    return ;
  tpos.x = pos->x;
  tpos.y = pos->y;
  while (str[++i])
    {
      if (str[i] == '\n')
	{
	  tpos.x = pos->x;
	  tpos.y += 32 * size;
	}
      else
	{
	  tekletter(str[i], &tpos, size, base);
	  tpos.x += 32 * size;
	}
    }
}
