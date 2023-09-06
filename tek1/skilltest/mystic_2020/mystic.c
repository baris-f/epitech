/*
** tekpixel.c for chromatic in /home/baris-f/rendu/skilltest/chromatic_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb  2 14:10:11 2016 Florent Baris
** Last update Mon Feb  8 17:11:15 2016 Florent Baris
*/

#include <lapin.h>
#include <math.h>

typedef struct s_bunny_circle
{
  t_bunny_position position;
  double radius;
  unsigned int color;
}  t_bunny_circle;

void                    tekpixel(t_bunny_pixelarray *img, t_bunny_position *pos,
				 unsigned int col)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  buff[idx] = col;
}

void                    tekcircle(t_bunny_pixelarray *pix, t_bunny_position *pos,
				  double radius,
				  unsigned int color)
{
  t_bunny_position      cur;
  float                 alpha;
  float                 p;

  alpha = 0.0;
  p = 0.05;
  p = p / 180 * M_PI;
  while (alpha < 2 * M_PI)
    {
      alpha += p;
      cur.x = pos->x + cos(alpha) * radius;
      cur.y = pos->y + sin(alpha) * radius;
      tekpixel(pix, &cur, color);
    }
}

void	mystic_clock(t_bunny_pixelarray *pix, const t_bunny_circle *circle,
	     double angle, size_t depth){
  t_bunny_circle        circles[1];

  if (depth <= 0)
    return ;
  circles[0] = circle[0];
  tekcircle(pix, &circle->position, circle->radius, circle->color);
  if (--depth > 0)
    {
      circles->color = circles->color * -1;
      circles->radius /= 2;
      angle += M_PI;
      angle *= -2;
      circles->position.x += cos(angle) * circle->radius;
      circles->position.y += sin(angle) * circle->radius;
      mystic_clock(pix, circles, angle, depth);
    }
}
