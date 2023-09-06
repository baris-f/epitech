/*
** nodes.c for nodes in /home/baris-f/rendu/gfx/gfx_tekadventure/final
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Apr 19 15:36:09 2016 Florent Baris
** Last update Fri Apr 22 00:35:22 2016 Gaspard Thirion
*/

#include "engine.h"

t_2D    tomap(t_main *_m, t_2D pos, int decal)
{
  pos.x += _m->map[_m->i].pos.x + decal;
  pos.y += _m->map[_m->i].pos.y + decal;
  return (pos);
}

void    draw_lines(t_main *_m)
{
  t_2D  cur[2];
  int   i;
  int   j;

  i = -1;
  while (++i < _m->map[_m->i].nb_node)
    {
      j = -1;
      while (++j < _m->map[_m->i].nb_node)
	if (_m->map[_m->i].node[i].link[j] >= 0)
	  {
	    cur[0] = tomap(_m, _m->map[_m->i].node[i].pos, 0);
	    cur[1] = tomap(_m, _m->map[_m->i].node[_m->map[_m->i].node[i].link[j]].pos, 0);
	    line(_m->mimg, cur[0], cur[1], BLACK);
	  }
    }
}

void		dn(t_main *_m, t_node *n)
{
  t_2D		pos;

  pos.x = n->pos.x - n->sprite->dim.x / 2;
  pos.y = n->pos.y - n->sprite->dim.y / 2;
  draw(_m, n->sprite, pos.x, pos.y);
}

void    draw_nodes(t_main *_m)
{
  int   i;
  t_2D  pos[2];
  t_col col;

  i = -1;
  while (++i < _m->map[_m->i].nb_node)
    {
      if (_m->map[_m->i].node[i].pos.x >= 0)
	{
	  (_m->map[_m->i].node[i].type == 1) ? (col = PURPLE) :
	    ((_m->map[_m->i].node[i].type == 2) ? (col = BLUE) :
	     ((_m->map[_m->i].node[i].type == 3) ? (col = GREEN) : (col = RED)));
	  pos[0].x = _m->map[_m->i].pos.x + _m->map[_m->i].node[i].pos.x
	    - _m->map[_m->i].node[i].scale.x;
	  pos[0].y = _m->map[_m->i].pos.y + _m->map[_m->i].node[i].pos.y
	    - _m->map[_m->i].node[i].scale.y;
	  pos[1].x = _m->map[_m->i].pos.x + _m->map[_m->i].node[i].pos.x
	    + _m->map[_m->i].node[i].scale.x;
	  pos[1].y = _m->map[_m->i].pos.y + _m->map[_m->i].node[i].pos.y
	    + _m->map[_m->i].node[i].scale.y;
	  dn(_m, &(_m->map[_m->i].node[i]));
	  draw_box(_m->mimg, pos, col, _m->map[_m->i].node[i].full);
	}
    }
}
