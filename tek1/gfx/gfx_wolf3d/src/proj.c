/*
** proj.c for proj in /home/baris-f/liblapin/projection
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Wed Dec  9 15:59:36 2015 Florent Baris
** Last update Sun Jan  3 23:33:55 2016 Florent Baris
*/

#include "../inc/wolf.h"

void			proj(t_pass *pass)
{
  t_bunny_position	player;
  t_bunny_position	view[1];

  player.x = (pass->player->pos.x * 25. /
	      pass->ini->dim.x) / (pass->ini->scale / 10.);
  player.y = (pass->player->pos.y * 25. /
	      pass->ini->dim.y) / (pass->ini->scale / 10.);
  tekpixel(pass->img, &player, RED);
  polcar(view, pass->player->ang, pass->player->len);
  view->x += player.x;
  view->y += player.y;
  tekpixel(pass->img, view, GREEN);
}
