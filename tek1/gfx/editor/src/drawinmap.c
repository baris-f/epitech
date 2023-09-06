/*
** drawinmap.c for drawinmap in /home/baris-f/rendu/gfx/gfx_tekdoom/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Jan 19 00:20:07 2016 Florent Baris
** Last update Wed Jan 20 16:35:07 2016 Florent Baris
*/

#include "../inc/wolf.h"

void		circleinmap(t_base *pass, t_2D *lpos, t_img *map, t_col col)
{
  int           whalf;
  int           hhalf;
  int		radius;
  t_2D          pos[2];

  whalf = map->clipable.clip_width * pass->edit.scale / 2;
  hhalf = map->clipable.clip_height * pass->edit.scale / 2;
  pos[0].x = (lpos[0].x - (pass->edit.center.x - whalf)) / pass->edit.scale;
  pos[0].y = (lpos[0].y - (pass->edit.center.y - hhalf)) / pass->edit.scale;
  pos[1].x = (lpos[1].x - (pass->edit.center.x - whalf)) / pass->edit.scale;
  pos[1].y = (lpos[1].y - (pass->edit.center.y - hhalf)) / pass->edit.scale;
  if (pos[1].x > pos[0].x)
    radius = pos[1].x - pos[0].x;
  else
    radius = pos[0].x - pos[1].x;
  if (radius < pos[1].y - pos[0].y)
    radius = pos[1].y - pos[0].y;
  else if (radius < pos[0].y - pos[1].y)
    radius = pos[0].y - pos[1].y;
  if (pos[0].x - radius >= 0 && pos[0].x + radius <= pass->edit.map->clipable.clip_width
      && pos[0].y - radius >= 0 && pos[0].y +
      radius <= pass->edit.map->clipable.clip_height &&
      pos[1].x >= 0 && pos[1].x <= pass->edit.map->clipable.clip_width
      && pos[1].y >= 0 && pos[1].y <= pass->edit.map->clipable.clip_height)
    tekcircle(map, pos[0], radius, col);
}

void            addinmap(t_base *pass, t_2D pos, t_img *map, t_col col)
{
  int           whalf;
  int           hhalf;
  unsigned int  *buff;

  whalf = pass->edit.map->clipable.clip_width * pass->edit.scale / 2;
  hhalf = pass->edit.map->clipable.clip_height * pass->edit.scale / 2;
  pos.x = (pos.x - (pass->edit.center.x - whalf)) / pass->edit.scale;
  pos.y = (pos.y - (pass->edit.center.y - hhalf)) / pass->edit.scale;
  buff = (unsigned int*)map->pixels;
  if (pos.x >= 0 && pos.x < pass->edit.map->clipable.clip_width
      && pos.y >= 0 && pos.y < pass->edit.map->clipable.clip_height)
    buff[pos.y * map->clipable.clip_width + pos.x] = col;
}

void            lineinmap(t_base *pass, t_2D *lpos, t_img *map, t_col col)
{
  int           whalf;
  int           hhalf;
  t_2D          pos[2];

  whalf = map->clipable.clip_width * pass->edit.scale / 2;
  hhalf = map->clipable.clip_height * pass->edit.scale / 2;
  pos[0].x = (lpos[0].x - (pass->edit.center.x - whalf)) / pass->edit.scale;
  pos[0].y = (lpos[0].y - (pass->edit.center.y - hhalf)) / pass->edit.scale;
  pos[1].x = (lpos[1].x - (pass->edit.center.x - whalf)) / pass->edit.scale;
  pos[1].y = (lpos[1].y - (pass->edit.center.y - hhalf)) / pass->edit.scale;
  if (pos[0].x >= 0 && pos[0].x < pass->edit.map->clipable.clip_width
            && pos[0].y >= 0 && pos[0].y < pass->edit.map->clipable.clip_height &&
              pos[1].x >= 0 && pos[1].x < pass->edit.map->clipable.clip_width
      && pos[1].y >= 0 && pos[1].y < pass->edit.map->clipable.clip_height)
    tekline(map, pos, col);
}

void    draw_boxinmap(t_base *pass, t_2D *lpos, t_col col, int full, t_img *tmp)
{
  int           whalf;
  int           hhalf;
  t_2D          pos[2];

  whalf = tmp->clipable.clip_width * pass->edit.scale / 2;
  hhalf = tmp->clipable.clip_height * pass->edit.scale / 2;
  pos[0].x = (lpos[0].x - (pass->edit.center.x - whalf)) / pass->edit.scale;
  pos[0].y = (lpos[0].y - (pass->edit.center.y - hhalf)) / pass->edit.scale;
  pos[1].x = (lpos[1].x - (pass->edit.center.x - whalf)) / pass->edit.scale;
  pos[1].y = (lpos[1].y - (pass->edit.center.y - hhalf)) / pass->edit.scale;
  if (pos[0].x >= 0 && pos[0].x < pass->edit.map->clipable.clip_width
                && pos[0].y >= 0 && pos[0].y < pass->edit.map->clipable.clip_height &&
                  pos[1].x >= 0 && pos[1].x < pass->edit.map->clipable.clip_width
      && pos[1].y >= 0 && pos[1].y < pass->edit.map->clipable.clip_height)
    draw_box(tmp, pos, col, full);
}
