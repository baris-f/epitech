/*
** draw.c for draw in /home/baris-f/rendu/gfx/gfx_tekadventure/baris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Apr  1 16:10:28 2016 Florent Baris
** Last update Thu Apr 21 13:09:58 2016 Gaspard Thirion
*/

#include "engine.h"

void	draw_lines(t_main *_m)
{
  t_2D	cur[2];
  int	i;
  int	j;

  if (_m->map.curlin.x == 1 && inmap(_m, _m->mouse[0]))
    {
      cur[0] = tomap(_m, _m->map.node[_m->map.curlin.y].pos, 0);
      cur[1] = _m->mouse[0];
      tekline(_m->mimg, cur, BLACK);
    }
  i = -1;
  while (++i < NB_NODE)
    {
      j = -1;
      while (++j < NB_NODE)
	if (_m->map.node[i].link[j] >= 0)
	  {
	    cur[0] = tomap(_m, _m->map.node[i].pos, 0);
	    cur[1] = tomap(_m, _m->map.node[_m->map.node[i].link[j]].pos, 0);
	    tekline(_m->mimg, cur, BLACK);
	  }
      }
}

void	draw_node_text(t_main *_m, int i, t_node *n)
{
  t_clip	*clip;
  t_img		*img;
  t_2D		pos;

  clip = &_m->text[i].img->clipable;
  img = _m->text[i].img;
  clip->clip_x_position = 0;
  clip->clip_y_position = 0;
  clip->clip_width = clip->buffer.width;
  clip->clip_height = clip->buffer.height;
  clip->scale.x = 1;
  clip->scale.y = 1;
  pos.x = n->pos.x - clip->clip_width/ 2;
  pos.y = n->pos.y - clip->clip_height / 2;
  blit(_m->mimg, img, pos);
}

void	draw_nodes(t_main *_m)
{
  int	i;
  t_2D	pos[2];
  t_col	col;

  i = -1;
  while (++i < NB_NODE)
    {
      if (_m->map.node[i].pos.x >= 0)
	{
	  (_m->map.node[i].type == 1) ? (col = PURPLE) :
	    ((_m->map.node[i].type == 2) ? (col = BLUE) :
	     ((_m->map.node[i].type == 3) ? (col = GREEN) : (col = RED)));
	  pos[0].x = _m->map.pos.x + _m->map.node[i].pos.x
	    - _m->map.node[i].scale.x;
	  pos[0].y = _m->map.pos.y + _m->map.node[i].pos.y
	    - _m->map.node[i].scale.y;
	  pos[1].x = _m->map.pos.x + _m->map.node[i].pos.x
	    + _m->map.node[i].scale.x;
	  pos[1].y = _m->map.pos.y + _m->map.node[i].pos.y
	    + _m->map.node[i].scale.y;
	  draw_node_text(_m, _m->map.node[i].act_text, &(_m->map.node[i]));
	  draw_box(_m->mimg, pos, col, _m->map.node[i].full);

	}
    }
}
