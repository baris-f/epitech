/*
** tekpixel.c for chromatic in /home/baris-f/rendu/skilltest/chromatic_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb  2 14:10:11 2016 Florent Baris
** Last update Thu Mar 31 09:53:01 2016 Florent Baris
*/

#include <lapin.h>

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  buff[idx] = col;
}

void tekblit(t_bunny_pixelarray *destination, const t_bunny_pixelarray *origin,
	const t_bunny_position *pos)
{

}

void tektext(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng,
	     const t_bunny_position *pos, const char *str);

void nocss(t_bunny_pixelarray *pix, t_bunny_ini *interface);
