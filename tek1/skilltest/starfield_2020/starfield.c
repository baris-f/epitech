/*
** starfield.c for starfield in /home/baris-f/rendu/starfield_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Nov 26 14:33:30 2015 Florent Baris
** Last update Thu Nov 26 16:38:07 2015 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include <lapin_enum.h>

typedef struct s_bunny_star
{
  int	y;
  float	x;
  float	x_speed;
} t_bunny_star;

void    my_fill(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int *pixel;
  int           i;

  i = -1;
  pixel = (unsigned int*)pix->pixels;
  while (pixel[++i])
    pixel[i] = color;
}

void            tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int  *pixel;
  int		index;

  pixel = (unsigned int*)pix->pixels;
  index = (pix->clipable.clip_width) * pos->y + pos->x;
  if (index > 0)
    pixel[index] = color;
}

void			starfield(t_bunny_pixelarray *pix,
	    t_bunny_star *star,
	    size_t	nstar)
{
  t_bunny_position	cur;
  int			i;

  i = -1;
  my_fill(pix, BLACK);
  while (++i < nstar)
    {
      star[i].x += star[i].x_speed;
      if (star[i].x < 0)
	{
	  star[i].y = rand()% pix->clipable.clip_height;
	  star[i].x +=  pix->clipable.clip_width - 1;
	}
	cur.y = star[i].y;
      cur.x = star[i].x;
      tekpixel(pix, &cur, WHITE);
    }
}
