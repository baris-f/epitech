/*
** tekpixel.c for chromatic in /home/baris-f/rendu/skilltest/chromatic_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb  2 14:10:11 2016 Florent Baris
** Last update Tue Feb 16 16:18:20 2016 Florent Baris
*/

#include <lapin.h>
#include <math.h>

typedef struct s_bunny_symbols
{
  size_t length;
  char data[0];
} t_bunny_symbols;

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  buff[idx] = col;
}

void tekletter(t_bunny_pixelarray *pix, char c, t_bunny_pixelarray *font)
{
  int	i;

  i = c * 5;

}

void tektext(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng,
	     const t_bunny_position *pos, const char *str)
{
  return (0);
}

void tektitle(t_bunny_pixelarray *out,
	      t_bunny_pixelarray *fontpng, const char *str)
{
  return (0);
}

t_bunny_symbols *teknew_symbol(const char *str, size_t len)
{
  return (0);
}

void tekdelete_symbol(t_bunny_symbols *sym)
{
  return (0);
}

void teksymbols(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng,
	  const t_bunny_position *pos, const t_bunny_symbols *sym)
{
  return (0);
}

int                     main(int ac, char **av)
{
  int                   x;
  int                   y;
  t_bunny_window        *win;
  t_bunny_pixelarray    *img;
  t_bunny_pixelarray    *font;
  t_bunny_position      pos[2];

  pos->x = 0;
  pos->y = 0;
  pos[1].x = 200;
  pos[1].y = 200;
  if (ac != 1)
    return (write(1, "Usage: ./wolf map\n", 18));
  x = 1280;
  y = 720;
  if ((win = bunny_start(x, y, 0, "Wolf3D")) == NULL)
    return (0);
  if ((img = bunny_new_pixelarray(x, y)) == NULL)
    return (0);
  if ((font = bunny_load_pixelarray("font.png")) == NULL)
    return (0);
  while (1)
    {
      bunny_blit(&(win->buffer), &(img->clipable), &pos[0]);
      tekletter(font, 'a');
      bunny_display(win);
      pause();
    }
  bunny_delete_clipable(&img->clipable);
  bunny_stop(win);
  return (0);
}
