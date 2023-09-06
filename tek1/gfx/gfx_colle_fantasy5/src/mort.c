/*
** mort.c for mort in /home/baris-f/rendu/gfx/gfx_colle_fantasy5
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Jan 13 09:12:07 2016 Florent Baris
** Last update Wed Jan 13 14:30:22 2016 Florent Baris
*/

#include <stdio.h>
#include "wolf.h"

void	sideini(int side, t_pos *pos, t_pos *bpos, float size)
{
  int	hauteur;

  hauteur = (sqrt(3)/2 * (float)size);
  if (side == 1)
    {
      bpos[0].x = pos[0].x;
      bpos[0].y = pos[0].y - hauteur * 2 / 3;
      bpos[1].x = pos[0].x - size / 2;
      bpos[1].y = pos[0].y + hauteur / 3;
      bpos[2].x = pos[0].x + size / 2;
      bpos[2].y = pos[0].y + hauteur / 3;
    }
  else
    {
      bpos[0].x = pos[0].x;
      bpos[0].y = pos[0].y + hauteur * 2 / 3;
      bpos[1].x = pos[0].x + size / 2;
      bpos[1].y = pos[0].y - hauteur / 3;
      bpos[2].x = pos[0].x - size / 2;
      bpos[2].y = pos[0].y - hauteur / 3;
    }
}

void		triangle(t_pass *pass, t_pos *pos, int side, float size)
{
  t_pos		bpos[3];
  t_pos		cur[2];
  int		i;
  unsigned int	color;

  if (pass->fill == 1)
    color = pass->rand;
  else
    color = pass->col;
  i = -1;
  sideini(side, pos, bpos, size);
  while (++i < 2)
    {
      cur[0] = bpos[i];
      cur[1] = bpos[i + 1];
      tekline(pass->img, cur, color);
    }
  cur[0] = bpos[2];
  cur[1] = bpos[0];
  tekline(pass->img, cur, color);
  i = bpos[0].y - size/ 7.7;
  while (++i < bpos[2].y)
    {
      cur[0].x = bpos[1].x - cos(300 * (M_PI / 180)) * (i - bpos[2].y);
      cur[0].y = bpos[1].y - sin(300 * (M_PI / 180)) * (i - bpos[2].y);
      cur[1].x = bpos[2].x - cos(240 * (M_PI / 180)) * (i - bpos[2].y);
      cur[1].y = bpos[2].y - sin(240 * (M_PI / 180)) * (i - bpos[2].y);
      tekline(pass->img, cur, color);
    }
}

void	mort(t_pass *pass, t_pos *pos, int side, float size)
{
  int	i;
  t_pos	*all;
  int	j;
  int	hauteur;
  int	test;

  if ((all = malloc(sizeof(t_pos) * pow(3, pass->nb))) == NULL)
    return ;
  all[0] = pos[0];
  i = -1;
  while (++i <= pass->nb)
    {
      j = pow(3, i) - 1;
      size /= 2;
      while (j > 0)
	{
	  hauteur = (sqrt(3)/2 * (float)size);
	  test = j - (j - j / 3);
	  all[j].x = all[test].x + size / 2;
	  all[j].y = all[test].y + hauteur / 3;
	  all[j - 1].x = all[test].x - size / 2;
	  all[j - 1].y = all[test].y + hauteur / 3;
	  all[j - 2].x = all[test].x;
	  all[j - 2].y = all[test].y - hauteur * 2 / 3;
	  j -= 3;
	}
    }
  i = -1;
  while (++i < pow(3, pass->nb))
    triangle(pass, &all[i], side, size);
  free(all);
}
