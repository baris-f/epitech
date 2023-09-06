/*
** lel.c for lel in /home/baris-f/rendu/skilltest/flip_part_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Feb 26 09:30:37 2016 Florent Baris
** Last update Fri Feb 26 09:34:22 2016 Florent Baris
*/

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  buff[idx] = col;
}

void	tektext(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng,
	const t_bunny_position	*pos, const char *str)
{
  return (0);
}

typedef struct s_bunny_font
{
  t_bunny_pixelarray *font_file;
  t_bunny_position charsize;
  /* contains width and height of 1 glyph */
}t_bunny_font;

void	flipping_letters(t_bunny_pixelarray *pix,  const t_bunny_font *font,
		 const char *str, size_t counter)
{
  return (0);
}
