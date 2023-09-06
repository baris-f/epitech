/*
** boxs.c for boxs in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 23:05:53 2016 Florent Baris
** Last update Sun Feb 28 23:06:44 2016 Florent Baris
*/

#include "tool.h"

void    textbox(t_objs *but, t_theme *theme)
{
  int   size;
  t_2D  tpos;

  tpos = but->pos;
  size = but->font_size;
  if (size == -1)
    while ((but->size.x / (6 * (++size + 1) * higherword(but->text))) >= 1 &&
	   (but->size.y / (8 * (size + 1) * (nb_c_in_str(but->text, '\n') + 1)
			   )) >= 1);
  window(but, theme);
  tpos.x += but->size.x / 2 - ((size * 6 * higherword(but->text)) / 2);
  tpos.y += but->size.y / 2 - ((size * 8 * (nb_c_in_str(but->text, '\n')
					    + 1)) / 2);
  if (size > 0)
    tektext(but->text, &tpos, size, theme);
  else
    tektext("STRING TOO LARGE\nPLEASE SET FONT SIZE", &tpos, 1, theme);
}

void    tick(t_objs *but, t_theme *theme)
{
  if (but->border == TRUE)
    border(&but->pos, &but->size, but->border_size, theme);
  if (but->tick == FALSE)
    rectangle(theme->win_img, &but->pos, &but->size, theme->obj_col);
  else
    rectangle(theme->win_img, &but->pos, &but->size, theme->frame_col);
}

void    imgbox(t_objs *but, t_theme *theme)
{
  if (but->border == TRUE)
    border(&but->pos, &but->size, but->border_size, theme);
  if (but->img != NULL)
    tekblit(theme->win_img, but->img, &but->pos, &but->size);
}
