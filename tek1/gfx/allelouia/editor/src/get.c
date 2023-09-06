/*
** get.c for s in /home/fus/rendu/gfx/gfx_tekadventure/gas/src
**
** Made by Gaspard Thirion
** Login   <thirio_b@epitech.net>
**
** Started on  Tue Mar 29 10:10:40 2016 Gaspard Thirion
** Last update Thu Apr 21 17:39:43 2016 Gaspard Thirion
*/

#include "engine.h"

t_col		get_col(t_scope *scope, char *field, t_ini *ini, int k)
{
  t_col		nb;
  char          *tmp;
  int           i;

  if ((tmp = (char*)bunny_ini_get_field(ini, scope, field, k))
      == NULL)
    return (0x12345678);
  nb = 0;
  i = 1;
  if (tmp[0] != '0' || (tmp[1] != 'x' && tmp[1] != 'X')
      || my_strlen(tmp) != 10)
    return (0x12345678);
  while (++i < 10)
    {
      if (tmp[i] >= '0' && tmp[i] <= '9')
	nb += (t_col)powere(16, (10 - i - 1)) * (tmp[i] - 48);
      else if (tmp[i] >= 'a' && tmp[i] <= 'f')
	nb += (t_col)powere(16, (10 - i - 1)) * (tmp[i] - 87);
      else if (tmp[i] >= 'A' && tmp[i] <= 'F')
	nb += (t_col)powere(16, (10 - i - 1)) * (tmp[i] - 55);
      else
	return (0x12345678);
    }
  return (nb);
}

t_img		*find_text(t_main *_m, char *id)
{
  int           i;

  i = 0;
  if (!id[0])
    return (_m->text[0].img);
  while (++i <= _m->nb_text)
    if (nmatch(_m->text[i].id, id) > 0)
      return (_m->text[i].img);
  return (_m->text[0].img);
}

int		find_i_text(t_main *_m, char *id)
{
  int           i;

  i = 0;
  if (!id[0])
    return (0);
  while (++i <= _m->nb_text)
    if (nmatch(_m->text[i].id, id) > 0)
      return (i);
  return (0);
}

t_sprite	*new_sprite(t_main *_m, char *id)
{
  t_sprite	*sprite;

  if ((sprite = malloc(sizeof(t_sprite))) == NULL)
    return (NULL);

  sprite->pos.x = 0;
  sprite->pos.y = 0;
  sprite->img = find_text(_m, id);
  sprite->sens = 1;
  sprite->start.x = 0;
  sprite->start.y = 0;
  sprite->dim.x = sprite->img->clipable.buffer.width;
  sprite->dim.y = sprite->img->clipable.buffer.height;
  sprite->scale.x = 1;
  sprite->scale.y = 1;
  sprite->anim = NULL;
  return (sprite);
}
