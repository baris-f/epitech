/*
** export.c for efniz in /home/fus/rendu/gfx_tekadventure/baris/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Mon Apr 18 16:34:39 2016 Gaspard Thirion
** Last update Thu Apr 21 19:20:23 2016 Gaspard Thirion
*/

#include "engine.h"

void		put_node(t_main *_m, char *scp, t_node *nod, t_ini *ini)
{
  int		i;
  int		k;

  set(ini, scp, "pos", 0, nts(nod->pos.x));
  set(ini, scp, "pos", 1, nts(nod->pos.y));
  set(ini, scp, "size", 0, nts(nod->scale.x));
  set(ini, scp, "size", 1, nts(nod->scale.y));
  set(ini, scp, "full", 0, nts(nod->full));
  set(ini, scp, "type", 0, nts(nod->type));
  if (_m->text[nod->act_text].id)
    set(ini, scp, "img", 0, _m->text[nod->act_text].id);
  i = -1;
  k = 0;
  while (++i < NB_NODE)
    if (nod->link[i] > -1)
      {
	k++;
	set(ini, scp, "link", k - 1, nts(nod->link[i]));
      }
  set(ini, scp, "nlink", 0, nts(k));
}

int		export(t_main *_m, char *path)
{
  t_ini		*ini;
  int		i;
  int		k;

  if (((ini = bunny_load_ini(path)) == NULL
       && (ini = bunny_new_ini()) == NULL))
    return (-1);
  set(ini, "main", "img", 0, _m->map.name);
  i = -1;
  k = 0;
  while (++i < NB_NODE)
    if (_m->map.node[i].pos.x > -1)
      {
	k++;
	set(ini, "main", "nodes", k - 1, nts(k));
	put_node(_m, nts(k), &_m->map.node[i], ini);
      }
  set(ini, "main", "nb", 0, nts(k));
  bunny_save_ini(ini, path);
  return (0);
}
