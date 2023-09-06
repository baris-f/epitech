/*
1;2802;0c** display.c for display in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 17:33:51 2016 Florent Baris
** Last update Sun Feb 28 23:31:51 2016 Florent Baris
*/

#include "tool.h"

void	tekgui_display(t_bunny_pixelarray *pix, t_tekgui *gui)
{
  int	i;

  if (gui == NULL || (gui->theme->win_img = pix) == NULL)
    {
      printf("error\n");
      return ;
    }
  tekfill(pix, gui->theme[0].win_col);
  i = -1;
  while (++i < gui->nb.y)
    {
      if (gui->objs[i].visible == TRUE)
	{
	  if (gui->objs[i].type == 'k')
	    tick(&gui->objs[i], gui->theme);
	  else if (gui->objs[i].type == 'x')
	    textbox(&gui->objs[i], gui->theme);
	  else if (gui->objs[i].type == 'b')
	    button(&gui->objs[i], gui->theme);
	  else
	    imgbox(&gui->objs[i], gui->theme);
	}
    }
}
