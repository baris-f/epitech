/*
** calc2.c for in /home/grandma/gfx_wolf3d
**
** Made by Corentin Grandmaire
** Login   <grandm_a@epitech.net>
**
** Started on  Tue Dec 10 10:23:37 2015 Corentin Grandmaire
** Last update Thu Jan 14 13:24:45 2016 Florent Baris
*/
#include <wolf.h>

void			calchit(t_pass *wolf)
{
  while (wolf->rcast.hit == 0)
    {
      if (wolf->rcast.dist.x < wolf->rcast.dist.y)
	{
	  wolf->rcast.wall_side = 0;
	  wolf->rcast.dist.x += wolf->rcast.delta.x;
	  wolf->rcast.map_pos.x += wolf->rcast.step.x;
	}
      else
	{
	  wolf->rcast.wall_side = 1;
	  wolf->rcast.dist.y += wolf->rcast.delta.y;
	  wolf->rcast.map_pos.y += wolf->rcast.step.y;
	}
      if (wolf->ini.data[wolf->rcast.map_pos.x][wolf->rcast.map_pos.y] > 0)
	wolf->rcast.hit = 1;
    }
}

void			putwall2(t_pass *wolf)
{
  if (wolf->rcast.wall_side == 0)
    {
      wolf->color->full = 0xFF9b9b9b;
      wolf->rcast.wall_dist = ABS((wolf->rcast.map_pos.x - wolf->player.x +
			 (1 - wolf->rcast.step.x) / 2) / wolf->vect.v_ray.x);
    }
  else
    {
      wolf->color->full = 0xFFcbcbcb;
      wolf->rcast.wall_dist = ABS((wolf->rcast.map_pos.y - wolf->player.y +
			 (1 - wolf->rcast.step.y) / 2) / wolf->vect.v_ray.y);
    }
  wolf->rcast.line_height = ABS(HEIGHT / wolf->rcast.wall_dist);
}

void			putwall(int x, t_pass *wolf)
{
  unsigned int		color;

  color = SKY;
  wolf->rcast.line_coord[0].x = x;
  wolf->rcast.line_coord[1].x = x;
  wolf->rcast.line_coord[0].y = 0;
  wolf->rcast.line_coord[1].y = (HEIGHT / 2) - (wolf->rcast.line_height / 2);
  tekline(wolf->pix, wolf->rcast.line_coord, color);
  wolf->rcast.line_coord[0].y = wolf->rcast.line_coord[1].y;
  wolf->rcast.line_coord[1].y = (HEIGHT / 2) + (wolf->rcast.line_height / 2);
  tekline(wolf->pix, wolf->rcast.line_coord, wolf->color);
  color = FLOOR;
  wolf->rcast.line_coord[0].y = wolf->rcast.line_coord[1].y;
  wolf->rcast.line_coord[1].y = HEIGHT - 1;
  tekline(wolf->pix, wolf->rcast.line_coord, color);
}
