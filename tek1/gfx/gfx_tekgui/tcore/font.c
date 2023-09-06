/*
** font.c for font in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 18:13:29 2016 Florent Baris
** Last update Sun Feb 28 23:26:31 2016 Florent Baris
*/

#include <lapin.h>

void		tekletter(char c, t_bunny_pixelarray *out,
			  t_bunny_pixelarray *font_png)
{
  int		x;
  unsigned int	*buff;
  t_2D		tpos;

  buff = (unsigned int*)font_png->pixels;
  tpos.x = -1;
  x = c * 5;
  while (++tpos.x < 5)
    {
      tpos.y = -1;
      while (++tpos.y < 7)
	if (buff[x + (tpos.x - pos->x) / size + (tpos.y - pos->y)
		 / size * theme->font_img->clipable.clip_width]
	    && 0xff000000 > 0)
	  tekpixel(out, tpos, buff[x + (tpos.x) + (tpos.y) *
				   font_png->clipable.clip_width]);
    }
}

void	tektext(t_bunny_pixelarray *out, const char *str,
		t_bunny_pixelarray *font_png)
{
  int	j;
  t_2D	tpos;

  j = -1;
  tpos.x = 0;
  tpos.y = 0;
  while (str[++j])
    {
      tekletter(str[j], out, font_png);
      tpos.x += 6;
    }
}
