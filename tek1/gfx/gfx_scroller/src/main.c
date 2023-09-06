/*
** main.c for main in /home/baris-f/rendu/gfx_wolf3d
**
** Made by Florent Baris
** Login   <baris_f@epitech.net>
**
** Started on  Sat Dec 26 17:27:16 2015 Florent Baris
** Last update Sun Mar 20 22:26:04 2016 Florent Baris
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include "tool.h"

t_bunny_response        tekkey(t_bunny_event_state state, t_bunny_keysym key,
			       void *_void)
{
  t_base        *base;

  base = (t_base*)_void;
  (void)base;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (key == BKS_RIGHT)
    (void)state;
  return (GO_ON);
}

t_bunny_response	update(void *_void)
{
  t_base		*base;

  base = (t_base*)_void;
  mreader(base);
  tekfill(base->img, BLUE);
  base->fpos.x -= 5;
  if (!base->bol)
    base->fpos.y--;
  else
    base->fpos.y++;
  if (base->fpos.y <= 200 || base->fpos.y >= WIN_H - 400)
    base->bol = !base->bol;
  base->mopos.x--;
  base->hpos.x -= 2;
  base->fipos.x -= 2;
  base->nupos.x -= 3;
  (base->afire > 8) ? (base->afire = 0) : (base->afire++);
  if (base->fpos.x <  0 - my_strlen(base->msg) * 32 * 2)
    base->fpos.x = WIN_W;
  draw(base, base->mont, &base->mopos);
  draw(base, base->herb, &base->hpos);
  draw(base, base->nu, &base->nupos);
  anim(base, base->fire, &base->fipos, 5);
  tektext(base, base->msg, &base->fpos, 2);
  bunny_blit(&(base->win->buffer), &(base->img->clipable), &base->mpos);
  bunny_display(base->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_base		base[1];
  int			x;
  int			y;

  x = WIN_W;
  y = WIN_H;
  (void)ac;
  (void)av;

  mparser(base, "res/modlike/maniax.bsf");

  if ((base->win = bunny_start(x, y, 0, "lap")) == NULL)
    return (0);
  if ((base->img = bunny_new_pixelarray(x, y)) == NULL)
    return (0);
  base->msg = my_strdup("penser a mettre un lorem ipsum made by baris thirio and lol grandma\n");
  base->mpos.x = 0;
  base->mpos.y = 0;
  base->fpos.x = WIN_W;
  base->fpos.y = WIN_HH;
  base->bol = 0;
  base->afire = 0;
  if ((base->font = bunny_load_pixelarray("res/font6.gif")) == NULL)
    return (write(1, "font miss\n", 10) * -1);
  if ((base->mont = bunny_load_pixelarray("res/montagnes.png")) == NULL)
    return (write(1, "montagnes miss\n", 10) * -1);
  if ((base->herb = bunny_load_pixelarray("res/herbe3.png")) == NULL)
    return (write(1, "herb miss\n", 10) * -1);
  base->mopos.x = 0;
  base->mopos.y = WIN_H - base->mont->clipable.clip_height
    - base->herb->clipable.clip_height;
  if ((base->nu = bunny_load_pixelarray("res/nuages3.png")) == NULL)
    return (write(1, "nuage miss\n", 10) * -1);
  base->nupos.x = 0;
  base->nupos.y = base->nu->clipable.clip_height;
  base->hpos.x = 0;
  base->hpos.y = WIN_H - base->herb->clipable.clip_height;
  if ((base->fire = bunny_load_pixelarray("res/fire.png")) == NULL)
    return (write(1, "fire miss\n", 10) * -1);
  base->fipos.x = WIN_W;
  base->fipos.y = WIN_H - base->fire->clipable.clip_height * 2;
  bunny_set_loop_main_function(update);
  bunny_set_key_response(tekkey);
  bunny_loop(base->win, 150, base);
  bunny_delete_clipable(&base->img->clipable);
  bunny_stop(base->win);
  return (0);
}
