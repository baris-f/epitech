/*
** tekpixel.c for chromatic in /home/baris-f/rendu/skilltest/chromatic_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb  2 14:10:11 2016 Florent Baris
** Last update Tue Feb 16 14:29:30 2016 Florent Baris
*/

#include <lapin.h>
#include <math.h>

typedef struct s_bunny_3d_space
{
  t_color *buffer; /* size is width * height * depth */
  int width; /* width in cube */
  int height; /* height in cube */
  int depth; /* depth in cube */
  int cube_size; /* the size of one cube */
} t_bunny_3d_space;

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  buff[idx] = col;
}


t_color	*tekgetvertex(t_bunny_3d_space *buf, int x, int y, int z)
{
  return (0);
}

void	flashlight(t_bunny_pixelarray *pix, int eye_screen_dist,
	   const t_bunny_position *pos, const t_bunny_3d_space *buf)
{
  return (0);
}
