/*
** binarizer.c for binarizer in /home/baris-f/rendu/binarizer_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Dec  9 14:08:29 2015 Florent Baris
** Last update Wed Dec  9 14:26:26 2015 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include "my_lap.h"

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

t_bunny_pixelarray	*load_bitmap(const char *file)
{

}

void			all_grey(t_bunny_pixelarray *pix)
{

}

void			binarize(t_bunny_pixelarray *pix)
{

}
