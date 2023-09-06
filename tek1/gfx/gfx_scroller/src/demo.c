/*
** demo.c for demo  in /home/baris-f/rendu/gfx/gfx_tekgui
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sun Feb 28 18:46:36 2016 Florent Baris
** Last update Sun Feb 28 18:46:44 2016 Florent Baris
*/

t_resp          update(void *_v)
{
  t_base        *base;

  base = (t_base*)_v;
  tekgui_display(base->img, base->tg);
  if (base->opt.blit)
    bunny_blit(&(base->win->buffer), &(base->img->clipable), &(base->mpos));
  bunny_display(base->win);
  return (GO_ON);
}

int             main(int ac, char **av)
{
  t_base        base;

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
  bunny_set_click_response(&click);
  bunny_set_move_response(&mouse_move);
  bunny_set_loop_main_function(&update);
  bunny_loop(base.win, 60, &(base));
  mfree(&base);
  return (0);
}
