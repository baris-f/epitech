/*
** get.c for get in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Fri Feb 26 09:43:08 2016 Florent Baris
** Last update Fri Feb 26 15:33:57 2016 Florent Baris
*/

#include "tool.h"

unsigned int	get_int(t_scope *scope, char *field)
{
  unsigned int	nb;
  char		*tmp;

  if ((tmp = (char*)bunny_ini_scope_get_field(scope, field, 0)) == NULL
      || (nb = my_getnbr(tmp)) <= 0)
    return (-1);
  my_printf("%s -> %d\n", field, nb);
  return (nb);
}

t_bool		get_bool(t_scope *scope, char *field)
{
  char		*tmp;
  t_bool	ret;

  if ((tmp = (char*)bunny_ini_scope_get_field(scope, field, 0)) == NULL)
    return (-1);
  if (tmp[0] == '1')
    ret = TRUE;
  else
    ret = FALSE;
  my_printf("%s -> %d\n", field, ret);
  return (ret);
}

t_2D		get_2D(t_scope *scope, char *field)
{
  t_2D		nb;
  char		*tmpx;
  char		*tmpy;

  if ((tmpx = (char*)bunny_ini_scope_get_field(scope, field, 0)) == NULL
      || (tmpy = (char*)bunny_ini_scope_get_field(scope, field, 1)) == NULL
      || (nb.x = my_getnbr(tmpx)) <= 0
      || (nb.y = my_getnbr(tmpy)) <= 0)
    {
      nb.x = -1;
      nb.y = -1;
    }
  my_printf("%s -> %d %d\n", field, nb.x, nb.y);
  return (nb);
}

char		*get_char(t_scope *scope, char *field)
{
  char		*tmp;

  if ((tmp = (char*)bunny_ini_scope_get_field(scope, field, 0)) == NULL)
    return (NULL);
  return (tmp);
}

void		*get_fct(t_scope *scope, char *field)
{
  /* char		*tmp; */

  /* if ((tmp == (char*)bunny_ini_scope_get_field(scope, field, 0)) == NULL) */
  /*   return (NULL); */
  /*char* to fct*/
  (void)scope;
  my_printf("%s -> %s\n", field, "test");
  return (NULL);
}
