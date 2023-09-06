/*
** get2.c for get2 in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Feb 26 09:43:26 2016 Florent Baris
** Last update Sun Feb 28 23:05:09 2016 Florent Baris
*/

#include "tool.h"

int	powere(int nb, int power)
{
  if (power == 0)
    return (1);
  else if (power == 1)
    return (nb);
  else if (power > 1)
    {
      nb *= powere(nb, power - 1);
      return (nb);
    }
  else
    return (-1);
}

unsigned int    get_hex(t_scope *scope, char *field)
{
  unsigned int  nb;
  char          *tmp;
  int		i;

  if ((tmp = (char*)bunny_ini_scope_get_field(scope, field, 0)) == NULL)
    return (0x12345678);
  nb = 0;
  i = 1;
  if (tmp[0] != '0' || (tmp[1] != 'x' && tmp[1] != 'X') || my_strlen(tmp) != 10)
    return (0x12345678);
  while (++i < 10)
    {
      if (tmp[i] >= '0' && tmp[i] <= '9')
	nb += (unsigned int)powere(16, (10 - i - 1)) * (tmp[i] - 48);
      else if (tmp[i] >= 'a' && tmp[i] <= 'f')
	nb += (unsigned int)powere(16, (10 - i - 1)) * (tmp[i] - 87);
      else if (tmp[i] >= 'A' && tmp[i] <= 'F')
	nb += (unsigned int)powere(16, (10 - i - 1)) * (tmp[i] - 55);
      else
	return (0x12345678);
    }
  my_printf("%s -> %x\n", field, nb);
  return (nb);
}

t_img		*get_img(t_scope *scope, char *field)
{
  t_img		*img;
  char          *tmp;

  if ((tmp = (char*)bunny_ini_scope_get_field(scope, field, 0)) == NULL)
    return (0);
  if ((img = bunny_load_pixelarray(tmp)) == NULL)
    return (0);
  my_printf("%s -> %s\n", field, tmp);
  return (img);
}

void		*get_func(t_scope *scope, char *field)
{
  void	*func;
  char	*tmp;

  if ((tmp = (char*)bunny_ini_scope_get_field(scope, field, 0)) == NULL)
    return (0);
  if ((func = tekfunction(tmp)) == NULL)
    return (0);
  return (func);
}
void		getcommu(t_scope *scope, t_objs *obj)
{
  obj->visible = TRUE;
  obj->depth = 0;
  obj->text = get_char(scope, "text");
  obj->tick = FALSE;
  obj->pos = get_2D(scope, "position");
  if (obj->pos.x < 0)
    obj->pos.x = 10;
  if (obj->pos.y < 0)
    obj->pos.y = 18;
  obj->size = get_2D(scope, "size");
  if (obj->size.x < 20)
    obj->size.x = 100;
  if (obj->size.y < 100)
    obj->size.y = 20;
  obj->font_size = get_int(scope, "font_size");
  if (obj->font_size <= 0)
    obj->font_size = -1;
  obj->border_size = get_int(scope, "border_size");
  if (obj->border_size <= 0)
    obj->border_size = 1;
  obj->img = get_img(scope, "img");
  obj->func = get_func(scope, "function");
}
