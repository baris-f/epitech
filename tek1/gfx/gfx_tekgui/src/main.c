/*
** main.c for main in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 18:22:58 2016 Florent Baris
** Last update Thu Mar  3 15:04:51 2016 Florent Baris
*/

#include "tool.h"

void	OUI()
{
  printf("OUIIIIII\nIIIIIIIIIIIIIIIIIIIIIIII\n");
}
void		mfree(t_base *base)
{
  if (base->win)
    bunny_stop(base->win);
  if (base->img)
    bunny_delete_clipable(&(base->img->clipable));
  my_printf("\33[2K\r");
}

void		opt(t_base *base, char **av, int ac)
{
  int		i;

  base->opt.debug = DEBUG;
  base->opt.clear = CLEAR;
  base->opt.ui = UI;
  base->opt.blit = BLIT;
  i = 0;
  while (++i < ac)
    if (av[i][0] == '-')
      {
	if (av[i][1] == 'd')
	  base->opt.debug = TRUE;
	if (av[i][1] == 'c')
	  base->opt.clear = TRUE;
	if (av[i][1] == 'u')
	  base->opt.ui = TRUE;
      }
  bunny_set_key_response(&keys);
}

t_resp		update(void *_v)
{
  t_base	*base;

  base = (t_base*)_v;
  tekgui_display(base->img, base->tg);
  if (base->opt.blit)
    bunny_blit(&(base->win->buffer), &(base->img->clipable), &(base->mpos));
  bunny_display(base->win);
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_base	base;

  base.tg = tekgui_load("demo/new.ini");
  base.tg->theme->font_img = bunny_load_pixelarray("font.png");
  base.win = bunny_start(base.tg->dim.x, base.tg->dim.y, base.tg->full
			 , "LibLapin");
  opt(&base, av, ac);
  if ((base.img = bunny_new_pixelarray(WIN_W, WIN_H)) == NULL)
    my_printf("base.img FAILED\n");
  if (base.tg == NULL)
    printf("bug\n");
  base.mpos.x = 0;
  base.mpos.y = 0;
  base.mous.x = 0;
  base.mous.y = 0;
  my_memset(base.tg->text, '\0', 140);
  bunny_set_loop_main_function(&update);
  bunny_loop(base.win, 60, &(base));
  mfree(&base);
  return (0);
}
