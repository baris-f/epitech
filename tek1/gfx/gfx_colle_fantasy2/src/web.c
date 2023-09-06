/*
** web.c for web in /home/baris-f/rendu/gfx/gfx_colle_fantasy2
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Mon Jan 11 14:32:15 2016 Florent Baris
** Last update Mon Jan 11 18:45:10 2016 Florent Baris
*/

#include "wolf.h"

void	init(t_pass *pass, int nb)
{
  (IMG_WIDTH > IMG_HEIGHT) ? (pass->max = IMG_HEIGHT) : (pass->max = IMG_WIDTH);
  pass->alpha = 0;
  pass->p = (float)((360 / (float)(nb)) / 180 * M_PI);
}

void	initcur(t_pass *pass, t_pos *c)
{
  c[0].x = IMG_WIDTH / 2;
  c[0].y = IMG_HEIGHT / 2;
  c[1].x = c[0].x + cos(pass->alpha) * pass->max / 2;
  c[1].y = c[0].y + sin(pass->alpha) * pass->max / 2;
}

void	web(t_pass *pass, int nb, int face)
{
  int	i;
  int	j;
  t_pos	c[2];
  t_pos **tpos;

  i = -1;
  tpos = malloc(sizeof(t_pos) * face);
  while (++i < face)
    tpos[i] = malloc(sizeof(t_pos) * (nb + 1));
  init(pass, nb);
  i = -1;
  while (++i < nb)
    {
      initcur(pass, c);
      j = -1;
      while (++j < face)
      	{
      	  tpos[j][i].x = (c[0].x - (c[0].x - c[1].x) * ((float)(j + 1) / face));
      	  tpos[j][i].y = (c[0].y - (c[0].y - c[1].y) * ((float)(j + 1) / face));
      	}
      tekline(pass->img, c, WHITE);
      pass->alpha += pass->p;
    }
  i = -1;
  while (++i < face)
    {
      tpos[i][nb] = tpos[i][0];
      tektabline(pass->img, tpos[i], WHITE, nb + 1);
    }
}
