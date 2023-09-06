/*
** flame.c for flame in /home/baris-f/rendu/gfx_incendie
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Dec  5 12:13:26 2015 Florent Baris
** Last update Sun Dec  6 23:34:12 2015 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "my_lap.h"

void		flameloop(t_flam *t, t_pass *pass)
{
  int		i;
  unsigned int	color[4];

  color[0] = WHITE;
  color[1] = YELLOW;
  color[2] = RED;
  color[3] = BLACK;
  i = -1;
  while (++i < pass->img->clipable.clip_width)
    {
      while (++(t->larg) < 40000000);
      t->pos[0].y = pass->img->clipable.clip_height;
      t->pos[0].x = i;
      t->pos[1].y = pass->img->clipable.clip_height - t->born
	+ (t->ran % t->haut) * rand() % 10;
      t->pos[1].x = i;
      t->pos[2].y = pass->img->clipable.clip_height - t->born - t->born2
	+ (t->ran % t->haut) * rand() % 10;
      t->pos[2].x = i;
      t->pos[3].y = pass->img->clipable.clip_height - t->born - t->born2 -
	t->born3 + (t->ran % t->haut) * rand() % 10;
      t->pos[3].x = i;
      tektabgrad(pass->img, t->pos, color, 4);
    }
}

void		flame(t_pass *pass)
{
  t_flam	t;

  t.larg = 10;
  t.haut = 30;
  if ((t.pos = malloc(sizeof(t_bunny_position) * 4)) == NULL)
    return ;
  t.born = rand() % (50 - 80) + 50;
  t.born2 = rand() % (40 - 60) + 40;
  t.born3 = rand() % (30 - 50) + 30;
  t.ran = rand();
  t.mov = rand() % (1 - 3) + 1;
  flameloop(&t, pass);
  free(t.pos);
}
