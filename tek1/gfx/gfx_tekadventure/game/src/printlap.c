/*
** printlap.c for sds in /home/fus/tmp/fusgine/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Mar 24 20:53:57 2016 Gaspard Thirion
** Last update Sat Apr  9 13:28:26 2016 Gaspard Thirion
*/

#include "engine.h"

void            charl(t_img *img, t_font *font, char c, t_2D pos)
{
  int           x;
  unsigned int  *buff;
  t_2D          tpos;

  buff = (unsigned int*)font->img->pixels;
  tpos.x = pos.x - 1;
  x = c * font->scale.x;
  while (++tpos.x < pos.x + font->scale.x * font->size)
    {
      tpos.y = pos.y - 1;
      while (++tpos.y < pos.y + font->scale.y * font->size)
	if ((buff[x +
		 (tpos.x - pos.x) / font->size + (tpos.y - pos.y)
		 / font->size * font->img->clipable.clip_width]
	     & 0xff000000) == 0xff000000)
	  mpixel(img, tpos, font->col);
    }
}

void		strl(t_img *img, t_font *font, char *s, t_2D *pos)
{
  int		j;

  j = -1;
  while (s[++j])
    {
      charl(img, font, s[j], *pos);
      pos->x += (font->scale.x + font->marge.x) * font->size;
    }
}

void		nbrl(t_img *img, t_font *font, int nb, t_2D *pos)
{
  int		d;

  d = 1;
  if (nb < 0)
    {
      charl(img, font, '-', *pos);
      pos->x += (font->scale.x + font->marge.x) * font->size;
      nb *= -1;
    }
  while (nb / d >= 10)
    d *= 10;
  while (d > 0)
    {
      charl(img, font, nb / d % 10 + '0', *pos);
      pos->x += (font->scale.x + font->marge.x) * font->size;
      d /= 10;
    }
}

void		printl(t_img *img, t_font *font, t_2D pos,
		       char *patt, ...)
{
  int		i;
  t_2D		tpos;
  va_list	ap;

  va_start(ap, patt);
  i = -1;
  tpos.x = pos.x;
  tpos.y = pos.y;
  while (patt[++i])
    if (patt[i] == '%')
      {
	if (patt[++i] == 's') strl(img, font, va_arg(ap, char*), &tpos);
	else if (patt[i] == 'd') nbrl(img, font, va_arg(ap, int), &tpos);
      }
    else if (patt[i] == '\n')
      {
	tpos.x = pos.x;
	tpos.y += (font->scale.y + font->marge.y) * font->size;
      }
    else
      {
	charl(img, font, patt[i], tpos);
	tpos.x += (font->scale.x + font->marge.x)* font->size;
      }
}
