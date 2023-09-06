/*
** tekpixel.c for chromatic in /home/baris-f/rendu/skilltest/chromatic_2020
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb  2 14:10:11 2016 Florent Baris
** Last update Mon Feb  8 17:11:31 2016 Florent Baris
*/

#include <lapin.h>
#include <math.h>

# define ABS(Value) ((Value < 0) ? (Value * -1) : (Value))

typedef struct          s_line
{
  int   dx;
  int   dy;
  int   xinc;
  int   yinc;
  int   cumul;
}                       t_line;


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

void                    tekfill(t_bunny_pixelarray *img, unsigned int col)
{
  unsigned int          *buff;
  int                   i;
  int                   max;

  i = -1;
  max = (img->clipable.clip_width * img->clipable.clip_height);
  buff = (unsigned int*)img->pixels;
  while (++i < max)
    buff[i] = col;
}

int                     main(int ac, char **av)
{
  int                   x;
  int                   y;
  t_bunny_window	*win;
  t_bunny_pixelarray	*img;
  t_bunny_position	pos[2];
  t_bunny_circle	circle[1];
  float			angle;

  angle = 0;
  circle[0].position.x = 640;
  circle[0].position.y = 360;
  circle[0].radius = 200;
  circle[0].color = RED;
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
  while (1)
    {
      tekfill(img, BLACK);
      angle += 0.005;
      mystic_clock(img, circle, angle, 4);
      bunny_blit(&(win->buffer), &(img->clipable), &pos[0]);
      bunny_display(win);
    }
  bunny_delete_clipable(&img->clipable);
  bunny_stop(win);
  return (0);
}
