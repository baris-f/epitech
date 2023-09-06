/*
** raycast.c for raycast in /home/baris-f/rendu/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Dec 31 13:34:49 2015 Florent Baris
** Last update Thu Jan 14 13:40:02 2016 Florent Baris
*/

#include "../inc/wolf.h"

int     whererayis(t_pass *pass, float posx, float posy)
{
  float x;
  float y;
  int   ret;

  ret = 0;
  x = posx / (float)pass->ini->scale;
  y = posy / (float)pass->ini->scale;
  if (x <= 0 || y <= 0 || x >= pass->ini->dim.x || y >= pass->ini->dim.y)
    return (1);
  else
    ret = my_getnbr(bunny_ini_scope_get_field(pass->ini->scope, "data",
					 (int)x + (int)y * pass->ini->dim.x));
  return (ret);
}

float	DDA(t_pass *pass, float ang)
{
  float	dist;
  float	x;
  float	y;
  float	dx;
  float dy;

  dist = 0.;
  x = (float)pass->player->pos.x;
  y = (float)pass->player->pos.y;
  dx = (cos((ang * M_PI) / 180)) / 2;
  dy = (-sin((ang * M_PI) / 180)) / 2;
  while (whererayis(pass, x, y) != 1)
    {
      dist += 0.2;
      x = x + dx;
      y = y + dy;
    }
  return (dist);
}

void	raycast(t_pass *pass)
{
  float	angle;
  float	i;
  float	dist;
  t_pos	pos[2];
  float	divi;

  divi = IMG_WIDTH / (float)FOV;
  i = 0;
  angle = (float)pass->player->ang - FOVHALF;
  (angle < 0) ? angle += 360. : 0;
  while (i < FOV)
    {
      if (i < FOVHALF)
	dist = DDA(pass, angle + (FOV - i)) * cos((FOVHALF - i) * M_PI / 180);
      else
	dist = DDA(pass, angle + (FOV - i)) * cos((i - FOVHALF) * M_PI / 180);
      pos[0].y = IMG_HEIGHTHALF - IMG_HEIGHT * 8 / dist;
      pos[1].y = IMG_HEIGHTHALF + IMG_HEIGHT * 8 / dist;
      pos[0].x = i * divi;
      pos[1].x = pos[0].x;
      tekline(pass->img, pos, 0xFF333333);
      i += (float)FOVANG;
    }
}
