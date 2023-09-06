/*
** tekpixel.c for my_tekpixel in /home/baris_f/rendu/gfx_fdf1
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Nov 22 19:18:14 2015 Florent Baris
** Last update Sun Nov 22 22:38:53 2015 Florent Baris
*/
  #include <lapin.h>
  #include <unistd.h>
  #include <lapin_enum.h>

void            tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color color)
{
  unsigned int  *pixel;

  pixel = (unsigned int*)pix->pixels;
  pixel[(pix->clipable.clip_width) * pos->y + pos->x] = color.full;
}
