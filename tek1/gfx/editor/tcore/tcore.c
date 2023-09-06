/*
** tcore.c for tcore in /home/baris-f/rendu/gfx_wolf3d/tcore
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Jan  3 20:18:23 2016 Florent Baris
** Last update Sun Jan  3 22:50:35 2016 Florent Baris
*/

void tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color)
{
  unsigned int          *buff;
  int                   idx;

  buff = (unsigned int*)img->pixels;
  idx = img->clipable.clip_width * pos->y + pos->x;
  if (idx <= img->clipable.clip_width * img->clipable.clip_height
      && idx >= 0)
    buff[idx] = col->full;
}

double vecnorm(t_bunny_position *coord0, t_bunny_position *coord1)
{
  return (sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2)));
}

void go(t_bunny_position *curpos, double angle,
	t_bunny_position *newpos, int move)
{
  if (ang > 0)
    {
      new->x = -cos(ang) * move + old->x;
      new->y = -sin(ang) * move + old->y;
    }
  else
    {
      new->x = cos(ang) * move + old->x;
      new->y = sin(ang) * move + old->y;
    }
}
