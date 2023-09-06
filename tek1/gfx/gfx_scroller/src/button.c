/*
** button.c for button in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Tue Feb 16 20:01:43 2016 Florent Baris
** Last update Sun Feb 28 23:25:26 2016 Florent Baris
*/

#include "tool.h"

int	nb_c_in_str(char *str, char c)
{
  int	i;
  int	nb;

  i = -1;
  nb = 0;
  while (str[++i])
    if (str[i] == c)
      nb++;
  return (nb);
}

int	higherword(char *str)
{
  int	i;
  int	len;
  int	lenmax;

  lenmax = -1;
  i = -1;
  len = 0;
  while (str[++i])
    {
      if (str[i] != '\n')
	len++;
      else
	len = 0;
      if (len > lenmax)
	lenmax = len;
    }
  return (lenmax);
}

void	button(t_objs *but, t_theme *theme)
{
  int	size;
  t_2D	tpos;

  tpos = but->pos;
  size = but->font_size;
  if (size == -1)
    while ((but->size.x / (6 * (++size + 1) * higherword(but->text))) >= 1 &&
	   (but->size.y / (8 * (size + 1) * (nb_c_in_str(but->text, '\n') + 1)
			   )) >= 1);
  if (but->border == TRUE)
    border(&but->pos, &but->size, but->border_size, theme);
  if (but->tick == FALSE)
    rectangle(theme->win_img, &but->pos, &but->size, theme->obj_col);
  else
    rectangle(theme->win_img, &but->pos, &but->size, theme->frame_col);
  tpos.x += but->size.x / 2 - ((size * 6 * higherword(but->text)) / 2);
  tpos.y += but->size.y / 2 - ((size * 8 * (nb_c_in_str(but->text, '\n')
						+ 1)) / 2);
  if (size > 0)
    tektext(but->text, &tpos, size, theme);
  else
    tektext("STRING TOO LARGE\nPLEASE SET FONT SIZE", &tpos, 1, theme);
}
