/*
** load.c for zplf in /home/fus/rendu/gfx_tekadventure/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Sat Apr  9 23:05:31 2016 Gaspard Thirion
** Last update Thu Apr 21 17:39:05 2016 Gaspard Thirion
*/

#include "engine.h"

int		text(t_main *_m, t_ini *proj)
{
  int		i;
  char		*tmp;

  while ((tmp = get_field(proj, "text", "size", 0)) == NULL
	 || (_m->nb_text = my_getnbr(tmp)) <= 0)
    bunny_ini_set_field(proj, "text", "size", 0, "1");
  if ((_m->text = malloc(sizeof(t_text) * (_m->nb_text + 1))) == NULL
      || (_m->text[0].img = bunny_new_pixelarray(10, 10)) == NULL)
    return (-1);
  _m->text[0].id = NULL;
  i = 0;
  while (++i <= _m->nb_text)
    {
      while((_m->text[i].id = get_field(proj, "text", "id", i - 1)) == NULL)
	bunny_ini_set_field(proj, "text", "id", i - 1, nts(i));
      if ((tmp = get_field(proj, "text", "path", i - 1)) == NULL
	  || (_m->text[i].img = bunny_load_pixelarray(tmp)) == NULL)
	{
	  if ((_m->text[i].img = bunny_new_pixelarray(50, 50)) == NULL)
	    return (-1);
	  fill(_m->text[i].img, GREEN);
	}
    }
  return (0);
}

int		keys(t_main *_m, t_ini *proj)
{
  char		*tmp;

  while ((tmp = get_field(proj, "keys", "esc", 0)) == NULL
	 || (_m->keys[0] = my_getnbr(tmp)) < 0)
    bunny_ini_set_field(proj, "keys", "esc", 0, "36");
    while ((tmp = get_field(proj, "keys", "left", 0)) == NULL
	 || (_m->keys[1] = my_getnbr(tmp)) < 0)
    bunny_ini_set_field(proj, "keys", "left", 0, "1");
  while ((tmp = get_field(proj, "keys", "right", 0)) == NULL
	 || (_m->keys[2] = my_getnbr(tmp)) < 0)
    bunny_ini_set_field(proj, "keys", "right", 0, "2");
  return (0);
}

int		base(t_main *_m, t_ini *proj)
{
  char		*tmp;
  char		*name;
  t_2D		size;
  t_2D		other;

  while ((name = get_field(proj, "base", "name", 0)) == NULL)
    bunny_ini_set_field(proj, "base", "name", 0, "deflap");
  while ((tmp = get_field(proj, "base", "dim", 0)) == NULL
	 || (size.x = my_getnbr(tmp)) < 1280)
    bunny_ini_set_field(proj, "base", "dim", 0, "1280");
  while ((tmp = get_field(proj, "base", "dim", 1)) == NULL
	 || (size.y = my_getnbr(tmp)) < 720)
    bunny_ini_set_field(proj, "base", "dim", 1, "720");
  while ((tmp = get_field(proj, "base", "max_ram", 0)) == NULL
	 || (other.y = my_getnbr(tmp)) < 50)
    bunny_ini_set_field(proj, "base", "max_ram", 0, "50");
  while ((tmp = get_field(proj, "base", "full", 0)) == NULL
	 || ((other.x = my_getnbr(tmp)) != 1 && other.x != 0))
    bunny_ini_set_field(proj, "base", "full", 0, "0");
  if ((_m->mwin = bunny_start(size.x, size.y, other.x, name)) == NULL
      || (_m->mimg = bunny_new_pixelarray(size.x, size.y)) == NULL
      /* || set_ram(other.y) == -1 */)
    return (-1);
  return (0);
}

int		loadproj(t_main *_m, char *path)
{
  t_ini		*proj;

  if ((proj = bunny_load_ini(path)) == NULL
      && (proj = bunny_new_ini()) == NULL)
    return (-1);
  if (base(_m, proj) == -1
      || keys(_m, proj) == -1
      || text(_m, proj) == -1
      || anim(_m, proj) == -1
      || font(_m, proj) == -1)
    return (-1);
  bunny_save_ini(proj, path);
  return (0);
}
