/*
** tcore.c for tcore in /home/baris-f/rendu/gfx_fdf2/tcore
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Dec 21 12:51:29 2015 Florent Baris
** Last update Mon Dec 21 12:53:07 2015 Florent Baris
*/

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 t_color *col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  if (idx <= img->clipable.clip_width * img->clipable.clip_height
      && idx >= 0)
    buff[idx] = col->full;
}
