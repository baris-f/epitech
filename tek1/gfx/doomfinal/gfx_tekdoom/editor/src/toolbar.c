/*
** toolbar.c for toolbar in /home/baris-f/rendu/gfx/gfx_tekdoom/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Jan 19 00:24:23 2016 Florent Baris
** Last update Mon Jan 25 17:45:10 2016 Florent Baris
*/

#include "wolf.h"

void	draw_box(t_img *img, t_2D *pos, t_col col, int full)
{
  t_2D	cur;
  t_2D	max;
  t_2D	empty[5];

  if (full == 0)
    {
      empty[0] = pos[0];
      empty[1].x = pos[1].x;
      empty[1].y = pos[0].y;
      empty[2] = pos[1];
      empty[3].x = pos[0].x;
      empty[3].y = pos[1].y;
      empty[4] = pos[0];
      tektabline(img, empty, col, 5);
	return ;
    }
  max.x = MAX(pos[0].x, pos[1].x);
  max.y = MAX(pos[0].y, pos[1].y);
  cur.x = (MIN(pos[0].x, pos[1].x)) - 1;
  while (++cur.x <= max.x)
    {
      cur.y = (MIN(pos[0].y, pos[1].y)) - 1;
      while (++cur.y <= max.y)
	tekpixel(img, cur, col);
    }
}

void	tooldur(t_base *pass, t_2D *cur, int i)
{
  t_2D	tmp[2];

      tmp[0].x = (cur[0].x + cur[1].x) / 2 - 40;
      tmp[0].y = (cur[0].y + cur[1].y) / 2 - 40;
      tmp[1].x = (cur[0].x + cur[1].x) / 2 + 40;
      tmp[1].y = (cur[0].y + cur[1].y) / 2 + 40;
  if (i == 0)
    tekline(pass->img, tmp, pass->edit.col);
  else if (i == 1)
    draw_box(pass->img, tmp, pass->edit.col, 0);
  else if (i == 2)
    draw_box(pass->img, tmp, pass->edit.col, 1);
  else if (i == 3)
    {
      tmp[0].x = (cur[0].x + cur[1].x) / 2;
      tmp[0].y = (cur[0].y + cur[1].y) / 2;
      tekcircle(pass->img, tmp[0], 30, pass->edit.col);
    }
}

void	toolbar(t_base *pass, t_menu menu)
{
  int	i;
  t_2D	size;
  t_2D	cur[2];

  i = -1;
  draw_box(pass->img, menu.pos, menu.col, 1);
  draw_box(pass->img, menu.pos, menu.scol, 0);
  size.x = (menu.pos[1].x - menu.pos[0].x) * 0.8;
  size.y = (menu.pos[1].y - menu.pos[0].y) / (menu.but + 1);
  cur[0].x = menu.pos[0].x + ((menu.pos[1].x - menu.pos[0].x) - size.x) / 2;
  cur[0].y = menu.pos[0].y + size.y / (menu.but + 1);
  cur[1].x = cur[0].x + size.x;
  cur[1].y = cur[0].y + size.y;
  while (++i < menu.but)
    {
      draw_box(pass->img, cur, menu.bcol[0], 1);
      if (i == menu.cur)
	draw_box(pass->img, cur, RED, 0);
      else
	draw_box(pass->img, cur, menu.bscol[0], 0);
      tooldur(pass, cur, i);
      cur[0].y += size.y + size.y / (menu.but + 1);
      cur[1].y += size.y + size.y / (menu.but + 1);
    }
}

void    palbar(t_base *pass, t_menu menu)
{
  int   i;
  t_2D  size;
  t_2D  cur[2];

  i = -1;
  draw_box(pass->img, menu.pos, menu.col, 1);
  draw_box(pass->img, menu.pos, menu.scol, 0);
  size.y = (menu.pos[1].y - menu.pos[0].y) * 0.8;
  size.x = (menu.pos[1].x - menu.pos[0].x) / (menu.but + 1);
  cur[0].y = menu.pos[0].y + ((menu.pos[1].y - menu.pos[0].y) - size.y) / 2;
  cur[0].x = menu.pos[0].x + size.x / (menu.but + 1);
  cur[1].x = cur[0].x + size.x;
  cur[1].y = cur[0].y + size.y;
  while (++i < menu.but)
    {
      draw_box(pass->img, cur, menu.bcol[i], 1);
      if (i == menu.cur)
	draw_box(pass->img, cur, BLACK, 0);
      else
	draw_box(pass->img, cur, menu.bscol[0], 0);
      cur[0].x += size.x + size.x / (menu.but + 1);
      cur[1].x += size.x + size.x / (menu.but + 1);
    }
}
