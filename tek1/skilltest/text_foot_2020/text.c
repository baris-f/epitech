/*
** tekpixel.c for chromatic in /home/baris-f/rendu/skilltest/chromatic_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb  2 14:10:11 2016 Florent Baris
** Last update Tue Mar  8 15:13:54 2016 Florent Baris
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

typedef struct	s_bunny_textbox
{
  t_bunny_pixelarray	*chipset;
  int			border_size;
  t_bunny_pixelarray	*font;
  t_bunny_position	fontsize;
  int			x;
  int			y;
  int			w;
  int			h;
}	t_bunny_textbox;

void	textbox(t_bunny_pixelarray *pix, const t_bunny_textbox *box, const char *str)
{

}
