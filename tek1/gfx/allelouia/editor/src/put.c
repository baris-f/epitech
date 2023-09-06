/*
** put.c for put in /home/baris-f/rendu/gfx/gfx_tekadventure/baris
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Apr  2 01:45:38 2016 Florent Baris
** Last update Fri Apr  8 13:25:59 2016 Florent Baris
*/

#include "engine.h"

void	delete_node(t_main *_m, int nod)
{
  int	i;

  i = -1;
  while (++i < NB_NODE)
    {
      if (_m->map.node[i].pos.x > -1)
	_m->map.node[i].link[nod] = -1;
      _m->map.node[nod].link[i] = -1;
    }
  _m->map.node[nod].pos.x = -1;
  _m->map.mov = -1;
}

t_2D	tomap(t_main *_m, t_2D pos, int decal)
{
  pos.x += _m->map.pos.x + decal;
  pos.y += _m->map.pos.y + decal;
  return (pos);
}

void	addlink(t_main *_m, int node, int tolink)
{
  if (_m->map.node[node].link[tolink] != tolink)
    {
      _m->map.node[tolink].link[node] = node;
      _m->map.node[node].link[tolink] = tolink;
    }
  else
    {
      _m->map.node[node].link[tolink] = -1;
      _m->map.node[tolink].link[node] = -1;
    }
}
