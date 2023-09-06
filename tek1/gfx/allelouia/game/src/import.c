/*
** import.c for isck in /home/fus/rendu/gfx_tekadventure/baris/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Wed Apr 20 10:04:24 2016 Gaspard Thirion
** Last update Thu Apr 21 19:28:18 2016 Gaspard Thirion
*/

#include "engine.h"

int		glink(t_node *nod, char *scp, t_ini *ini)
{
  char		*tmp;
  int		i;
  int           nb;

  if ((nod->link = malloc(sizeof(int) * nod->nb_link)) == NULL)
    return (-1);
  i = -1;
  while (++i < nod->nb_link)
    nod->link[i] = -1;
  if ((tmp = get_field(ini, scp, "nlink", 0)) == NULL
      || (nod->nb_link = my_getnbr(tmp)) < 0)
    nod->nb_link = 0;
  i = -1;
  while (++i < nod->nb_link)
    {
      if ((tmp = get_field(ini, scp, "link", i)) == NULL
	  || (nb = my_getnbr(tmp)) < 0)
	nb = -1;
      if (nb != -1)
	nod->link[nb] = nb;
    }
  return (0);
}

int		gnode(t_main *_m, t_node *nod, char *scp, t_ini *ini)
{
  char		*tmp;

  tmp = get_field(ini, scp, "img", 0);
  if ((nod->sprite = new_sprite(_m, (tmp) ? (tmp) : ("dbg"))) == NULL)
    return (-1);
  if ((tmp = get_field(ini, scp, "pos", 0)) == NULL
      || (nod->pos.x = my_getnbr(tmp)) < 0)
    nod->pos.x = 0;
  if ((tmp = get_field(ini, scp, "pos", 1)) == NULL
      || (nod->pos.y = my_getnbr(tmp)) < 0)
    nod->pos.y = 0;
  if ((tmp = get_field(ini, scp, "size", 0)) == NULL
      || (nod->scale.x = my_getnbr(tmp)) < 0)
    nod->scale.x = 0;
  if ((tmp = get_field(ini, scp, "size", 1)) == NULL
      || (nod->scale.y = my_getnbr(tmp)) < 0)
    nod->scale.y = 0;
  if ((tmp = get_field(ini, scp, "full", 0)) == NULL
      || (nod->full = my_getnbr(tmp)) < 0)
    nod->full = 0;
  if ((tmp = get_field(ini, scp, "type", 0)) == NULL
      || (nod->type = my_getnbr(tmp)) < 0)
    nod->type = 0;
  return (glink(nod, scp, ini));
}

int		gmap(t_main *_m, t_map *map, char *file)
{
  t_ini		*ini;
  char		*tmp;
  int		i;

  if ((ini = bunny_load_ini(file)) == NULL
      && (ini = bunny_new_ini()) == NULL)
    return (-1);
  if ((map->name = get_field(ini, "main", "img", 0)) == NULL
      || (_m->map->back = new_sprite(_m, map->name)) == NULL
      || (tmp = get_field(ini, "main", "nb", 0)) == NULL
      || (map->nb_node = my_getnbr(tmp)) < 1
      || (map->node = malloc(sizeof(t_node) * map->nb_node)) == NULL)
    return (-1);
  i = -1;
  while (++i < map->nb_node)
    {
      map->node[i].nb_link = map->nb_node;
    if ((tmp = get_field(ini, "main", "nodes", i)) == NULL
	|| gnode(_m, &(map->node[i]), tmp, ini) == -1)
      return (-1);
    }
  return (0);
}

int		map(t_main *_m, t_ini *proj)
{
  char		*tmp;
  int		i;

  while ((tmp = get_field(proj, "maps", "nb", 0)) == NULL
	 || (_m->nb_map = my_getnbr(tmp)) < 0)
    set(proj, "maps", "nb", 0, "0");
  if (_m->nb_map > 0
      && (_m->map = malloc(sizeof(t_map) * _m->nb_map)) == NULL)
    return (-1);
  i = -1;
  while (++i < _m->nb_map)
    {
      while ((tmp = get_field(proj, "maps", "list", 0)) == NULL)
	set(proj, "maps", "nb", 0, nts(i + 1));
      if (gmap(_m, &(_m->map[i]), tmp) == -1)
	return (-1);
    }
  return (0);
}
