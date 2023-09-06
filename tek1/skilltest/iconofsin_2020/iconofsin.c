/*
** iconofsin.c for iconofsin in /home/baris_f/rendu/iconofsin_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Nov 16 09:07:03 2015 Florent Baris
** Last update Mon Jan 11 15:31:05 2016 Florent Baris
*/

#include <lapin.h>
#include <unistd.h>
#include <lapin_enum.h>
#include <math.h>

void    my_set_pixel(t_bunny_pixelarray *pix, t_bunny_position pos, unsigned int color)
{
  unsigned int *pixel;

  pixel = pix->pixels;
  pixel[(pix->clipable.clip_width) * pos.y + pos.x] = color;
}

int                     my_abs(int num)
{
  return ((num > 0) ? num : -(num));
}

void            tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int  *pixel;

  pixel = pix->pixels;
  pixel[(pix->clipable.clip_width) * pos->y + pos->x] = color;
}

void                    my_set_line(t_bunny_pixelarray *pix,
                                    t_bunny_position pos1
				    ,t_bunny_position pos2,  unsigned int color)
{
  int                   dx;
  int                   dy;
  int                   xinc;
  int                   yinc;
  int                   cumul;
  int                   i;

  dx = pos2.x - pos1.x;
  dy = pos2.y - pos1.y;
  xinc = (dx > 0) ? 1 : -1;
  yinc = (dy > 0) ? 1 : -1;
  dx = my_abs(dx);
  dy = my_abs(dy);
  tekpixel(pix, &pos1, color);
  i = 1;
  if (dx > dy)
    {
      cumul = dx / 2;
      while (i <= dx)
        {
	  pos1.x += xinc;
          cumul += dy;
          if (cumul >= dx)
            {
	      cumul -= dx;
              pos1.y += yinc;
            }
          tekpixel(pix, &pos1, color);
          i++;
        }
    }
  else
    {
      cumul = dy / 2;
      while (i <= dy)
        {
          pos1.y += yinc;
          cumul += dx;
          if (cumul >= dy)
            {
              cumul -= dy;
              pos1.x += xinc;
            }
          tekpixel(pix, &pos1, color);
          i++;
        }
    }
}

void                    my_ovale(t_bunny_pixelarray *pix, t_bunny_position O, float R, float p, unsigned int color)
{
  t_bunny_position      cur;
  float                 alpha;

  alpha = 0.0;
  p = p / 180 * M_PI;
  while (alpha < 2 * M_PI)
    {
      alpha += p;
      cur.x = O.x + cos(alpha) * pix->clipable.clip_width / 2 * 0.9;
      cur.y = O.y + sin(alpha) * pix->clipable.clip_height / 2 * 0.9;
      my_set_pixel(pix, cur, color);
    }
}

void lightning(t_bunny_pixelarray *pix,
               t_bunny_position *pos,
               size_t npos)
{
  int   i;

  i = -1;
  while (++i < npos - 1)
    my_set_line(pix, pos[i], pos[i+1], RED);
}

void			icon_of_sin(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_bunny_position	cur;
  t_bunny_position	tpos[13];
  int	i;
  float	alpha;
  float decal;

  decal = 1;
  alpha = M_PI * 6/4;
  i = -1;
  pos.x = pix->clipable.clip_width / 2;
  pos.y = pix->clipable.clip_height / 2;
  while (++i < 13)
    {
      cur.x = pos.x + cos(alpha) * pix->clipable.clip_width / 2 * 0.9;
      cur.y = pos.y + sin(alpha) * pix->clipable.clip_height / 2 * 0.9;
      alpha += M_PI * decal;
      if (decal == 1)
	decal = decal * 5/6;
      else
	decal = 1;
      tpos[i].x = cur.x;
      tpos[i].y = cur.y;
    }
  my_ovale(pix, pos, pix->clipable.clip_width / 2 * 0.9, 0.01, RED);
  lightning(pix, tpos, 13);
}

void			icon_of_sin_nbr(t_bunny_pixelarray *pix,
		     size_t branch)
{

}
