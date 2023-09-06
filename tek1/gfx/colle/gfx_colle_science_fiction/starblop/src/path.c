/*
** path.c for skd in /home/fus/rendu/gfx_tekadventure/game/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Thu Apr 21 19:45:17 2016 Gaspard Thirion
** Last update Fri Apr 22 00:28:02 2016 Gaspard Thirion
*/

#include "engine.h"

int		sort(t_path *tab, int k)
{
  int		sw;
  int		i;
  t_path	tmp;

  sw = 1;
  while (sw != 0)
    {
      sw = 0;
      i = -1;
      while (++i < k - 1)
	if (tab[i].dist > tab[i + 1].dist)
	    {
	      sw++;
	      tmp = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = tmp;
	}
    }
  return (0);
}

float		calc(t_node *a, t_node *b)
{
  float		ret;

  ret = powere(b->pos.x - a->pos.x, 2) + powere(b->pos.y - a->pos.y, 2);
  return (ret);
}

int		go(t_main *_m, int cur, int targ, int prev)
{
  t_2D		i;
  t_path	*tab;

  if (cur != targ)
    {
      if ((tab = malloc(sizeof(t_path) * _m->map[_m->i].nb_node)) == NULL)
	return (-1);
      i = set2D(i, -1, -1, 1);
      while (++i.x < _m->map[_m->i].nb_node)
	if (_m->map[_m->i].node[cur].link[i.x] != -1 && i.x != cur && i.x != prev)
	  {
	    tab[++i.y].idx = _m->map[_m->i].node[cur].link[i.x];
	    tab[i.y].dist = calc(&_m->map[_m->i].node[tab[i.y].idx], &_m->map[_m->i].node[targ]);
	  }
      if (++i.y == 0)
	return (-2);
      (i.y == 1) ? (go(_m, tab[0].idx, targ, cur)) : (0);
      if (i.y > 1)
	while (sort(tab, i.y) == 0 && go(_m, tab[0].idx, targ, cur) == -2)
	  tab[0].dist = 999999999999;
      free(tab);
    }
  _m->path[++(_m->path[0])] = cur;
  return (0);
}

int		path(t_main *_m, int start, int targ)
{
  int		i;

  _m->path[0] = 0;
  i = 0;
  while (++i < _m->map[_m->i].nb_node)
    _m->path[i] = -1;
  go(_m, start, targ, start);
  i = 0;
  while (++i < _m->map[_m->i].nb_node && _m->path[i] != -1);
  _m->path[0] = i - 1;
  return (0);
}
