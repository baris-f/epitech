/*
** parser.c for parser in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Thu Feb 25 22:15:57 2016 Florent Baris
** Last update Sun Feb 28 22:39:16 2016 Florent Baris
*/

#include "tool.h"

void	gettheme2(t_ini *ini, t_theme *theme, t_scope *scope, int i)
{
  my_printf("\t%s\n", bunny_ini_scope_name(ini, scope));
  theme[i].win_col = get_hex(scope, "win_color");
  if (theme[i].win_col == 0x12345678)
    {
      theme[i].win_col = WHITE;
      my_printf("win_col failed, is now WHITE by default\n");
    }
  theme[i].font_col = get_hex(scope, "font_color");
  if (theme[i].font_col == 0x12345678)
    {
      theme[i].font_col = BLACK;
      my_printf("font_col failed, is now BLACK by default\n");
    }
  theme[i].obj_col = get_hex(scope, "obj_color");
  if (theme[i].obj_col == 0x12345678)
    {
      theme[i].obj_col = WHITE;
      my_printf("obj_col failed, is now WHITE by default\n");
    }
  theme[i].frame_col = get_hex(scope, "frame_color");
  if (theme[i].frame_col == 0x12345678)
    {
      theme[i].frame_col = BLACK;
      my_printf("frame_col failed, is now BLACK by default\n");
    }
}

t_theme         *gettheme(t_ini *ini, int nb, t_scope *fscope)
{
  t_theme	*theme;
  t_scope	*scope;
  int		i;

  i = -1;
  if ((theme = malloc(sizeof(t_theme) * nb)) == NULL
      || (scope = bunny_ini_next(ini, fscope)) == NULL)
    return (NULL);
  while ((scope = bunny_ini_next(ini, scope)))
    if (bunny_ini_scope_name(ini, scope)[0] == 't')
      gettheme2(ini, theme, scope, ++i);
  return (theme);
}

t_objs		*getobjs(t_ini *ini, int nb, t_scope *fscope, t_theme *themes)
{
  t_objs	*objs;
  t_scope	*scope;
  char		c;
  int		i;

  i = -1;
  if ((objs = malloc(sizeof(t_objs) * nb)) == NULL
      || (scope = bunny_ini_next(ini, fscope)) == NULL)
    return (NULL);
  while ((scope = bunny_ini_next(ini, scope)))
    if ((c = bunny_ini_scope_name(ini, scope)[0]) != 't')
      {
	my_printf("\t%s\n", bunny_ini_scope_name(ini, scope));
	getcommu(scope, &(objs[++i]));
	objs[i].type = c;
	objs[i].theme = &(themes[get_int(scope, "theme")]);
	objs[i].visible = TRUE;
	objs[i].tick = FALSE;
	objs[i].border = get_bool(scope, "border");
      }
  return (objs);
}

t_2D		getnb(t_ini *ini, t_scope *fscope)
{
  t_scope	*scope;
  t_2D		ret;
  char		c;

  ret.x = 0;
  ret.y = 0;
  if ((scope = bunny_ini_next(ini, fscope)) == NULL)
    return (ret);
  while ((scope = bunny_ini_next(ini, scope)))
    if ((c = bunny_ini_scope_name(ini, scope)[0]) == 't')
      ++ret.x;
    else if (c == 'x' || c == 'i' || c == 'k' || c == 'b')
      ++ret.y;
  return (ret);
}

t_tekgui	*tekgui_load(const char *file)
{
  t_tekgui	*tg;
  t_ini		*ini;
  t_scope	*scope;
  t_2D		nb;

  if ((tg = malloc(sizeof(t_tekgui))) == NULL
      || (ini = bunny_load_ini(file)) == NULL
      || (scope = bunny_ini_first(ini)) == NULL)
    return (NULL);
  nb = getnb(ini, scope);
  tg->theme = gettheme(ini, nb.x, scope);
  tg->objs = getobjs(ini, nb.y, scope, tg->theme);
  tg->nb = nb;
  if ((scope = bunny_ini_next(ini, scope)) == NULL)
    return (NULL);
  my_printf("\t%s\n", bunny_ini_scope_name(ini, scope));
  tg->dim = get_2D(scope, "window_size");
  tg->full = get_bool(scope, "fullscreen");
  bunny_set_click_response(&click);
  bunny_set_move_response(&mouse_move);
  return (tg);
}
